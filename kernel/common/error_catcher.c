#include "error_catcher.h"

#include "serialio.h"
#include "isr.h"

void _ec_println(char* str) {
    write_serial_string("[ERROR] ");
    writeln_serial_string(str);
}

void div_by_zero(register_t * reg) {
    _ec_println("DEVIDE BY ZERO");
}

void debug(register_t * reg) {
    _ec_println("DEBUG");
}

void bound_range_exceeded(register_t * reg) {
    _ec_println("BOUND_RANGE_EXCEEDED");
}

void invalid_opcode(register_t * reg) {
    _ec_println("INVALID OPCODE");
}

void device_not_available(register_t * reg) {
    _ec_println("DEVICE NOT AVAILABLE");
}

void double_fault(register_t * reg) {
    _ec_println("DOUBLE_FAULT");
}

void invalid_tss(register_t * reg) {
    _ec_println("INVALID TSS");
}

void segment_not_present(register_t * reg) {
    _ec_println("SEGMENT NOT PRESENT");
}

void stack_segment_fault(register_t * reg) {
    _ec_println("STACK SEGMENT FAULT");
}

void general_protection_fault(register_t * reg) {
    _ec_println("GENERAL PROTECTION FAULT");
}

void page_fault(register_t * reg) {
    _ec_println("PAGE FAULT");
}

void alignment_check(register_t * reg) {
    _ec_println("ALIGNMENT CHECK");
}

void machine_check(register_t * reg) {
    _ec_println("MACHINE CHECK");
}

void control_protection(register_t * reg) {
    _ec_println("CONTROL PROTECTION");
}

void vmm_coms(register_t * reg) {
    _ec_println("VMM COMMUNICATION EXCEPTION");
}

void security_exception(register_t * reg) {
    _ec_println("SECURITY EXCEPTION");
}

// Init method!
void ec_init() {
    _ec_println("Registering responders...");
    register_interrupt_handler(0x00, *div_by_zero);
    register_interrupt_handler(0x01, *debug);
    register_interrupt_handler(0x05, *bound_range_exceeded);
    register_interrupt_handler(0x06, *invalid_opcode);
    register_interrupt_handler(0x07, *device_not_available);
    register_interrupt_handler(0x08, *double_fault);
    register_interrupt_handler(0x0A, *invalid_tss);
    register_interrupt_handler(0x0B, *segment_not_present);
    register_interrupt_handler(0x0C, *stack_segment_fault);
    register_interrupt_handler(0x0D, *general_protection_fault);
    register_interrupt_handler(0x0E, *page_fault);
    register_interrupt_handler(0x11, *alignment_check);
    register_interrupt_handler(0x12, *machine_check);
    register_interrupt_handler(0x15, *control_protection);
    register_interrupt_handler(0x1D, *vmm_coms);
    register_interrupt_handler(0x1E, *security_exception);
    _ec_println("Error responders attached!");
}