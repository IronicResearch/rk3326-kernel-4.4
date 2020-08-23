cmd_firmware/kaweth/new_code.bin.gen.o := ./scripts/gcc-wrapper.py ./../prebuilts/gcc/linux-x86/aarch64/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc -Wp,-MD,firmware/kaweth/.new_code.bin.gen.o.d  -nostdinc -isystem /work2/yujian/81-rk3326/prebuilts/gcc/linux-x86/aarch64/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/../lib/gcc/aarch64-linux-gnu/6.3.1/include -I./arch/arm64/include -Iarch/arm64/include/generated/uapi -Iarch/arm64/include/generated  -Iinclude -I./arch/arm64/include/uapi -Iarch/arm64/include/generated/uapi -I./include/uapi -Iinclude/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian   -D__ASSEMBLY__ -fno-PIE -DCONFIG_AS_LSE=1 -DCC_HAVE_ASM_GOTO -Wa,-gdwarf-2            -c -o firmware/kaweth/new_code.bin.gen.o firmware/kaweth/new_code.bin.gen.S

source_firmware/kaweth/new_code.bin.gen.o := firmware/kaweth/new_code.bin.gen.S

deps_firmware/kaweth/new_code.bin.gen.o := \

firmware/kaweth/new_code.bin.gen.o: $(deps_firmware/kaweth/new_code.bin.gen.o)

$(deps_firmware/kaweth/new_code.bin.gen.o):
