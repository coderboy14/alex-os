#include "memutils.h"

void* memcpy(void *dst, const void * src, size_t n) {
    char * ret = dst;
    char * p = dst;
    const char * q = src;
    while (n--)
        *p++ = *q++;
    return ret;
}

void* memset(void *dst,char val, int n) {
    char *temp = dst;
    for(;n != 0; n--) *temp++ = val;
    return dst;
}

int strcpy(char *dst,const char *src) {
    int i = 0;
    while ((*dst++ = *src++) != 0)
        i++;
    return i;
}