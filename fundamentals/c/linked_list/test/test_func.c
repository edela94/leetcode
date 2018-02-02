#include "unity.h"
#include "func.h"
#include <stdbool.h>
#include "linked_list.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_func_NeedToImplement(void)
{
    node head;
    node node1;
    node node2;
    int ans;

    head->data = 6;
    head->next = node1;
    node1->data = 7;
    node1->next = node2;
    node2->data = 9;
    // ans = printNodes(head);

    TEST_ASSERT_EQUAL_INT(0, 0);
}
