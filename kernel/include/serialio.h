#ifndef SERIALIO_H
#define SERIALIO_H

int init_serial();
// int sio_serial_received();
// char sio_read_serial()
// int sio_is_transmit_empty();
void write_serial(char a);
void write_serial_string(char* str);
void writeln_serial_string(char* str);

#endif