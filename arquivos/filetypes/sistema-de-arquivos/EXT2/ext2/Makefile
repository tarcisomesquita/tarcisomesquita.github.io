
obj-m := ext2.o

ext2-objs := balloc.o dir.o file.o fsync.o ialloc.o inode.o ioctl.o namei.o super.o symlink.o xattr.o xattr_user.o xattr_trusted.o acl.o xattr_security.o

all:
	make -C /lib/modules/2.6.28-11-generic/build M=/home/ubuntu/Desktop/ext2 modules

clean:
	make -C /lib/modules/2.6.28-11-generic/build M=/home/ubuntu/Desktop/ext2 clean
	rm /home/ubuntu/Desktop/ext2/Module.markers /home/ubuntu/Desktop/ext2/modules.order


