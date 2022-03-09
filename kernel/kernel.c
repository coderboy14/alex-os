#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "system.h"
#include "vga.h"
#include "ata.h"
#include "pmm.h"
#include "kheap.h"
#include "pci.h"
#include "isr.h"

#include "serialio.h"
#include "error_catcher.h"

void kernel_main(void)  {
    vga_initialize();
    init_serial();

    writeln_serial_string("Starting kernel...");
    vga_writestring("Starting...");

    ec_init();
    kernel_init_main();

    // disk_test();
}

void kernel_init_main() {
    writeln_serial_string("Running KERNINIT_0...");
    vga_writestring("Loading kernel...");
    writeln_serial_string("Starting PMM...");
    pmm_init(1096 * M);
    writeln_serial_string("Starting paging...");
    paging_init();
    writeln_serial_string("Starting kheap...");
    // kheap_init(KHEAP_START, KHEAP_START + KHEAP_INITIAL_SIZE, KHEAP_MAX_ADDRESS);
    writeln_serial_string("Starting PCI...");
    // pci_init();
    writeln_serial_string("Starting ATA...");
    // ata_init();
    writeln_serial_string("Kernel stage-0 loaded!");
    vga_writestring("Kernel loaded!");
}

void disk_test(void) {
    vga_writestring("Running disktest...\n");
    ata_init();
}