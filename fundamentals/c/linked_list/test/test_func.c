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

    addNode(head, 6);
    addNode(head, 7);
    addNode(head, 9);

    TEST_ASSERT_EQUAL_INT(0, printNodes(head));
}
