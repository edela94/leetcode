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
    if(head == NULL){
        head = temp;
    }
    else{
        // assign head to p
        p  = head;
        while(p->next != NULL)
        {
            // traverse the list until p is the last node
            // the last node always points to NULL
            p = p->next;
        }
        // point the previous last node to the new node created
        p->next = temp;
    }
    return head;
}

int printNodes(node head)
{
    node n;
    n = head;
    int count = 0;
    while (n != NULL)
    {
        printf("Node: %d Value: %d\n", count, n->data);
        n = n->next;
        count++;
    }
    return count++;
}
