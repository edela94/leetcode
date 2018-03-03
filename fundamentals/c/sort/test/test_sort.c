#include "unity.h"
#include "sort.h"

#define SMALL_ARRAY_SIZE 6

void setUp(void)
{
}

void tearDown(void)
{
}

void test_sort_bubble(void)
{
    uint32_t actual[SMALL_ARRAY_SIZE] = {5, 9, 1, 13, 18, 3};
    uint32_t expected[SMALL_ARRAY_SIZE] = {1, 3, 5, 9, 13, 18};

    bubble_sort((uint32_t*) &actual, SMALL_ARRAY_SIZE);

    print_array(actual, SMALL_ARRAY_SIZE);

    TEST_ASSERT_EQUAL_UINT32_ARRAY(expected, actual, SMALL_ARRAY_SIZE);
}
