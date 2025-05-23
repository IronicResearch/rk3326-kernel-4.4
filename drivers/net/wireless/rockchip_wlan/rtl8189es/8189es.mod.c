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
	{ 0x590ff505, __VMLINUX_SYMBOL_STR(register_netdevice) },
	{ 0x15d6920f, __VMLINUX_SYMBOL_STR(sdio_writeb) },
	{ 0x6f040db5, __VMLINUX_SYMBOL_STR(sdio_readb) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0x9a1dfd65, __VMLINUX_SYMBOL_STR(strpbrk) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xe4689576, __VMLINUX_SYMBOL_STR(ktime_get_with_offset) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0x1d92d898, __VMLINUX_SYMBOL_STR(complete_and_exit) },
	{ 0x6230db56, __VMLINUX_SYMBOL_STR(wiphy_free) },
	{ 0xa650d07f, __VMLINUX_SYMBOL_STR(cfg80211_unlink_bss) },
	{ 0xf33847d3, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x4fad5d73, __VMLINUX_SYMBOL_STR(rockchip_wifi_mac_addr) },
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0x349cba85, __VMLINUX_SYMBOL_STR(strchr) },
	{ 0xa05a210c, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0x9cdd6eca, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x98cf60b3, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x92827074, __VMLINUX_SYMBOL_STR(wakeup_source_add) },
	{ 0x9c64fbd, __VMLINUX_SYMBOL_STR(ieee80211_frequency_to_channel) },
	{ 0xc3cd8dfb, __VMLINUX_SYMBOL_STR(__pm_stay_awake) },
	{ 0x23d0743a, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0xe4550ff3, __VMLINUX_SYMBOL_STR(find_vpid) },
	{ 0xd3c4ec44, __VMLINUX_SYMBOL_STR(sdio_enable_func) },
	{ 0xa522528b, __VMLINUX_SYMBOL_STR(sdio_claim_irq) },
	{ 0x215adea4, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0xf6f0ffed, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0x84bc974b, __VMLINUX_SYMBOL_STR(__arch_copy_from_user) },
	{ 0x388ed3f8, __VMLINUX_SYMBOL_STR(skb_clone) },
	{ 0x308eba2e, __VMLINUX_SYMBOL_STR(dev_get_by_name) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0xdcff44e5, __VMLINUX_SYMBOL_STR(skb_copy) },
	{ 0xfa91eb38, __VMLINUX_SYMBOL_STR(down_interruptible) },
	{ 0xa19da04f, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xd2da1048, __VMLINUX_SYMBOL_STR(register_netdevice_notifier) },
	{ 0x4222d04e, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0x88bfa7e, __VMLINUX_SYMBOL_STR(cancel_work_sync) },
	{ 0x1cd10264, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xef75341f, __VMLINUX_SYMBOL_STR(cfg80211_rx_mgmt) },
	{ 0x3b2278b6, __VMLINUX_SYMBOL_STR(filp_close) },
	{ 0x8b0adb3d, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0xeae3dfd6, __VMLINUX_SYMBOL_STR(__const_udelay) },
	{ 0x9580deb, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0xbd58f31d, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0xc9f0d035, __VMLINUX_SYMBOL_STR(__pm_wakeup_event) },
	{ 0x790b8e8, __VMLINUX_SYMBOL_STR(get_wifi_chip_type) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xf4c91ed, __VMLINUX_SYMBOL_STR(ns_to_timespec) },
	{ 0xbf2b7238, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x15aa810d, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xfc28c265, __VMLINUX_SYMBOL_STR(sdio_get_host_pm_caps) },
	{ 0x9d0d6206, __VMLINUX_SYMBOL_STR(unregister_netdevice_notifier) },
	{ 0xade00cb7, __VMLINUX_SYMBOL_STR(rockchip_wifi_set_carddetect) },
	{ 0x2187b59c, __VMLINUX_SYMBOL_STR(skb_trim) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0xd42fb84, __VMLINUX_SYMBOL_STR(cfg80211_mgmt_tx_status) },
	{ 0xd9864a31, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0xacc5b5d2, __VMLINUX_SYMBOL_STR(csum_ipv6_magic) },
	{ 0xb2de8687, __VMLINUX_SYMBOL_STR(netif_rx) },
	{ 0xcda7cfd6, __VMLINUX_SYMBOL_STR(wakeup_source_prepare) },
	{ 0x9ea1ff8d, __VMLINUX_SYMBOL_STR(__pskb_pull_tail) },
	{ 0xab40cca9, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xf0ddd9c9, __VMLINUX_SYMBOL_STR(PDE_DATA) },
	{ 0xf9dde891, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0xe8b32f32, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xa9244c06, __VMLINUX_SYMBOL_STR(sdio_writel) },
	{ 0x706d051c, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0xd3259d65, __VMLINUX_SYMBOL_STR(test_and_set_bit) },
	{ 0x48df828e, __VMLINUX_SYMBOL_STR(cfg80211_vendor_cmd_reply) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x2267b1a2, __VMLINUX_SYMBOL_STR(__ieee80211_get_channel) },
	{ 0x317042a, __VMLINUX_SYMBOL_STR(netif_tx_wake_queue) },
	{ 0x49ce3eb1, __VMLINUX_SYMBOL_STR(netif_tx_stop_all_queues) },
	{ 0x97fdbab9, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x6acab429, __VMLINUX_SYMBOL_STR(cfg80211_get_bss) },
	{ 0x37befc70, __VMLINUX_SYMBOL_STR(jiffies_to_msecs) },
	{ 0x509b5f6d, __VMLINUX_SYMBOL_STR(mutex_lock_interruptible) },
	{ 0x5983685b, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0xbb431f77, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x7e801204, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0xbc1ee1f0, __VMLINUX_SYMBOL_STR(wiphy_unregister) },
	{ 0xfaef0ed, __VMLINUX_SYMBOL_STR(__tasklet_schedule) },
	{ 0x9166fada, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0xf27c099, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0x8afaebe7, __VMLINUX_SYMBOL_STR(nla_put) },
	{ 0x73ccd87d, __VMLINUX_SYMBOL_STR(sdio_readl) },
	{ 0x1ac3bee6, __VMLINUX_SYMBOL_STR(cfg80211_del_sta_sinfo) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0xa7474231, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0xa001d6fc, __VMLINUX_SYMBOL_STR(cfg80211_connect_result) },
	{ 0x9b3057be, __VMLINUX_SYMBOL_STR(proc_mkdir_data) },
	{ 0xa40af9f4, __VMLINUX_SYMBOL_STR(cfg80211_michael_mic_failure) },
	{ 0x4a754bd, __VMLINUX_SYMBOL_STR(wiphy_apply_custom_regulatory) },
	{ 0x9545af6d, __VMLINUX_SYMBOL_STR(tasklet_init) },
	{ 0x16e5c2a, __VMLINUX_SYMBOL_STR(mod_timer) },
	{ 0x2469810f, __VMLINUX_SYMBOL_STR(__rcu_read_unlock) },
	{ 0x9d265a9c, __VMLINUX_SYMBOL_STR(kill_pid) },
	{ 0xa735db59, __VMLINUX_SYMBOL_STR(prandom_u32) },
	{ 0x43b0c9c3, __VMLINUX_SYMBOL_STR(preempt_schedule) },
	{ 0xc86bfa62, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0xec0f4d50, __VMLINUX_SYMBOL_STR(cfg80211_ibss_joined) },
	{ 0xd0ac6502, __VMLINUX_SYMBOL_STR(init_net) },
	{ 0x72dd9a1a, __VMLINUX_SYMBOL_STR(__pm_relax) },
	{ 0xc849cb03, __VMLINUX_SYMBOL_STR(__cfg80211_send_event_skb) },
	{ 0x82072614, __VMLINUX_SYMBOL_STR(tasklet_kill) },
	{ 0xd4b4234, __VMLINUX_SYMBOL_STR(flush_signals) },
	{ 0x856b9e93, __VMLINUX_SYMBOL_STR(sdio_unregister_driver) },
	{ 0x847b9fe, __VMLINUX_SYMBOL_STR(sdio_f0_writeb) },
	{ 0x37e9eebc, __VMLINUX_SYMBOL_STR(sdio_set_host_pm_flags) },
	{ 0x89f39a5e, __VMLINUX_SYMBOL_STR(netif_device_attach) },
	{ 0xc786d7fb, __VMLINUX_SYMBOL_STR(cfg80211_roamed) },
	{ 0xa9da3d85, __VMLINUX_SYMBOL_STR(cfg80211_put_bss) },
	{ 0x12a38747, __VMLINUX_SYMBOL_STR(usleep_range) },
	{ 0xb44f7ce1, __VMLINUX_SYMBOL_STR(__cfg80211_alloc_event_skb) },
	{ 0xbc45a16a, __VMLINUX_SYMBOL_STR(__cfg80211_alloc_reply_skb) },
	{ 0xc24d7222, __VMLINUX_SYMBOL_STR(wiphy_register) },
	{ 0xb35dea8f, __VMLINUX_SYMBOL_STR(__arch_copy_to_user) },
	{ 0xabbbd444, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0xbd5da52, __VMLINUX_SYMBOL_STR(sdio_release_irq) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0x96b29254, __VMLINUX_SYMBOL_STR(strncasecmp) },
	{ 0x1055ee9e, __VMLINUX_SYMBOL_STR(cfg80211_ready_on_channel) },
	{ 0xe77e14fe, __VMLINUX_SYMBOL_STR(nla_put_nohdr) },
	{ 0x21e0ba9e, __VMLINUX_SYMBOL_STR(wiphy_new_nm) },
	{ 0x69d58296, __VMLINUX_SYMBOL_STR(eth_type_trans) },
	{ 0xb79c36e8, __VMLINUX_SYMBOL_STR(proc_get_parent_data) },
	{ 0x329e064c, __VMLINUX_SYMBOL_STR(sdio_f0_readb) },
	{ 0x51ecdaa3, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0x8da6a588, __VMLINUX_SYMBOL_STR(cfg80211_disconnected) },
	{ 0x5cd885d5, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x96220280, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xfbc3924a, __VMLINUX_SYMBOL_STR(unregister_netdevice_queue) },
	{ 0x4f9b1a2d, __VMLINUX_SYMBOL_STR(cfg80211_new_sta) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0x3ca695bb, __VMLINUX_SYMBOL_STR(sdio_memcpy_toio) },
	{ 0x6a5cb913, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0xd8e31812, __VMLINUX_SYMBOL_STR(sdio_writew) },
	{ 0x7cc253aa, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x6df1aaf1, __VMLINUX_SYMBOL_STR(kernel_sigaction) },
	{ 0x1603dc15, __VMLINUX_SYMBOL_STR(dev_alloc_name) },
	{ 0xae8c4d0c, __VMLINUX_SYMBOL_STR(set_bit) },
	{ 0x324b3877, __VMLINUX_SYMBOL_STR(up) },
	{ 0xf5a3cf74, __VMLINUX_SYMBOL_STR(rockchip_wifi_power) },
	{ 0xe95ab30d, __VMLINUX_SYMBOL_STR(skb_dequeue) },
	{ 0x76051c4a, __VMLINUX_SYMBOL_STR(cfg80211_remain_on_channel_expired) },
	{ 0xd132b2c7, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0x58412040, __VMLINUX_SYMBOL_STR(netif_wake_subqueue) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0xbdbc13a1, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x5a9f1d63, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0x959a87ac, __VMLINUX_SYMBOL_STR(sdio_readw) },
	{ 0x6a48f92a, __VMLINUX_SYMBOL_STR(sdio_register_driver) },
	{ 0xe113bbbc, __VMLINUX_SYMBOL_STR(csum_partial) },
	{ 0xef6f52bc, __VMLINUX_SYMBOL_STR(sdio_memcpy_fromio) },
	{ 0xf9bfeb95, __VMLINUX_SYMBOL_STR(sdio_claim_host) },
	{ 0x85670f1d, __VMLINUX_SYMBOL_STR(rtnl_is_locked) },
	{ 0x7f02188f, __VMLINUX_SYMBOL_STR(__msecs_to_jiffies) },
	{ 0xd19f53ca, __VMLINUX_SYMBOL_STR(cfg80211_scan_done) },
	{ 0x8d522714, __VMLINUX_SYMBOL_STR(__rcu_read_lock) },
	{ 0x9854ee83, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xf3a426a4, __VMLINUX_SYMBOL_STR(wait_for_completion_timeout) },
	{ 0x65e0c549, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x3a46524b, __VMLINUX_SYMBOL_STR(skb_copy_bits) },
	{ 0x9c8bfe92, __VMLINUX_SYMBOL_STR(sdio_set_block_size) },
	{ 0x3c851c7e, __VMLINUX_SYMBOL_STR(wakeup_source_drop) },
	{ 0x9e7d6bd0, __VMLINUX_SYMBOL_STR(__udelay) },
	{ 0x75ab9ab2, __VMLINUX_SYMBOL_STR(wakeup_source_remove) },
	{ 0x88db9f48, __VMLINUX_SYMBOL_STR(__check_object_size) },
	{ 0x760a0f4f, __VMLINUX_SYMBOL_STR(yield) },
	{ 0xb8f16bfc, __VMLINUX_SYMBOL_STR(sdio_disable_func) },
	{ 0xbc3681f8, __VMLINUX_SYMBOL_STR(sdio_release_host) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
	{ 0xff0229fb, __VMLINUX_SYMBOL_STR(filp_open) },
	{ 0x6f76a13b, __VMLINUX_SYMBOL_STR(alloc_etherdev_mqs) },
	{ 0xf7fbc02e, __VMLINUX_SYMBOL_STR(cfg80211_inform_bss_frame_data) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("sdio:c*v024Cd8179*");

MODULE_INFO(srcversion, "96E32152AD67DDBE4E83022");
