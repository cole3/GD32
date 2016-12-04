CROSS_COMPILE=arm-none-eabi
CC=$(CROSS_COMPILE)-gcc
LD=$(CROSS_COMPILE)-ld -v
OBJCOPY=$(CROSS_COMPILE)-objcopy
AR=$(CROSS_COMPILE)-ar
GDB=$(CROSS_COMPILE)-gdb

TOP=$(PWD)
LIBS+=libgd32.a libgd32all.a

#USB_MODULE=USB_Mouse
#USB_MODULE=USB_MSC
USB_MODULE=Virtual_COM_Port

SRCPATH1=$(TOP)/Libraries/CMSIS
SRCPATH2=$(TOP)/Libraries/GD32F10x_StdPeriph_Driver/src
SRCPATH3=$(TOP)/Libraries/GD32_USB_Device_Driver/src
SRCPATH4=$(TOP)/Libraries/GD32_USB_Device_Library/Core/src
SRCPATH5=$(TOP)/Projects/$(USB_MODULE)/src
SRCPATH6=$(TOP)/Utilities/GD32_EVAL/GD32103C_EVAL

CFLAGSlib=-g -mcpu=cortex-m3 -mthumb -O0 -Wall -Werror -c
CFLAGSlib+=-D GD32F10X_HD -D VECT_TAB_FLASH -D USE_GD32F103C_EVAL
CFLAGSlib+=-D USE_STDPERIPH_DRIVER
CFLAGSlib+= -I$(TOP)/Libraries/CMSIS \
			-I$(TOP)/Libraries/GD32F10x_StdPeriph_Driver/inc \
			-I$(TOP)/Libraries/GD32_USB_Device_Driver/inc \
			-I$(TOP)/Libraries/GD32_USB_Device_Library/Core/inc \
			-I$(TOP)/Projects/$(USB_MODULE)/inc \
			-I$(TOP)/Utilities/GD32_EVAL/GD32103C_EVAL

ifeq "$(USB_MODULE)" "USB_Mouse"
SRCPATH7=$(TOP)/Libraries/GD32_USB_Device_Library/Class/hid/src
CFLAGSlib+= -I$(TOP)/Libraries/GD32_USB_Device_Library/Class/hid/inc
endif
ifeq "$(USB_MODULE)" "USB_MSC"
SRCPATH7=$(TOP)/Libraries/GD32_USB_Device_Library/Class/msc/src
CFLAGSlib+= -I$(TOP)/Libraries/GD32_USB_Device_Library/Class/msc/inc
endif
ifeq "$(USB_MODULE)" "Virtual_COM_Port"
SRCPATH7=$(TOP)/Libraries/GD32_USB_Device_Library/Class/cdc/src
CFLAGSlib+= -I$(TOP)/Libraries/GD32_USB_Device_Library/Class/cdc/inc
endif

all: libs
libs: $(LIBS)

libgd32.a:
	@echo "Building $@ part1..."
	@cd $(SRCPATH1) && \
		$(CC) $(CFLAGSlib) \
		system_gd32f10x.c
	@echo "Building $@ part2..."
	@cd $(SRCPATH2) && \
		$(CC) $(CFLAGSlib) \
		-D"assert_param(expr)=((void)0)" \
		*.c
	@echo "Aring $@ ..."
	@$(AR) cr $@ \
		$(SRCPATH1)/*.o \
		$(SRCPATH2)/*.o
	@echo "done."

libgd32all.a:
	@echo "Building $@ part3..."
	@cd $(SRCPATH3) && \
		$(CC) $(CFLAGSlib) \
		*.c
	@echo "Building $@ part4..."
	@cd $(SRCPATH4) && \
		$(CC) $(CFLAGSlib) \
		*.c
	@echo "Building $@ part5..."
	@cd $(SRCPATH5) && \
		$(CC) $(CFLAGSlib) \
		*.c
	@echo "Building $@ part6..."
	@cd $(SRCPATH6) && \
		$(CC) $(CFLAGSlib) \
		*.c
	@echo "Building $@ part7..."
	@cd $(SRCPATH7) && \
		$(CC) $(CFLAGSlib) \
		*.c
	@echo "Aring $@ ..."
	@$(AR) cr $@ \
		$(SRCPATH1)/*.o \
		$(SRCPATH2)/*.o \
		$(SRCPATH3)/*.o \
		$(SRCPATH4)/*.o \
		$(SRCPATH5)/*.o \
		$(SRCPATH6)/*.o \
		$(SRCPATH7)/*.o 
	@echo "done."

.PHONY: libs clean tshow
clean:
	rm -f $(SRCPATH1)/*.o
	rm -f $(SRCPATH2)/*.o
	rm -f $(SRCPATH3)/*.o
	rm -f $(SRCPATH4)/*.o
	rm -f $(SRCPATH5)/*.o
	rm -f $(SRCPATH6)/*.o
	rm -f $(SRCPATH7)/*.o
	rm -f $(LIBS)

