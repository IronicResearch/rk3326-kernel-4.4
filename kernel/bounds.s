	.arch armv8-a
	.file	"bounds.c"
// GNU C89 (Linaro GCC 6.3-2017.05) version 6.3.1 20170404 (aarch64-linux-gnu)
//	compiled by GNU C version 4.8.4, GMP version 6.1.0, MPFR version 3.1.4, MPC version 1.0.3, isl version none
// GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
// options passed:  -nostdinc -I ./arch/arm64/include
// -I arch/arm64/include/generated/uapi -I arch/arm64/include/generated
// -I include -I ./arch/arm64/include/uapi
// -I arch/arm64/include/generated/uapi -I ./include/uapi
// -I include/generated/uapi -imultiarch aarch64-linux-gnu
// -iprefix /work2/yujian/81-rk3326/prebuilts/gcc/linux-x86/aarch64/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/../lib/gcc/aarch64-linux-gnu/6.3.1/
// -isysroot /work2/yujian/81-rk3326/prebuilts/gcc/linux-x86/aarch64/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc
// -D __KERNEL__ -D CONFIG_AS_LSE=1 -D CC_HAVE_ASM_GOTO -D KBUILD_STR(s)=#s
// -D KBUILD_BASENAME=KBUILD_STR(bounds)
// -D KBUILD_MODNAME=KBUILD_STR(bounds)
// -isystem /work2/yujian/81-rk3326/prebuilts/gcc/linux-x86/aarch64/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/../lib/gcc/aarch64-linux-gnu/6.3.1/include
// -include ./include/linux/kconfig.h -MD kernel/.bounds.s.d
// kernel/bounds.c -mlittle-endian -mgeneral-regs-only
// -mpc-relative-literal-loads -march=armv8-a -mabi=lp64
// -auxbase-strip kernel/bounds.s -g -Os -Wall -Wundef -Wstrict-prototypes
// -Wno-trigraphs -Werror=implicit-function-declaration
// -Wno-format-security -Wno-maybe-uninitialized -Wno-frame-address
// -Wframe-larger-than=2048 -Wno-unused-but-set-variable
// -Wunused-const-variable=0 -Wdeclaration-after-statement
// -Wno-pointer-sign -Werror=implicit-int -Werror=strict-prototypes
// -Werror=date-time -std=gnu90 -fno-strict-aliasing -fno-common -fno-pic
// -fno-asynchronous-unwind-tables -fno-delete-null-pointer-checks
// -fstack-protector-strong -fno-omit-frame-pointer
// -fno-optimize-sibling-calls -fno-var-tracking-assignments
// -fno-strict-overflow -fno-merge-all-constants -fmerge-constants
// -fstack-check=no -fconserve-stack -fverbose-asm
// --param allow-store-data-races=0
// options enabled:  -faggressive-loop-optimizations -falign-functions
// -falign-jumps -falign-labels -falign-loops -fauto-inc-dec
// -fbranch-count-reg -fcaller-saves -fchkp-check-incomplete-type
// -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
// -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
// -fchkp-use-static-bounds -fchkp-use-static-const-bounds
// -fchkp-use-wrappers -fcombine-stack-adjustments -fcompare-elim
// -fcprop-registers -fcrossjumping -fcse-follow-jumps -fdefer-pop
// -fdevirtualize -fdevirtualize-speculatively -fdwarf2-cfi-asm
// -fearly-inlining -feliminate-unused-debug-types
// -fexpensive-optimizations -fforward-propagate -ffunction-cse -fgcse
// -fgcse-lm -fgnu-runtime -fgnu-unique -fguess-branch-probability
// -fhoist-adjacent-loads -fident -fif-conversion -fif-conversion2
// -findirect-inlining -finline -finline-atomics -finline-functions
// -finline-functions-called-once -finline-small-functions -fipa-cp
// -fipa-cp-alignment -fipa-icf -fipa-icf-functions -fipa-icf-variables
// -fipa-profile -fipa-pure-const -fipa-ra -fipa-reference -fipa-sra
// -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
// -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
// -fleading-underscore -flifetime-dse -flra-remat -flto-odr-type-merging
// -fmath-errno -fmerge-constants -fmerge-debug-strings
// -fmove-loop-invariants -fomit-frame-pointer -fpartial-inlining
// -fpeephole -fpeephole2 -fplt -fprefetch-loop-arrays -free
// -freg-struct-return -freorder-blocks -freorder-functions
// -frerun-cse-after-loop -fsched-critical-path-heuristic
// -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
// -fsched-last-insn-heuristic -fsched-pressure -fsched-rank-heuristic
// -fsched-spec -fsched-spec-insn-heuristic -fsched-stalled-insns-dep
// -fschedule-fusion -fschedule-insns2 -fsection-anchors
// -fsemantic-interposition -fshow-column -fshrink-wrap -fsigned-zeros
// -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-backprop -fssa-phiopt
// -fstack-protector-strong -fstdarg-opt -fstrict-volatile-bitfields
// -fsync-libcalls -fthread-jumps -ftoplevel-reorder -ftrapping-math
// -ftree-bit-ccp -ftree-builtin-call-dce -ftree-ccp -ftree-ch
// -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim -ftree-dce
// -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
// -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
// -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pre
// -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr
// -ftree-sra -ftree-switch-conversion -ftree-tail-merge -ftree-ter
// -ftree-vrp -funit-at-a-time -fvar-tracking -fverbose-asm
// -fzero-initialized-in-bss -mfix-cortex-a53-835769
// -mfix-cortex-a53-843419 -mgeneral-regs-only -mglibc -mlittle-endian
// -momit-leaf-frame-pointer -mpc-relative-literal-loads

	.text
.Ltext0:
	.cfi_sections	.debug_frame
#APP
	.irp	num,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30
	.equ	.L__reg_num_x\num, \num
	.endr
	.equ	.L__reg_num_xzr, 31

	.macro	mrs_s, rt, sreg
	.inst	0xd5200000|(\sreg)|(.L__reg_num_\rt)
	.endm

	.macro	msr_s, sreg, rt
	.inst	0xd5000000|(\sreg)|(.L__reg_num_\rt)
	.endm

#NO_APP
	.align	2
	.global	foo
	.type	foo, %function
foo:
.LFB134:
	.file 1 "kernel/bounds.c"
	.loc 1 16 0
	.cfi_startproc
	.loc 1 18 0
#APP
// 18 "kernel/bounds.c" 1
	
.ascii "->NR_PAGEFLAGS 21 __NR_PAGEFLAGS"	//
// 0 "" 2
	.loc 1 19 0
// 19 "kernel/bounds.c" 1
	
.ascii "->MAX_NR_ZONES 3 __MAX_NR_ZONES"	//
// 0 "" 2
	.loc 1 21 0
// 21 "kernel/bounds.c" 1
	
.ascii "->NR_CPUS_BITS 3 ilog2(CONFIG_NR_CPUS)"	//
// 0 "" 2
	.loc 1 23 0
// 23 "kernel/bounds.c" 1
	
.ascii "->SPINLOCK_SIZE 4 sizeof(spinlock_t)"	//
// 0 "" 2
#NO_APP
	ret
	.cfi_endproc
.LFE134:
	.size	foo, .-foo
.Letext0:
	.file 2 "include/linux/types.h"
	.file 3 "include/linux/init.h"
	.file 4 "./arch/arm64/include/asm/cachetype.h"
	.file 5 "include/linux/printk.h"
	.file 6 "include/linux/kernel.h"
	.file 7 "include/linux/page-flags.h"
	.file 8 "include/linux/mmzone.h"
	.file 9 "include/linux/lockdep.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.4byte	0x3bf
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.4byte	.LASF90
	.byte	0x1
	.4byte	.LASF91
	.4byte	.LASF92
	.8byte	.Ltext0
	.8byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF2
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF3
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF4
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF8
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF9
	.uleb128 0x4
	.4byte	0x73
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF10
	.uleb128 0x5
	.byte	0x8
	.4byte	0x73
	.uleb128 0x6
	.4byte	.LASF12
	.byte	0x2
	.byte	0x1d
	.4byte	0x97
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.4byte	.LASF11
	.uleb128 0x6
	.4byte	.LASF13
	.byte	0x3
	.byte	0x83
	.4byte	0xa9
	.uleb128 0x5
	.byte	0x8
	.4byte	0xaf
	.uleb128 0x7
	.4byte	0x49
	.uleb128 0x5
	.byte	0x8
	.4byte	0xba
	.uleb128 0x8
	.uleb128 0x9
	.4byte	0x9e
	.4byte	0xc6
	.uleb128 0xa
	.byte	0
	.uleb128 0xb
	.4byte	.LASF14
	.byte	0x3
	.byte	0x86
	.4byte	0xbb
	.uleb128 0xb
	.4byte	.LASF15
	.byte	0x3
	.byte	0x86
	.4byte	0xbb
	.uleb128 0xb
	.4byte	.LASF16
	.byte	0x3
	.byte	0x87
	.4byte	0xbb
	.uleb128 0xb
	.4byte	.LASF17
	.byte	0x3
	.byte	0x87
	.4byte	0xbb
	.uleb128 0x9
	.4byte	0x73
	.4byte	0xfd
	.uleb128 0xa
	.byte	0
	.uleb128 0xb
	.4byte	.LASF18
	.byte	0x3
	.byte	0x8e
	.4byte	0xf2
	.uleb128 0xb
	.4byte	.LASF19
	.byte	0x3
	.byte	0x8f
	.4byte	0x86
	.uleb128 0xb
	.4byte	.LASF20
	.byte	0x3
	.byte	0x90
	.4byte	0x50
	.uleb128 0xb
	.4byte	.LASF21
	.byte	0x3
	.byte	0x9c
	.4byte	0xb4
	.uleb128 0xb
	.4byte	.LASF22
	.byte	0x3
	.byte	0x9e
	.4byte	0x8c
	.uleb128 0xb
	.4byte	.LASF23
	.byte	0x4
	.byte	0x28
	.4byte	0x65
	.uleb128 0x9
	.4byte	0x7a
	.4byte	0x14a
	.uleb128 0xa
	.byte	0
	.uleb128 0x4
	.4byte	0x13f
	.uleb128 0xb
	.4byte	.LASF24
	.byte	0x5
	.byte	0xa
	.4byte	0x14a
	.uleb128 0xb
	.4byte	.LASF25
	.byte	0x5
	.byte	0xb
	.4byte	0x14a
	.uleb128 0x9
	.4byte	0x49
	.4byte	0x170
	.uleb128 0xa
	.byte	0
	.uleb128 0xb
	.4byte	.LASF26
	.byte	0x5
	.byte	0x2e
	.4byte	0x165
	.uleb128 0xb
	.4byte	.LASF27
	.byte	0x5
	.byte	0x9f
	.4byte	0x49
	.uleb128 0xb
	.4byte	.LASF28
	.byte	0x5
	.byte	0xa0
	.4byte	0x49
	.uleb128 0xb
	.4byte	.LASF29
	.byte	0x5
	.byte	0xa1
	.4byte	0x49
	.uleb128 0xc
	.4byte	.LASF31
	.uleb128 0x4
	.4byte	0x19c
	.uleb128 0xd
	.4byte	.LASF30
	.byte	0x5
	.2byte	0x1a4
	.4byte	0x1a1
	.uleb128 0xc
	.4byte	.LASF32
	.uleb128 0xd
	.4byte	.LASF33
	.byte	0x6
	.2byte	0x104
	.4byte	0x1b2
	.uleb128 0xe
	.4byte	0x7f
	.4byte	0x1d2
	.uleb128 0xf
	.4byte	0x49
	.byte	0
	.uleb128 0xd
	.4byte	.LASF34
	.byte	0x6
	.2byte	0x105
	.4byte	0x1de
	.uleb128 0x5
	.byte	0x8
	.4byte	0x1c3
	.uleb128 0xd
	.4byte	.LASF35
	.byte	0x6
	.2byte	0x1bf
	.4byte	0x49
	.uleb128 0xd
	.4byte	.LASF36
	.byte	0x6
	.2byte	0x1c0
	.4byte	0x49
	.uleb128 0xd
	.4byte	.LASF37
	.byte	0x6
	.2byte	0x1c1
	.4byte	0x49
	.uleb128 0xd
	.4byte	.LASF38
	.byte	0x6
	.2byte	0x1c2
	.4byte	0x49
	.uleb128 0xd
	.4byte	.LASF39
	.byte	0x6
	.2byte	0x1c3
	.4byte	0x49
	.uleb128 0xd
	.4byte	.LASF40
	.byte	0x6
	.2byte	0x1c4
	.4byte	0x49
	.uleb128 0xd
	.4byte	.LASF41
	.byte	0x6
	.2byte	0x1c5
	.4byte	0x49
	.uleb128 0xd
	.4byte	.LASF42
	.byte	0x6
	.2byte	0x1c7
	.4byte	0x8c
	.uleb128 0xd
	.4byte	.LASF43
	.byte	0x6
	.2byte	0x1da
	.4byte	0x49
	.uleb128 0xd
	.4byte	.LASF44
	.byte	0x6
	.2byte	0x1dc
	.4byte	0x8c
	.uleb128 0x10
	.4byte	.LASF53
	.byte	0x4
	.4byte	0x50
	.byte	0x6
	.2byte	0x1df
	.4byte	0x28c
	.uleb128 0x11
	.4byte	.LASF45
	.byte	0
	.uleb128 0x11
	.4byte	.LASF46
	.byte	0x1
	.uleb128 0x11
	.4byte	.LASF47
	.byte	0x2
	.uleb128 0x11
	.4byte	.LASF48
	.byte	0x3
	.uleb128 0x11
	.4byte	.LASF49
	.byte	0x4
	.byte	0
	.uleb128 0xd
	.4byte	.LASF50
	.byte	0x6
	.2byte	0x1e5
	.4byte	0x25c
	.uleb128 0xd
	.4byte	.LASF51
	.byte	0x6
	.2byte	0x1f8
	.4byte	0x14a
	.uleb128 0xd
	.4byte	.LASF52
	.byte	0x6
	.2byte	0x203
	.4byte	0x14a
	.uleb128 0x12
	.4byte	.LASF54
	.byte	0x4
	.4byte	0x50
	.byte	0x7
	.byte	0x4a
	.4byte	0x369
	.uleb128 0x11
	.4byte	.LASF55
	.byte	0
	.uleb128 0x11
	.4byte	.LASF56
	.byte	0x1
	.uleb128 0x11
	.4byte	.LASF57
	.byte	0x2
	.uleb128 0x11
	.4byte	.LASF58
	.byte	0x3
	.uleb128 0x11
	.4byte	.LASF59
	.byte	0x4
	.uleb128 0x11
	.4byte	.LASF60
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF61
	.byte	0x6
	.uleb128 0x11
	.4byte	.LASF62
	.byte	0x7
	.uleb128 0x11
	.4byte	.LASF63
	.byte	0x8
	.uleb128 0x11
	.4byte	.LASF64
	.byte	0x9
	.uleb128 0x11
	.4byte	.LASF65
	.byte	0xa
	.uleb128 0x11
	.4byte	.LASF66
	.byte	0xb
	.uleb128 0x11
	.4byte	.LASF67
	.byte	0xc
	.uleb128 0x11
	.4byte	.LASF68
	.byte	0xd
	.uleb128 0x11
	.4byte	.LASF69
	.byte	0xe
	.uleb128 0x11
	.4byte	.LASF70
	.byte	0xf
	.uleb128 0x11
	.4byte	.LASF71
	.byte	0x10
	.uleb128 0x11
	.4byte	.LASF72
	.byte	0x11
	.uleb128 0x11
	.4byte	.LASF73
	.byte	0x12
	.uleb128 0x11
	.4byte	.LASF74
	.byte	0x13
	.uleb128 0x11
	.4byte	.LASF75
	.byte	0x14
	.uleb128 0x11
	.4byte	.LASF76
	.byte	0x15
	.uleb128 0x11
	.4byte	.LASF77
	.byte	0x8
	.uleb128 0x11
	.4byte	.LASF78
	.byte	0xc
	.uleb128 0x11
	.4byte	.LASF79
	.byte	0x8
	.uleb128 0x11
	.4byte	.LASF80
	.byte	0x4
	.uleb128 0x11
	.4byte	.LASF81
	.byte	0x8
	.uleb128 0x11
	.4byte	.LASF82
	.byte	0xb
	.byte	0
	.uleb128 0x10
	.4byte	.LASF83
	.byte	0x4
	.4byte	0x50
	.byte	0x8
	.2byte	0x115
	.4byte	0x393
	.uleb128 0x11
	.4byte	.LASF84
	.byte	0
	.uleb128 0x11
	.4byte	.LASF85
	.byte	0x1
	.uleb128 0x11
	.4byte	.LASF86
	.byte	0x2
	.uleb128 0x11
	.4byte	.LASF87
	.byte	0x3
	.byte	0
	.uleb128 0xb
	.4byte	.LASF88
	.byte	0x9
	.byte	0x10
	.4byte	0x49
	.uleb128 0xb
	.4byte	.LASF89
	.byte	0x9
	.byte	0x11
	.4byte	0x49
	.uleb128 0x13
	.string	"foo"
	.byte	0x1
	.byte	0xf
	.8byte	.LFB134
	.8byte	.LFE134-.LFB134
	.uleb128 0x1
	.byte	0x9c
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x15
	.byte	0
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x15
	.byte	0
	.uleb128 0x27
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.4byte	0x2c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x8
	.byte	0
	.2byte	0
	.2byte	0
	.8byte	.Ltext0
	.8byte	.Letext0-.Ltext0
	.8byte	0
	.8byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF77:
	.string	"PG_checked"
.LASF83:
	.string	"zone_type"
.LASF30:
	.string	"kmsg_fops"
.LASF52:
	.string	"hex_asc_upper"
.LASF24:
	.string	"linux_banner"
.LASF38:
	.string	"panic_on_unrecovered_nmi"
.LASF6:
	.string	"long long unsigned int"
.LASF49:
	.string	"SYSTEM_RESTART"
.LASF34:
	.string	"panic_blink"
.LASF47:
	.string	"SYSTEM_HALT"
.LASF76:
	.string	"__NR_PAGEFLAGS"
.LASF5:
	.string	"long long int"
.LASF0:
	.string	"signed char"
.LASF17:
	.string	"__security_initcall_end"
.LASF19:
	.string	"saved_command_line"
.LASF67:
	.string	"PG_private_2"
.LASF45:
	.string	"SYSTEM_BOOTING"
.LASF54:
	.string	"pageflags"
.LASF91:
	.string	"kernel/bounds.c"
.LASF10:
	.string	"long int"
.LASF40:
	.string	"panic_on_warn"
.LASF64:
	.string	"PG_arch_1"
.LASF25:
	.string	"linux_proc_banner"
.LASF42:
	.string	"crash_kexec_post_notifiers"
.LASF55:
	.string	"PG_locked"
.LASF60:
	.string	"PG_lru"
.LASF57:
	.string	"PG_referenced"
.LASF13:
	.string	"initcall_t"
.LASF31:
	.string	"file_operations"
.LASF4:
	.string	"unsigned int"
.LASF66:
	.string	"PG_private"
.LASF43:
	.string	"root_mountflags"
.LASF41:
	.string	"sysctl_panic_on_stackoverflow"
.LASF7:
	.string	"long unsigned int"
.LASF29:
	.string	"kptr_restrict"
.LASF32:
	.string	"atomic_notifier_head"
.LASF26:
	.string	"console_printk"
.LASF46:
	.string	"SYSTEM_RUNNING"
.LASF3:
	.string	"short unsigned int"
.LASF12:
	.string	"bool"
.LASF80:
	.string	"PG_savepinned"
.LASF28:
	.string	"dmesg_restrict"
.LASF15:
	.string	"__con_initcall_end"
.LASF88:
	.string	"prove_locking"
.LASF72:
	.string	"PG_reclaim"
.LASF56:
	.string	"PG_error"
.LASF8:
	.string	"sizetype"
.LASF79:
	.string	"PG_pinned"
.LASF90:
	.ascii	"GNU C89 6.3.1 20170404 -mlittle-endian -mgeneral-regs-only -"
	.ascii	"mpc-relative-literal-loads -march=armv8-a -mabi=lp64 -g -Os "
	.ascii	"-std=gnu90 -fno-strict-aliasing -fno-common -fno-pic -fno-as"
	.ascii	"ynchronous-unwind-tables -fno-delete-n"
	.string	"ull-pointer-checks -fstack-protector-strong -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fstack-check=no -fconserve-stack --param allow-store-data-races=0"
.LASF20:
	.string	"reset_devices"
.LASF50:
	.string	"system_state"
.LASF68:
	.string	"PG_writeback"
.LASF89:
	.string	"lock_stat"
.LASF75:
	.string	"PG_mlocked"
.LASF36:
	.string	"panic_timeout"
.LASF86:
	.string	"ZONE_MOVABLE"
.LASF16:
	.string	"__security_initcall_start"
.LASF33:
	.string	"panic_notifier_list"
.LASF71:
	.string	"PG_mappedtodisk"
.LASF85:
	.string	"ZONE_NORMAL"
.LASF58:
	.string	"PG_uptodate"
.LASF11:
	.string	"_Bool"
.LASF1:
	.string	"unsigned char"
.LASF53:
	.string	"system_states"
.LASF70:
	.string	"PG_swapcache"
.LASF22:
	.string	"initcall_debug"
.LASF2:
	.string	"short int"
.LASF84:
	.string	"ZONE_DMA"
.LASF62:
	.string	"PG_slab"
.LASF87:
	.string	"__MAX_NR_ZONES"
.LASF59:
	.string	"PG_dirty"
.LASF48:
	.string	"SYSTEM_POWER_OFF"
.LASF35:
	.string	"oops_in_progress"
.LASF9:
	.string	"char"
.LASF69:
	.string	"PG_head"
.LASF92:
	.string	"/work2/yujian/81-rk3326/kernel"
.LASF82:
	.string	"PG_slob_free"
.LASF37:
	.string	"panic_on_oops"
.LASF18:
	.string	"boot_command_line"
.LASF63:
	.string	"PG_owner_priv_1"
.LASF27:
	.string	"printk_delay_msec"
.LASF44:
	.string	"early_boot_irqs_disabled"
.LASF39:
	.string	"panic_on_io_nmi"
.LASF65:
	.string	"PG_reserved"
.LASF61:
	.string	"PG_active"
.LASF23:
	.string	"__icache_flags"
.LASF51:
	.string	"hex_asc"
.LASF78:
	.string	"PG_fscache"
.LASF81:
	.string	"PG_foreign"
.LASF14:
	.string	"__con_initcall_start"
.LASF21:
	.string	"late_time_init"
.LASF73:
	.string	"PG_swapbacked"
.LASF74:
	.string	"PG_unevictable"
	.ident	"GCC: (Linaro GCC 6.3-2017.05) 6.3.1 20170404"
	.section	.note.GNU-stack,"",@progbits
