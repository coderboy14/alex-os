#ifndef MEMUTILS_H
#define MEMUTILS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void* memcpy(void *dest, const void * src, size_t n);
void* memset(void *dst,char val, int n);
int strcpy(char *dst,const char *src);


#endif