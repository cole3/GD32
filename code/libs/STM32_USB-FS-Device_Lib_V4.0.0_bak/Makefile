CROSS_COMPILE=arm-none-eabi
CC=$(CROSS_COMPILE)-gcc
LD=$(CROSS_COMPILE)-ld -v
OBJCOPY=$(CROSS_COMPILE)-objcopy
AR=$(CROSS_COMPILE)-ar
GDB=$(CROSS_COMPILE)-gdb

PLATFORM=STM3210B_EVAL
TOP=$(PWD)
LIBS+=libstm32.a libstm32all.a

SRCPATH1=$(TOP)/Libraries/CMSIS/Device/ST/STM32F10x/Source/Templates
SRCPATH2=$(TOP)/Libraries/STM32F10x_StdPeriph_Driver/src
SRCPATH3=$(TOP)/Libraries/STM32_USB-FS-Device_Driver/src
SRCPATH4=$(TOP)/Projects/Custom_HID/src

CFLAGSlib=-g -mcpu=cortex-m3 -mthumb -O0 -Wall -Werror -c
CFLAGSlib+=-D STM32F10X_HD -D VECT_TAB_FLASH -D USE_$(PLATFORM) -D USE_STDPERIPH_DRIVER
CFLAGSlib+= -I$(TOP)/Libraries/CMSIS/Include \
			-I$(TOP)/Libraries/CMSIS/Device/ST/STM32F10x/Include \
			-I$(TOP)/Libraries/STM32F10x_StdPeriph_Driver/inc \
			-I$(TOP)/Libraries/STM32_USB-FS-Device_Driver/inc \
			-I$(TOP)/Utilities/STM32_EVAL/$(PLATFORM) \
			-I$(TOP)/Utilities/STM32_EVAL/Common \
			-I$(TOP)/Projects/Custom_HID/inc


all: libs
libs: $(LIBS)

libstm32.a:
	@echo "Building $@ part1..."
	@cd $(SRCPATH1) && \
		$(CC) $(CFLAGSlib) \
		system_stm32f10x.c
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

libstm32all.a:
	@echo "Building $@ part1..."
	@cd $(SRCPATH3) && \
		$(CC) $(CFLAGSlib) \
		*.c
	@echo "Building $@ part2..."
	@cd $(SRCPATH4) && \
		$(CC) $(CFLAGSlib) \
		*.c
	@echo "Aring $@ ..."
	@$(AR) cr $@ \
		$(SRCPATH1)/*.o \
		$(SRCPATH2)/*.o \
		$(SRCPATH3)/*.o \
		$(SRCPATH4)/*.o
	@echo "done."

.PHONY: libs clean tshow
clean:
	rm -f $(SRCPATH1)/*.o
	rm -f $(SRCPATH2)/*.o
	rm -f $(SRCPATH3)/*.o
	rm -f $(SRCPATH4)/*.o
	rm -f $(LIBS)

