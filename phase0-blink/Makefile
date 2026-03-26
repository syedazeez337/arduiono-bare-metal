MCU     = atmega328p
F_CPU   = 16000000UL
CC      = avr-gcc
OBJCOPY = avr-objcopy
SIZE    = avr-size
OBJDUMP = avr-objdump
PORT    = /dev/ttyACM0
BAUD    = 115200
CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra -std=c11 -ffunction-sections -fdata-sections
LDFLAGS = -mmcu=$(MCU) -Wl,--gc-sections
TARGET  = main
SRC     = $(wildcard src/*.c)
OBJ     = $(SRC:src/%.c=build/%.o)

.PHONY: all flash clean disasm size

all: build/$(TARGET).hex

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c -o $@ $<

build/$(TARGET).elf: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

build/$(TARGET).hex: build/$(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: build/$(TARGET).hex
	avrdude -c arduino -p $(MCU) -P $(PORT) -b $(BAUD) -D -U flash:w:$<:i

size: build/$(TARGET).elf
	$(SIZE) --format=avr --mcu=$(MCU) $<

disasm: build/$(TARGET).elf
	$(OBJDUMP) -d -S $<

build:
	mkdir -p build

clean:
	rm -rf build
