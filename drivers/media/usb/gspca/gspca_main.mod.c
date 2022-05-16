#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xcdc6a9e0, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x27f623cc, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x2978ede7, __VMLINUX_SYMBOL_STR(v4l2_event_unsubscribe) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0xe12f33cc, __VMLINUX_SYMBOL_STR(video_device_release_empty) },
	{ 0x9cdd6eca, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x94c813b9, __VMLINUX_SYMBOL_STR(v4l2_device_unregister) },
	{ 0x494e4ab7, __VMLINUX_SYMBOL_STR(v4l2_ctrl_handler_free) },
	{ 0x3fbfbf0, __VMLINUX_SYMBOL_STR(v4l2_ctrl_g_ctrl) },
	{ 0xa472e9a8, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0x776068a1, __VMLINUX_SYMBOL_STR(__video_register_device) },
	{ 0xbd58f31d, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0xe79b21d3, __VMLINUX_SYMBOL_STR(v4l2_device_register) },
	{ 0xab40cca9, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xf9c0b663, __VMLINUX_SYMBOL_STR(strlcat) },
	{ 0x2e1336d3, __VMLINUX_SYMBOL_STR(v4l2_device_disconnect) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x509b5f6d, __VMLINUX_SYMBOL_STR(mutex_lock_interruptible) },
	{ 0x5983685b, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x23faecf0, __VMLINUX_SYMBOL_STR(video_unregister_device) },
	{ 0x2b77e48e, __VMLINUX_SYMBOL_STR(usb_set_interface) },
	{ 0x3a154bb9, __VMLINUX_SYMBOL_STR(v4l2_ctrl_subscribe_event) },
	{ 0x5792f848, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xd8a2dfe5, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x422138db, __VMLINUX_SYMBOL_STR(v4l2_fh_release) },
	{ 0xcf1be827, __VMLINUX_SYMBOL_STR(usb_free_coherent) },
	{ 0x51042cc1, __VMLINUX_SYMBOL_STR(vm_insert_page) },
	{ 0x20819ba0, __VMLINUX_SYMBOL_STR(__v4l2_ctrl_s_ctrl) },
	{ 0x30d590e2, __VMLINUX_SYMBOL_STR(module_put) },
	{ 0x776d6d87, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0xb35dea8f, __VMLINUX_SYMBOL_STR(__arch_copy_to_user) },
	{ 0xd987fd91, __VMLINUX_SYMBOL_STR(video_devdata) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x8ad4cc90, __VMLINUX_SYMBOL_STR(input_register_device) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0x1ab918eb, __VMLINUX_SYMBOL_STR(v4l2_ctrl_handler_setup) },
	{ 0x933ac4b4, __VMLINUX_SYMBOL_STR(usb_clear_halt) },
	{ 0x274631cb, __VMLINUX_SYMBOL_STR(input_free_device) },
	{ 0xa0b04675, __VMLINUX_SYMBOL_STR(vmalloc_32) },
	{ 0x4addaadd, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xc0b5c835, __VMLINUX_SYMBOL_STR(v4l2_fh_open) },
	{ 0x65345022, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xcb128141, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x9e776f29, __VMLINUX_SYMBOL_STR(input_unregister_device) },
	{ 0xae8c4d0c, __VMLINUX_SYMBOL_STR(set_bit) },
	{ 0x9c5bc552, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0x3158756a, __VMLINUX_SYMBOL_STR(usb_ifnum_to_if) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x87170b6e, __VMLINUX_SYMBOL_STR(vmalloc_to_page) },
	{ 0xc93c9b70, __VMLINUX_SYMBOL_STR(usb_alloc_coherent) },
	{ 0x89b6285d, __VMLINUX_SYMBOL_STR(v4l2_device_put) },
	{ 0xf4a191b7, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x1c483a9, __VMLINUX_SYMBOL_STR(v4l2_get_timestamp) },
	{ 0x749c7410, __VMLINUX_SYMBOL_STR(video_ioctl2) },
	{ 0x4da575a0, __VMLINUX_SYMBOL_STR(v4l2_ctrl_poll) },
	{ 0x88db9f48, __VMLINUX_SYMBOL_STR(__check_object_size) },
	{ 0x9b5356df, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0xe34c88da, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0x504f3220, __VMLINUX_SYMBOL_STR(input_allocate_device) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "F5C20D78E083AA5A11E6F23");
