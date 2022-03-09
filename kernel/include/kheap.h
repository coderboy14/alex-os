/*
 * kheap.h
 *
 * Copyright 2013 JS-OS <js@duck-squirell>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

// kheap.h -- Interface for kernel heap functions, also provides
//            a placement malloc() for use before the heap is
//            initialised.
//            Based on code from JamesM's kernel development tutorials.

#ifndef KHEAP_H
#define KHEAP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "system.h"

#define KHEAP_START         (void*)0xC0400000
#define KHEAP_INITIAL_SIZE  48 * M
#define KHEAP_MAX_ADDRESS   (void*)0xCFFFFFFF
#define HEAP_MIN_SIZE       4 * M

#define PAGE_SIZE 4096
#define OVERHEAD (sizeof(struct Block) + sizeof(unsigned int))


struct Block
{
    unsigned int size;
    struct Block * prev;
    struct Block * next;
};

void * kmalloc_cont(uint32_t sz, int align, uint32_t *phys);
uint32_t kmalloc_int(uint32_t sz, int align, uint32_t *phys);
void * kmalloc_a(uint32_t sz);
uint32_t kmalloc_p(uint32_t sz, uint32_t *phys);
uint32_t kmalloc_ap(uint32_t sz, uint32_t *phys);
void * kmalloc(uint32_t sz);
void *kcalloc(uint32_t num, uint32_t size);
void * krealloc(void * ptr, uint32_t size);
void kfree(void * ptr);
void kheap_init(void * start, void * end, void * max);
uint32_t getRealSize(uint32_t size);
void db_print();
int isEnd(struct Block * n);
int doesItFit(struct Block * n, uint32_t size);
void setFree(uint32_t *size, int x);
int isFree(struct Block * n);
void removeNodeFromFreelist(struct Block * x);
void addNodeToFreelist(struct Block * x);
struct Block * bestfit(uint32_t size);
struct Block * getPrevBlock(struct Block * n);
struct Block * getNextBlock(struct Block * n);
void *malloc(uint32_t size);
void free(void *ptr);
void *realloc(void *ptr, uint32_t size);

#endif // KHEAP_H