#!/bin/bash
#set -e
#set -u
#set -o pipefail

echo "hello CC=${CC}"
cd "./KERNEL" || exit

while getopts 'dcgy:' OPTION; do
  case "$OPTION" in
    d)
      rm -rf .distclean.txt
      now=$(date +"%T")
      echo "dist clean start --> Current time : $now"
      echo "make ARCH=arm CROSS_COMPILE=${CC} distclean"
      make ARCH=arm CROSS_COMPILE=${CC} distclean &> .distclean.txt
      echo "distclean is completed"
      now=$(date +"%T")
      echo "dist clean end --> Current time : $now"
      ;;

    c)
      rm -rf .defconfig.txt
      now=$(date +"%T")
      echo "defconfig start --> Current time : $now"
      echo "make ARCH=arm CROSS_COMPILE=${CC} omap2plus_defconfig"
      make ARCH=arm CROSS_COMPILE=${CC} omap2plus_defconfig &> .defconfig.txt
      make ARCH=arm CROSS_COMPILE="${CC}" menuconfig
      echo "def config successful"
      now=$(date +"%T")
      echo "defconfig end --> Current time : $now"
      ;;

    g)
      rm -rf .compilelog.txt
      now=$(date +"%T")
      echo "compile starts --> Current time : $now"
      echo "make -j4 ARCH=arm CROSS_COMPILE=${CC} LOADADDR=0x80008000 uImage dtbs modules"
      make -j4 ARCH=arm CROSS_COMPILE=${CC} LOADADDR=0x80008000 uImage dtbs modules 2>&1 | tee -a .compilelog.txt
      echo "Compilation ends"
      now=$(date +"%T")
      echo "compile end --> Current time : $now"
      ;;
    ?)
      echo "script usage: $(basename $0) [-d [-c] [-y]" >&2
      exit 1
      ;;
  esac
done
shift "$(($OPTIND -1))"





#make ARCH=arm CROSS_COMPILE=${CC} distclean

#make ARCH=arm CROSS_COMPILE=${CC} shashi_bbb_defconfig

#make -j4 ARCH=arm CROSS_COMPILE=${CC} LOADADDR=0x80008000 uImage dtbs modules
