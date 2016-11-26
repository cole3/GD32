CROSS_COMPILE=arm-none-eabi
CC=$(CROSS_COMPILE)-gcc
LD=$(CROSS_COMPILE)-ld -v
OBJCOPY=$(CROSS_COMPILE)-objcopy
AR=$(CROSS_COMPILE)-ar
GDB=$(CROSS_COMPILE)-gdb

TOP=$(PWD)
LIBS+=libstm32.a

SRCPATH1="$(TOP)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x"
SRCPATH2="$(TOP)/Libraries/STM32F10x_StdPeriph_Driver/src"

CFLAGSlib=-g -mcpu=cortex-m3 -mthumb -O2 -Wall -Werror -c
CFLAGSlib+=-D STM32F10X_HD -D VECT_TAB_FLASH -D USE_STM3210B_EVAL -D USE_STDPERIPH_DRIVER
CFLAGSlib+= -I$(TOP)/Libraries/CMSIS/CM3/CoreSupport \
			-I$(TOP)/Project/STM32F10x_StdPeriph_Template \
			-I$(TOP)/Libraries/STM32F10x_StdPeriph_Driver/inc \
			-I$(TOP)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x \
			-I$(TOP)/Libraries/

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
	@echo "Aring $@ part2..."
	@$(AR) cr $@ \
		$(SRCPATH1)/*.o \
		$(SRCPATH2)/*.o
	@echo "done."

.PHONY: libs clean tshow
clean:
	rm -f $(SRCPATH1)/*.o
	rm -f $(SRCPATH2)/*.o
	rm -f $(LIBS)

