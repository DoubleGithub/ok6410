obj-m := keyint.o
KDIR :=/lib/modules/3.0.1/build
all:
	make -C $(KDIR) M=$(PWD) modules CROSS_COMPILE=arm-linux- ARCH=arm
clean:
	rm -f *.ko *.o *.order *.symvers *.mod.c *~
