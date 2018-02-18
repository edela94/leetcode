#include "unity.h"
#include "func.h"
#include <stdbool.h>
#include <stdio.h>
#include "linked_list.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_func_add(void)
{
    node head = NULL;
    head = addNode(head, 6);
    head = addNode(head, 7);
    head = addNode(head, 9);

    TEST_ASSERT_EQUAL_INT(3, printNodes(head));

    printf("Testing delete!\n");
    head = deleteAll(head);
    TEST_ASSERT_EQUAL_INT(0, printNodes(head));
}

void test_func_delete(void)
{

}
