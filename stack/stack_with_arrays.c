#include <stdio.h>

#define N 100
int S[N];
int sp = 0;

int push(int item)
{
    if (sp >= N)
    {
        printf("ERROR: Stack is full\n");
        return -1;
    }
    else
    {
        S[sp] = item;
        sp++;
        return 0;
    }
}

int pop()
{
    if (sp <= 0)
    {
        printf("ERROR: Stack is empty \n");
        return -1;
    }
    else
    {
        sp--;
        return S[sp];
    }
}

int top()
{
    return sp - 1;
}

int size()
{
    return sp;
}

int isEmpty()
{
    if (sp == 0)
        return 1;
    else
        return 0;
}

int main()
// Reading a line of text and writing it out backwards.
{
    char c;
    printf("Bir metin girin: ");
    while ((c = getchar()) != '\n')
    {
        push(c);
    }

    printf("Metnin tersi: ");
    while (sp > 0)
    {
        printf("%c", pop());
    }

    printf("\n");

    return 0;
}