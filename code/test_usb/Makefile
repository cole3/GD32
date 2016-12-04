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


TOP=$(PWD)
LIBTOP=$(TOP)/../libs
GD32LIB=$(LIBTOP)/GD32F10x_USB_FS_Device_Lib_V1.0.0
EXE=main

SRCPATH1=$(TOP)
PREFIX=$(TOP)

LDFLAGS=-g -mcpu=cortex-m3 -mthumb -O0 -fno-exceptions -ffunction-sections -fdata-sections
LDFLAGS+=-nostartfiles -Wl,--gc-sections,-Tlinker.ld
LDFLAGS+=-D GD32F10X_HD -D USE_GD32F103C_EVAL
LDFLAGS+=-L$(GD32LIB)
LDFLAGS+=-I$(GD32LIB)/Libraries/CMSIS \
		 -I$(GD32LIB)/Libraries/GD32F10x_StdPeriph_Driver/inc \
		 -I$(GD32LIB)/Utilities/GD32_EVAL/GD32103C_EVAL


all: src
src:
	@echo "Building $@ part1..."
	$(CC) -c $(LDFLAGS) $(SRCPATH1)/*.c
	$(CC) -o $(PREFIX)/$(EXE).elf $(LDFLAGS) $(SRCPATH1)/*.o $(GD32LIB)/libgd32all.a
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

