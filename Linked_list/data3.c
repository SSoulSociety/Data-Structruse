#include <stdio.h>
#include <stdlib.h>

node *delete(int key); // Function prototype

typedef struct node
{
    int data;
    struct node *next;
} node;

node *first = NULL;
node *last = NULL; /* !!! her noda eklemene lazım normalde lasti ama eklemedım burda amacım amtıgını anlamak kodun*/


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

    return 0;
}

node *delete(int key)
{
    node *p = first;
    node *previous = NULL;

    // Search for the element to be deleted
    while (p)
    {
        if (key == p->data)
        {
            break;
        }
        previous = p;
        p = p->next;
    }

    // If the element was found
    if (p != NULL)
    {
        if (previous == NULL)
        {
            // If the first element is to be deleted
            if (first == last)
            {
                // If the list has only one element
                first = NULL;
                last = NULL;
            }
            else
            {
                first = first->next;
            }
        }
        // Delete from the middle or last
        else
        {

            previous->next = p->next;
            if (previous->next == NULL)
            {
                // If the last element is deleted
                last = previous;
            }
        }

        free(p);
        return p; // Return the node that was deleted
    }
    else
    {
        // If the node with the given key was not found
        return NULL;
    }
}