#include <stdio.h>

typedef struct q
{
    int item;
    struct q *next;
} QUEUE;

QUEUE *front = NULL;
QUEUE *last = NULL;

int enqueue(int item)
{
    QUEUE *p;
    p = (QUEUE *)malloc(sizeof(QUEUE));

    if (p == NULL)
    {
        printf("ERROR: memory is full");
        return -1;
    }
    else
    {
        p->item = item;
        p->next = NULL;
        if (front == NULL) // queue is empty
        {
            front = p;
            last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
        return 1;
    }
}

int dequeu()

{
    QUEUE *p;
    int item;
    if (front == NULL)
    {
        printf("ERROR: queue is empty");
        return -1;
    }
    else
    {
        p = front;
        front = front->next;
        if (front == NULL)
        {
            last = NULL;
        }
        else
        {
            // p->next= NULL; gerek yok buna zaten free(p) yapıyoruz.
            item = p->item;
            free(p);
            return item;
        }
    }
}

void reset()
{
    QUEUE *p;
    p = front;

    while (p)
    {
        front = front->next;
        free(p);
        p = front;
    }
    last = NULL;
}