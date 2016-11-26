CROSS_COMPILE=arm-none-eabi
CC=$(CROSS_COMPILE)-gcc
LD=$(CROSS_COMPILE)-ld -v
OBJCOPY=$(CROSS_COMPILE)-objcopy
AR=$(CROSS_COMPILE)-ar
GDB=$(CROSS_COMPILE)-gdb
READELF=$(CROSS_COMPILE)-readelf
SIZE=$(CROSS_COMPILE)-size
OBJDUMP=$(CROSS_COMPILE)-objdump
NM=$(CROSS_COMPILE)-nm


PLATFORM=STM3210B_EVAL
TOP=$(PWD)
LIBTOP=$(TOP)/../libs
EXE=main

SRCPATH1=$(TOP)
PREFIX=$(TOP)

LDFLAGS=-g -mcpu=cortex-m3 -mthumb -O0 -fno-exceptions -ffunction-sections -fdata-sections
LDFLAGS+=-nostartfiles -Wl,--gc-sections,-Tlinker.ld
LDFLAGS+=-D STM32F10X_HD
#LDFLAGS+=-lstm32
LDFLAGS+=-L$(LIBTOP)/STM32_USB-FS-Device_Lib_V4.0.0
LDFLAGS+=-I$(LIBTOP)/STM32_USB-FS-Device_Lib_V4.0.0/Libraries/CMSIS/Device/ST/STM32F10x/Include
LDFLAGS+=-I$(LIBTOP)/STM32_USB-FS-Device_Lib_V4.0.0/Libraries/CMSIS/Include
LDFLAGS+=-I$(LIBTOP)/STM32_USB-FS-Device_Lib_V4.0.0/Libraries/STM32F10x_StdPeriph_Driver/inc


all: src
src:
	@echo "Building $@ part1..."
	$(CC) -c $(LDFLAGS) $(SRCPATH1)/*.c
	$(CC) -o $(PREFIX)/$(EXE).elf $(LDFLAGS) $(SRCPATH1)/*.o $(LIBTOP)/STM32_USB-FS-Device_Lib_V4.0.0/libstm32.a
	$(OBJCOPY) -O ihex $(PREFIX)/$(EXE).elf $(PREFIX)/$(EXE).hex
	$(OBJCOPY) -O binary $(PREFIX)/$(EXE).elf $(PREFIX)/$(EXE).bin
	$(READELF) -a $(PREFIX)/$(EXE).elf > $(PREFIX)/$(EXE).info_elf
	$(SIZE) -d -B -t $(PREFIX)/$(EXE).elf > $(PREFIX)/$(EXE).info_size
	$(OBJDUMP) -S $(PREFIX)/$(EXE).elf > $(PREFIX)/$(EXE).info_code
	$(NM) -t x -S --numeric-sort -s $(PREFIX)/$(EXE).elf > $(PREFIX)/$(EXE).info_symbol
	@echo "done."
	
.PHONY: src clean 
clean:
	rm -f $(SRCPATH1)/*.o
	rm -f $(PREFIX)/*.elf 
	rm -f $(PREFIX)/*.hex
	rm -f $(PREFIX)/*.bin
	rm -f $(PREFIX)/*.info_elf
	rm -f $(PREFIX)/*.info_size
	rm -f $(PREFIX)/*.info_code
	rm -f $(PREFIX)/*.info_symbol

