KERNELDIR = /lib/modules/$(shell uname -r)/build

obj-m := simple_char_drv2.o

PWD := $(shell pwd)

default: 
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean: 
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean


