
#include <unistd.h>
#include <fcntl.h>
int main()
{
   int fd;
   char buf[512];
   
   fd = open("/dev/hda", O_RDONLY);
   if (fd >= 0)
      read(fd, buf, sizeof(buf));
   return 0;
}


/*

The open system call is found in fs/open.c:

    int sys_open(const char *filename, int flags, int mode) {
            char *tmp = getname(filename);
            int fd = get_unused_fd();
            struct file *f = filp_open(tmp, flags, mode);
            fd_install(fd, f);
            putname(tmp);
            return fd;
    }

The routine getname() is found in fs/namei.c. It copies the file name from user space to kernel space:

    #define __getname()     kmem_cache_alloc(names_cachep, SLAB_KERNEL)
    #define putname(name)   kmem_cache_free(names_cachep, (void *)(name))

    char *getname(const char *filename) {
            char *tmp = __getname();        // allocate some memory
            strncpy_from_user(tmp, filename, PATH_MAX + 1);
            return tmp;
    }

The routine get_unused_fd() is found in fs/open.c again. It returns the first unused filedescriptor:

    int get_unused_fd(void) {
            struct files_struct *files = current->files;
            int fd = find_next_zero_bit(files->open_fds,
                                        files->max_fdset, files->next_fd);
            FD_SET(fd, files->open_fds);    // in use now
            files->next_fd = fd + 1;
            return fd;
    }

Here current is the pointer to the user task struct for the currently executing task.

The routine fd_install() is found in include/linux/file.h. It just stores the information returned by filp_open()

    void fd_install(unsigned int fd, struct file *file) {
            struct files_struct *files = current->files;
            files->fd[fd] = file;
    }

So all the interesting work of sys_open() is done in filp_open(). This routine is found in fs/open.c:

    struct file *filp_open(const char *filename, int flags, int mode) {
            struct nameidata nd;
            open_namei(filename, flags, mode, &nd);
            return dentry_open(nd.dentry, nd.mnt, flags);
    }

The struct nameidata is defined in include/linux/fs.h. It is used during lookups.

    struct nameidata {
            struct dentry *dentry;
            struct vfsmount *mnt;
            struct qstr last;
    };

The routine open_namei() is found in fs/namei.c:

    open_namei(const char *pathname, int flag, int mode, struct nameidata *nd) {
            if (!(flag & O_CREAT)) {
                    // The simplest case - just a plain lookup.
                    if (*pathname == '/') {
                            nd->mnt = mntget(current->fs->rootmnt);
                            nd->dentry = dget(current->fs->root);
                    } else {
                            nd->mnt = mntget(current->fs->pwdmnt);
                            nd->dentry = dget(current->fs->pwd);
                    }
                    path_walk(pathname, nd);
                    // Check permissions etc.
                    ...
                    return 0;
            }
            ...
    }

An inode (index node) describes a file. A file can have several names (or no name at all), but it has a unique inode. A dentry (directory entry) describes a name of a file: the inode plus the pathname used to find it. A vfsmount describes the filesystem we are in.

So, essentially, the lookup part of open_namei() is found in path_walk():

    path_walk(const char *name, struct nameidata *nd) {
            struct dentry *dentry;
            for(;;) {
                    struct qstr this;
                    this.name = next_part_of(name);
                    this.len = length_of(this.name);
                    this.hash = hash_fn(this.name);
                    // if . or .. then special, otherwise: 
                    dentry = cached_lookup(nd->dentry, &this);
                    if (!dentry)
                            dentry = real_lookup(nd->dentry, &this);
                    nd->dentry = dentry;
                    if (this_was_the_final_part)
                            return;
            }
    }

Here the cached_lookup() tries to find the given dentry in a cache of recently used dentries. If it is not found, the real_lookup() goes to the filesystem, which probably goes to disk, and actually finds the thing. After path_walk() is done, the nd argument contains the required dentry, which in turn has the inode information on the file. Finally we do dentry_open() that initializes a file struct:

    struct file *
    dentry_open(struct dentry *dentry, struct vfsmount *mnt, int flags) {
            struct file *f = get_empty_filp();
            f->f_dentry = dentry;
            f->f_vfsmnt = mnt;
            f->f_pos = 0;
            f->f_op = dentry->d_inode->i_fop;
            ...
            return f;
    }

So far the open. In short: walk the tree, for each component hope the information is in cache, and if not ask the file system. How does this work? Each file system type provides structs super_operations, file_operations, inode_operations, address_space_operations that contain the addresses of the routines that can do stuff. And thus

    struct dentry *
    real_lookup(struct dentry *parent, struct qstr *name, int flags) {
            struct dentry *dentry = d_alloc(parent, name);
            parent->d_inode->i_op->lookup(dir, dentry);
            return dentry;
    }

calls on the lookup routine for the specific fiilesystem, as found in the struct inode_operations in the inode of the dentry for the directory in which we do the lookup.

And this file system specific routine must read the disk data and search the directory for the file we are looking for. Good examples of file systems are minix and romfs because they are simple and small. For example, in fs/romfs/inode.c:

    romfs_lookup(struct inode *dir, struct dentry *dentry) {
            const char *name = dentry->d_name.name;
            int len = dentry->d_name.len;
            char fsname[ROMFS_MAXFN];
            struct romfs_inode ri;
            unsigned long offset = dir->i_ino & ROMFH_MASK;
            for (;;) {
                    romfs_copyfrom(dir, &ri, offset, ROMFH_SIZE);
                    romfs_copyfrom(dir, fsname, offset+ROMFH_SIZE, len+1);
                    if (strncmp (name, fsname, len) == 0)
                            break;
                    // next entry
                    offset = ntohl(ri.next) & ROMFH_MASK;
            }
            inode = iget(dir->i_sb, offset);
            d_add (dentry, inode);
            return 0;
    }

    romfs_copyfrom(struct inode *i, void *dest,
                   unsigned long offset, unsigned long count) {
            struct buffer_head *bh;

            bh = bread(i->i_dev, offset>>ROMBSBITS, ROMBSIZE);
            memcpy(dest, ((char *)bh->b_data) + (offset & ROMBMASK), count);
            brelse(bh);
    }


*/




/*
Next Previous Contents
3. read

Given a file descriptor (that keeps the inode and the file position of the file) we want to read. In fs/read_write.c we find:

    ssize_t sys_read(unsigned int fd, char *buf, size_t count) {
            struct file *file = fget(fd);
            return file->f_op->read(file, buf, count, &file->f_pos);
    }

That is, the read system call asks the file system to do the reading, starting at the current file position. The f_op field was filled in the dentry_open() routine above with the i_fop field of an inode.

For romfs the struct file_operations is assigned in romfs_read_inode(). For a regular file (case 2) it assigns generic_ro_fops. For a block special file (case 4) it calls init_special_inode() (see devices.c) which assigns def_blk_fops.

How come romfs_read_inode() was ever called? When the filesystem was mounted, the routine romfs_read_super() was called, and it assigned romfs_ops to the s_op field of the superblock struct.

    struct super_operations romfs_ops = {
            read_inode:     romfs_read_inode,
            statfs:         romfs_statfs,
    };

And the iget() that was skipped over in the discussion above (in romfs_lookup()) finds the inode with given number ino in a cache, and if it cannot be found there creates a new inode struct by calling get_new_inode() (see fs/inode.c):

    struct inode *
    iget(struct super_block *sb, unsigned long ino) {
            struct list_head * head = inode_hashtable + hash(sb,ino);
            struct inode *inode = find_inode(sb, ino, head);
            if (inode) {
                    wait_on_inode(inode);
                    return inode;
            }
            return get_new_inode(sb, ino, head);
    }

    struct inode *
    get_new_inode(struct super_block *sb, unsigned long ino,
                  struct list_head *head) {
            struct inode *inode = alloc_inode();
            inode->i_sb = sb;
            inode->i_dev = sb->s_dev;
            inode->i_ino = ino;
            ...
            sb->s_op->read_inode(inode);
    }

So that is how the inode was filled, and we find that in our case (/dev/hda is a block special file) the routine that is called by sys_read is def_blk_fops.read, and inspection of block_dev.c shows that that is the routine block_read():

    ssize_t
    block_read(struct file *filp, char *buf, size_t count, loff_t *ppos) {
            struct inode *inode = filp->f_dentry->d_inode;
            kdev_t dev = inode->i_rdev;
            ssize_t blocksize = blksize_size[MAJOR(dev)][MINOR(dev)];
            loff_t offset = *ppos;
            ssize_t read = 0;
            size_t left, block, blocks;
            struct buffer_head *bhreq[NBUF];
            struct buffer_head *buflist[NBUF];
            struct buffer_head **bh;

            left = count;                   // bytes to read
            block = offset / blocksize;     // first block
            offset &= (blocksize-1);    // starting offset in block
            blocks = (left + offset + blocksize - 1) / blocksize;

            bh = buflist;
            do {
                    while (blocks) {
                            --blocks;
                            *bh = getblk(dev, block++, blocksize);
                            if (*bh && !buffer_uptodate(*bh))
                                    bhreq[bhrequest++] = *bh;
                    }
                    if (bhrequest)
                            ll_rw_block(READ, bhrequest, bhreq);
                    // wait for I/O to complete,
                    // copy result to user space,
                    // increment read and *ppos, decrement left
            } while (left > 0);
            return read;
    }

So the building blocks here are getblk(), ll_rw_block(), and wait_on_buffer().

The first of these lives in fs/buffer.c. It finds the buffer that already contains the required data if we are lucky, and otherwise a buffer that is going to be used.

    struct buffer_head *
    getblk(kdev_t dev, int block, int size) {
            struct buffer_head *bh;
            int isize;

    try_again:
            bh = __get_hash_table(dev, block, size);
            if (bh)
                    return bh;
            isize = BUFSIZE_INDEX(size);
            bh = free_list[isize].list;
            if (bh) {
                    __remove_from_free_list(bh);
                    init_buffer(bh);
                    bh->b_dev = dev;
                    bh->b_blocknr = block;
                    ...
                    return bh;
            }
            refill_freelist(size);
            goto try_again;
    }

The real I/O is started by ll_rw_block(). It lives in drivers/block/ll_rw_blk.c.

    ll_rw_block(int rw, int nr, struct buffer_head * bhs[]) {
            int i;

            for (i = 0; i < nr; i++) {
                    struct buffer_head *bh = bhs[i];

                    bh->b_end_io = end_buffer_io_sync;

                    submit_bh(rw, bh);
            }
    }

Here bh->b_end_io specifies what to do when I/O is finished. In this case:

    end_buffer_io_sync(struct buffer_head *bh, int uptodate) {
            mark_buffer_uptodate(bh, uptodate);
            unlock_buffer(bh);
    }

So, ll_rw_block() just feeds the requests it gets one by one to submit_bh():

    submit_bh(int rw, struct buffer_head *bh) {
            bh->b_rdev = bh->b_dev;
            bh->b_rsector = bh->b_blocknr * (bh->b_size >> 9);

            generic_make_request(rw, bh);
    }

So, submit_bh() just passes things along to generic_make_request(), the routine to send I/O requests to block devices:

    generic_make_request (int rw, struct buffer_head *bh) {
            request_queue_t *q;

            q = blk_get_queue(bh->b_rdev);
            q->make_request_fn(q, rw, bh);
    }

Thus, it finds the right queue and calls the request function for that queue.

    struct blk_dev_struct {
            request_queue_t         request_queue;
            queue_proc              *queue;
            void                    *data;
    } blk_dev[MAX_BLKDEV];

    request_queue_t *blk_get_queue(kdev_t dev)
    {
            return blk_dev[MAJOR(dev)].queue(dev);
    }

In our case (/dev/hda), the blk_dev struct was filled by hwif_init (from drivers/ide/ide-probe.c):

            blk_dev[hwif->major].data = hwif;
            blk_dev[hwif->major].queue = ide_get_queue;

and this ide_get_queue() is found in drivers/ide/ide.c:

    #define DEVICE_NR(dev)       (MINOR(dev) >> PARTN_BITS)

    request_queue_t *ide_get_queue (kdev_t dev) {
            ide_hwif_t *hwif = (ide_hwif_t *) blk_dev[MAJOR(dev)].data;
            return &hwif->drives[DEVICE_NR(dev) & 1].queue;
    }

This .queue field was filled by ide_init_queue():

    ide_init_queue(ide_drive_t *drive) {
            request_queue_t *q = &drive->queue;

            q->queuedata = HWGROUP(drive);
            blk_init_queue(q, do_ide_request);
    }

And blk_init_queue() (from ll_rw_blk.c again):

    blk_init_queue(request_queue_t *q, request_fn_proc *rfn) {
            ...
            q->request_fn           = rfn;
            q->make_request_fn      = __make_request;
            q->merge_requests_fn    = ll_merge_requests_fn;
            ...
    }

Aha, so we found the q->make_request_fn. Here it is:

    __make_request(request_queue_t *q, int rw, struct buffer_head *bh) {
            // try to merge request with adjacent ones
            ...
            // get a struct request and fill it with device, start, length, ... 
            ...
            add_request(q, req, insert_here);
            if (!q->plugged)
                    q->request_fn(q);
    }

    add_request(request_queue_t *q, struct request *req,
                struct list_head *insert_here) {
            list_add(&req->queue, insert_here);
    }

When the request has been queued, q->request_fn is called. What is that? We can see it above - it is do_ide_request() and lives in ide.c.

    do_ide_request(request_queue_t *q) {
            ide_do_request(q->queuedata, 0);
    }

    ide_do_request(ide_hwgroup_t *hwgroup, int masked_irq) {
            ide_startstop_t startstop;

            while (!hwgroup->busy) {
                    hwgroup->busy = 1;
                    drive = choose_drive(hwgroup);
                    startstop = start_request(drive);
                    if (startstop == ide_stopped)
                            hwgroup->busy = 0;
            }
    }

    ide_startstop_t
    start_request (ide_drive_t *drive) {
            unsigned long block, blockend;
            struct request *rq;

            rq = blkdev_entry_next_request(&drive->queue.queue_head);
            block = rq->sector;
            block += drive->part[minor & PARTN_MASK].start_sect;
            SELECT_DRIVE(hwif, drive);
            return (DRIVER(drive)->do_request(drive, rq, block));
    }

So, in the case of a partitioned disk it is only at this very low level that we add in the starting sector of the partition in order to get an absolute sector.

The first actual port access happened already:

    #define SELECT_DRIVE(hwif,drive) \
            OUT_BYTE((drive)->select.all, hwif->io_ports[IDE_SELECT_OFFSET]);

but this do_request function must do the rest. For a disk it is defined in ide-disk.c, in the ide_driver_t idedisk_driver, and the function turns out to be do_rw_disk().

    ide_startstop_t
    do_rw_disk (ide_drive_t *drive, struct request *rq, unsigned long block) {
            if (IDE_CONTROL_REG)
                    OUT_BYTE(drive->ctl,IDE_CONTROL_REG);
            OUT_BYTE(rq->nr_sectors,IDE_NSECTOR_REG);
            if (drive->select.b.lba) {
                    OUT_BYTE(block,IDE_SECTOR_REG);
                    OUT_BYTE(block>>=8,IDE_LCYL_REG);
                    OUT_BYTE(block>>=8,IDE_HCYL_REG);
                    OUT_BYTE(((block>>8)&0x0f)|drive->select.all,IDE_SELECT_REG);
            } else {
                    unsigned int sect,head,cyl,track;
                    track = block / drive->sect;
                    sect  = block % drive->sect + 1;
                    OUT_BYTE(sect,IDE_SECTOR_REG);
                    head  = track % drive->head;
                    cyl   = track / drive->head;
                    OUT_BYTE(cyl,IDE_LCYL_REG);
                    OUT_BYTE(cyl>>8,IDE_HCYL_REG);
                    OUT_BYTE(head|drive->select.all,IDE_SELECT_REG);
            }
            if (rq->cmd == READ) {
                    ide_set_handler(drive, &read_intr, WAIT_CMD, NULL);
                    OUT_BYTE(WIN_READ, IDE_COMMAND_REG);
                    return ide_started;
            }
            ...
    }

This fills the remaining control registers of the interface and starts the actual I/O. Now ide_set_handler() sets up read_intr() to be called when we get an interrupt. This calls ide_end_request() when a request is done, which calls end_that_request_first() (which calls bh->b_end_io() as promised earlier) and end_that_request_last() which calls blkdev_release_request() which wakes up whoever waited for the block.
Next Previous Contents 

*/
