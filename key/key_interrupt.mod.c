#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xd0a8ddc4, "module_layout" },
	{ 0xf6288e02, "__init_waitqueue_head" },
	{ 0x40a6f522, "__arm_ioremap" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x8893fa5d, "finish_wait" },
	{ 0x75a17bed, "prepare_to_wait" },
	{ 0x1000e51, "schedule" },
	{ 0x98082893, "__copy_to_user" },
	{ 0xfa2a45e, "__memzero" },
	{ 0xd6dbfaa9, "cdev_add" },
	{ 0x72df84f2, "cdev_init" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0xb9e52429, "__wake_up" },
	{ 0x2072ee9b, "request_threaded_irq" },
	{ 0x67e222cd, "cdev_del" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xf20dabd8, "free_irq" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x27e1a049, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "6C60AC82C943E8A90206F91");
