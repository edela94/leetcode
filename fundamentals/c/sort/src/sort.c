#include "sort.h"

#include <stdio.h>

static void swap(uint32_t* a, uint32_t* b);

static void swap(uint32_t* a, uint32_t* b)
{
    uint32_t temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(uint32_t* buffer, uint32_t len)
{
    printf("Array: ");
    for(int i=0;i<len;i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void bubble_sort(uint32_t* buffer, uint32_t len)
{
    uint32_t i;
    uint32_t j;

    // loop through each element
    for(i=0;i<len-1;i++)
    {
        // compare with each element
        for (j=0;j<(len-i-1);j++)
        {
            // switch if greater
            if (*(buffer+j) > *(buffer+j+1))
            {
                swap(buffer+j, buffer+j+1);
            }
        }
    }
}
