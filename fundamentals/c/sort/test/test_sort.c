#include "unity.h"
#include "sort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_sort_NeedToImplement(void)
{
    uint32_t x = 12;
    uint32_t y = 42;
    swap(&x, &y);

    TEST_ASSERT(x == 42 && y == 12)
}
