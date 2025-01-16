#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *A = NULL; // to hold first node's adress

int main(void)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = 2;
    temp->next = NULL;
    A = temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = 4;
    temp->next = NULL;
    node *temp1 = A;
    temp1->next = temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = 6;
    temp->next = NULL;
    temp1 = temp1->next;
    temp1->next = temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = 8;
    temp->next = NULL;
    temp1 = temp1->next;
    temp1->next = temp;

    // lets print the list
    temp1 = A; // to go first node
    if (temp1 == NULL)
    {
        printf("List is empty");
        return -1;
    }
    while (temp1 != NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }

    return 0;
}
