#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdint.h>

void bubble_sort(uint32_t* buffer, uint32_t len);
void insertion_sort(uint32_t* buffer, uint32_t len);
void merge_sort(uint32_t* buffer, uint32_t len);
void quick_sort(uint32_t* buffer, uint32_t len);
void heap_sort(uint32_t* buffer, uint32_t len);
void counting_sort(uint32_t* buffer, uint32_t len);

// TODO: declare swap as static after verifying
void swap(uint32_t* a, uint32_t* b);

#endif // _LINKED_LIST_H
