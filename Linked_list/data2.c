#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *first = NULL; // to hold first node's adress

node *search(int key); // Function prototype

int main(void)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = 2;
    temp->next = NULL;
    first = temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = 4;
    temp->next = NULL;
    node *temp1 = first;
    temp1->next = temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = 6;
    temp->next = NULL;
    temp1 = temp1->next;
    temp1->next = temp;

    node *found = search(5);
    if (found != NULL)
    {
        printf("Value %d found ", found->data );
    }
    else
    {
        printf("Value not found.\n");
    }

    return 0;
}

node *search(int key)
{
    node *p = first;
    while (p)
    {
        if (p->data == key)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}
