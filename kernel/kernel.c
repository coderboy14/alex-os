#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "system.h"
#include "vga.h"
#include "ata.h"

void kernel_main(void)  {
    vga_initialize();
    //vga_writestring("Starting system...\n");
    disk_test();
}

void disk_test(void) {
    vga_writestring("Running disktest...\n");
    ata_init();
}