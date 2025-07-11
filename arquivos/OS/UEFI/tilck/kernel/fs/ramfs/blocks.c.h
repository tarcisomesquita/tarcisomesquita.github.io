/* SPDX-License-Identifier: BSD-2-Clause */

static struct ramfs_block *ramfs_new_block(offt page)
{
   void *vaddr;
   struct ramfs_block *block;

   if (!(vaddr = kzmalloc(PAGE_SIZE)))
      return NULL;

   if (!(block = kmalloc(sizeof(struct ramfs_block)))) {
      kfree2(vaddr, PAGE_SIZE);
      return NULL;
   }

   bintree_node_init(&block->node);
   block->offset = page;
   block->vaddr = vaddr;
   return block;
}

static void
ramfs_append_new_block(struct ramfs_inode *inode, struct ramfs_block *block)
{
   DEBUG_ONLY_UNSAFE(bool success =)
      bintree_insert_ptr(&inode->blocks_tree_root,
                         block,
                         struct ramfs_block,
                         node,
                         offset);

   ASSERT(success);
   inode->blocks_count++;
}

static int ramfs_inode_extend(struct ramfs_inode *i, offt new_len)
{
   ASSERT(rwlock_wp_holding_exlock(&i->rwlock));
   ASSERT(new_len > i->fsize);

   i->fsize = new_len;
   return 0;
}
