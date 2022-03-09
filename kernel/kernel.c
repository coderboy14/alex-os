#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "system.h"
#include "vga.h"
#include "ata.h"
#include "pmm.h"
#include "kheap.h"
#include "pci.h"

void kernel_main(void)  {
    vga_initialize();
    vga_writestring("Starting...");

    kernel_init_main();

    // disk_test();
}

void kernel_init_main() {
    vga_writestring("Loading kernel...");
    pmm_init(1096 * M);
    paging_init();
    // kheap_init(KHEAP_START, KHEAP_START + KHEAP_INITIAL_SIZE, KHEAP_MAX_ADDRESS);
    // pci_init();
    // ata_init();
    vga_writestring("Kernel loaded!");
}

void disk_test(void) {
    vga_writestring("Running disktest...\n");
    ata_init();
}