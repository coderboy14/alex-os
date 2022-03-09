/* Declare constants for the multiboot header. */
.set ALIGN,    1<<0             /* align loaded modules on page boundaries */
.set MEMINFO,  1<<1             /* provide memory map */
.set FLAGS,    ALIGN | MEMINFO  /* this is the Multiboot 'flag' field */
.set MAGIC,    0x1BADB002       /* 'magic number' lets bootloader find the header */
.set CHECKSUM, -(MAGIC + FLAGS) /* checksum of above, to prove we are multiboot */
 
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
 
.section data
.align 4096
.global TEMP_PAGE_DIRECTORY

.equ VM_BASE,        0xC0000000
.equ PDE_INDEX,      (VM_BASE >> 22)
.equ PSE_BIT,        0x00000010
.equ PG_BIT,         0x80000000

TEMP_PAGE_DIRECTORY:
    .word 0x00000083
    .rept (PDE_INDEX - 1)
        .byte   0
    .endr
    .word 0x00000083
    .rept (1024 - PDE_INDEX - 1)
        .byte   0
    .endr

.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:
 
.section .text

.global _start
.type _start, @function
_start:

    mov (TEMP_PAGE_DIRECTORY - VM_BASE), %ecx
    mov %ecx, %cr3

    mov %cr4, %ecx
    or PSE_BIT, %ecx
    mov %ecx, %cr4


    mov %cr0, %ecx
    or PG_BIT, %ecx
    mov %ecx, %cr0

    lea [higher_half], %ecx
    jmp higher_half

higher_half:
    mov $0, [TEMP_PAGE_DIRECTORY]
    invlpg 0
    mov $stack_top, %esp
	call kernel_main

loop:
    jmp loop
 
/*
Set the size of the _start symbol to the current location '.' minus its start.
This is useful when debugging or when you implement call tracing.
*/
.size _start, . - _start