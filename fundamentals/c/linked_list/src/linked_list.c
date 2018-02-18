// linked_list.c
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

node createNode()
{
    // declare a node
    node temp;

    // allocate memory using malloc()
    temp = (node)malloc(sizeof(struct Node));

    // make next point to NULL
    temp->next = NULL;

    //return the new node
    return temp;
}

node addNode(node head, int value)
{
    // declare two nodes temp and p
    node temp, p;
    // createNode will return a new node with data = value and next pointing to NULL.
    temp = createNode();
    // add element's value to data part of node
    temp->data = value;
    // when linked list is empty
    if(head == NULL)
    {
        printf("Creating head! Value: %d\n", value);
        head = temp;
    }
    else
    {
        // assign head to p
        p  = head;
        while(p->next != NULL)
        {
            // traverse the list until p is the last node
            // the last node always points to NULL
            p = p->next;
        }
        // point the previous last node to the new node created
        printf("Adding to head! Value: %d\n", value);
        p->next = temp;
    }
    return head;
}

node deleteNode(node head, int value)
{
    node before;
    node current;

    before = head;
    current = head;

    // if the head contains the value
    if (current != NULL && current->data == value)
    {
        printf("Deleting head! Value: %d\n", value);
        head = head->next;
        free(current);
        return head;
    }

    // search nodes for value
    while (current != NULL && current->data != value )
    {
        before = current;
        current = current->next;
    }

    // if the value is not found
    if (current == NULL)
    {
        printf("Delete failed, value not found. Value: %d\n", value);
        return head;
    }

    // if it is found remove the node and free pointer
    printf("Deleting node. Value: %d\n", value);
    before->next = current->next;
    free(current);
    return head;
}

node deleteAll(node head)
{
    node current = head;
    node temp = head;

    printf("Deleting all nodes!\n");

    // delete all found nodes
    while (current != NULL) {
        temp = current;
        printf("Deleting node! Value: %d\n", temp->data);
        current = current->next;
        free(temp);
    }

    return head;
}

int printNodes(node head)
{
    node n;
    n = head;
    int count = 0;

    // if there are no nodes
    if (n->data == 0)
    {
        return 0;
    }

    // print contents of all found nodes
    while (n != NULL)
    {
        printf("Node: %d Value: %d\n", count, n->data);
        n = n->next;
        count++;
    }

    return count++;
}
