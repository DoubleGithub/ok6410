# To build modules outside of the kernel tree, we run "make"
# in the kernel source tree; the Makefile these then includes this
# Makefile once again.
# This conditional selects whether we are being included from the
# kernel Makefile or not.
ifeq ($(KERNELRELEASE),)

    # Assume the source tree is where the running kernel was built
    # You should set KERNELDIR in the environment if it's elsewhere
    #KERNELDIR ?= /usr/src/kernels/linux-3.0.1
    KERNELDIR ?= /usr/src/kernels/2.6.32-696.el6.i686
    # The current directory is passed to sub-makes as argument
    PWD := $(shell pwd)
	PRINT_INC = $(PWD)
	EXTRA_CFLAGS += -I $(PRINT_INC)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

.PHONY: modules modules_install clean

else
    # called from kernel build system: just declare what our modules are
    obj-m := add_sub.o
endif
