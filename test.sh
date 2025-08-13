#!/bin/sh
sh-elf-objcopy -O binary sf64.elf sf64.bin
mkdcdisc -d sf_data -e sf64.elf -o sf64.cdi -N
/Applications/Flycast.app/Contents/MacOS/Flycast sf64.cdi
