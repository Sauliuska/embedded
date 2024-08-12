CC=arm-none-eabi-gcc
MACHINE=cortex-m4
CFLAGS= -c -mcpu=$(MACHINE) -mthumb -std=gnu11 -Wall -O0
LDFLAGS= -nostdlib -T stm32_linker.ld -Wl,-Map=final.map

all:main.o led.o stm32_startup.o final.elf

main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@
	
led.o:led.c
	$(CC) $(CFLAGS) $^ -o $@
	
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@
	
final.elf:main.o led.o stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^
	
clean:
	 del /F /Q *.o *.elf
	 
load:
	openocd -f board/st_nucleo_f4.cfg