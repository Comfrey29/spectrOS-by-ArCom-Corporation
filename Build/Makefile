CC = gcc
LD = ld
CFLAGS = -ffreestanding -fno-pie -m64 -nostdlib -Wall -Wextra

all: kernel.elf

kernel.o: kernel.c
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o

kernel.elf: kernel.o linker.ld
	$(LD) -T linker.ld -o kernel.elf kernel.o

run: kernel.elf
	qemu-system-x86_64 -kernel kernel.elf -serial stdio

clean:
	rm -f *.o *.elf
