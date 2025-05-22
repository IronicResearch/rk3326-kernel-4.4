# rk3326-kernel-4.4
Development snapshot for RK3326 kernel 4.4

Uses gcc ARM cross-compiler package for Ubuntu 16.

```
$ sudo apt-get install gcc-arm-linux-gnueabihf
```

Refer to `make-kernel.sh` script for compiling kernel config + binary images.

```
$ ./make-kernel.sh
```
Equivalent to the following `make` commands:

```
make ARCH=arm64 rk3326_yk_defconfig
make ARCH=arm64 dpf1m2_3326m1a.img -j8
```

Resulting kernel.img + resource.img binaries compatible with Rockchip flash tools and AOSP packing tools.

