#include <stdio.h>
#include <stdlib.h>

typedef struct s
{
    int item;
    struct s *next;
} STACK;

STACK *sp = NULL;

int push(int item)
{
    STACK *p;
    p = (STACK *)malloc(sizeof(STACK));
    if (p == NULL)
    {
        printf("ERROR: no memory \n");
        return -1;
    }
    else
    {
        p->item = item;
        p->next = sp;
        sp = p;
        return 0;
    }
}

int pop()
{
    STACK *p;
    int i;
    if (sp == NULL)
    {
        printf("ERROR: Stack is empty \n");
        return -1;
    }

    else
    {
        p = sp;
        i = sp->item;
        sp = sp->next;
        free(p);
        return i;
    }
}

void reset()
{
    STACK *p;
    while (sp != NULL)
    {
        p = sp;
        sp = sp->next;
        free(p);
    }
}

STACK *top() //returns the address of the top element

{
    return sp;
}

int size()
{
    STACK *p;
    int i = 0;
    p = sp;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

int isEmpty()
{
    return sp == NULL;
}

//mainin yaz calsıtır
int main()
{

    return 0;
}