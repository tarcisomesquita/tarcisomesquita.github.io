#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x5e1048c0, "filp_open" },
	{ 0x907a0346, "crypto_alloc_ahash" },
	{ 0xe914e41e, "strcpy" },
	{ 0xed70793d, "crypto_stats_get" },
	{ 0xf22305d, "vmalloc_to_page" },
	{ 0x48d88a2c, "__SCT__preempt_schedule" },
	{ 0xc890c008, "zlib_deflateEnd" },
	{ 0x8445bb7b, "kernel_bind" },
	{ 0x71fd4c6b, "param_ops_long" },
	{ 0x37a0cba, "kfree" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x522eef8, "kernel_accept" },
	{ 0xf2c43f3f, "zlib_deflate" },
	{ 0x9319e060, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92a94f2f, "crypto_destroy_tfm" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe9f7149c, "zlib_deflate_workspacesize" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x33b84f74, "copy_page" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xfbe26e7f, "init_net" },
	{ 0x5a0b73d0, "zlib_deflateInit2" },
	{ 0x4e7d68d2, "kernel_sock_shutdown" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0x531b604e, "__virt_addr_valid" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xbbed5eb9, "current_task" },
	{ 0xc08d0abe, "sock_set_reuseaddr" },
	{ 0x883ec885, "param_ops_charp" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x53258edb, "crypto_ahash_final" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x1de343ce, "kernel_listen" },
	{ 0x7a9a7084, "sock_create_kern" },
	{ 0xb87901af, "filp_close" },
	{ 0x57dd0846, "sock_release" },
	{ 0x4d2f58d6, "crypto_stats_ahash_update" },
	{ 0x754d539c, "strlen" },
	{ 0x77358855, "iomem_resource" },
	{ 0x2d2a26af, "param_ops_int" },
	{ 0xf74d26c9, "kernel_sendmsg" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xb07b3251, "kmalloc_caches" },
	{ 0x5c0ab056, "kernel_write" },
	{ 0x8e099eb2, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E844769B821676A19BDD5A3");
