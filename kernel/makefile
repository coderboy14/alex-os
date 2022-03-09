# Get paths
mkfile_path:=$(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
ROOT:=$(realpath $(mkfile_dir))
BUILD:=$(ROOT)/build

# Define sources and objects
C_SOURCES := kernel.c ui/vga.c drivers/ata.c drivers/pci.c common/port_io.c common/memutils.c core/kheap.c core/isr.c core/paging.c core/system.c core/pmm.c core/pic.c
# ASM_SOURCES := 
NASM_SOURCES := boot.s

INCLUDE_PATH := include
OBJECTS=$(C_SOURCES:.c=.o) $(NASM_SOURCES:.asm=.o)
OBJDIRS := $(patsubst %, $(OBJDIR)/%, $(MODULES))

# Define compiler
CC_PATH=$(HOME)/opt/cross/bin
ARCH=i686

# Define compiler options
COMPILE_OPTIONS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LINK_OPTIONS=-ffreestanding -O2 -nostdlib -lgcc
NASM=nasm
NASMFLAGS=-f elf32 -O0

# Define tools
ASSEMBLER=$(CC_PATH)/i686-elf-as
COMPILER=$(CC_PATH)/i686-elf-gcc

# File targets
%.o: %.c
	$(COMPILER) -I $(INCLUDE_PATH) $(COMPILE_OPTIONS) -c $< -o $@
%.o: %.s
	$(ASSEMBLER) $< -o $@
%.o: %.asm
	$(NASM) $(NASMFLAGS) $(ROOT)/$< -o $@

kernel.img: $(OBJDIRS) $(OBJECTS)
	$(COMPILER) -T "$(ROOT)/linker.ld" -o "$(ROOT)/kernel.img" $(LINK_OPTIONS) $(OBJECTS)

os.iso: kernel.img
	echo "TO DO"
#grub-mkrescue -o os.iso $(DISK_IMG_WORKDIR)

# Named targets
kernel: $(OBJECTS)

all: kernel.img

clean:
	rm -rf $(OBJECTS) kernel.img