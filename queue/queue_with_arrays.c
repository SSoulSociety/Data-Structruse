#include <stdio.h>

#define N 100
int Q[N];
int last = 0;

int enqueue(int item)
{
    if (last >= N)
    {
        printf("ERROR: queue is full.\n");
        return -1;
    }
    else
    {
        Q[last] = item;
        last++;
        return 0;
    }
}

int dequeue()
{
    int item;

    if (last == 0)
    {
        printf("Queue is empty\n");
        return -1; // if queue has positive values
    }
    else
    {
        item = Q[0];
        // shift left items in the queue by 1 position
        for (int i = 1; i < last; i++)
            Q[i - 1] = Q[i];
        last--;
        return item;
    }
}

void reset()
{
    last = 0;
}

int main(void)
{
    return 0;
}