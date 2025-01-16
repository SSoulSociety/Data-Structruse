#include <stdio.h>
#define N 100
// to distungish between full and empty array we add a counter
int Q[N];
int last = 0, front = 0, counter = 0;

int enqueue(int item)
{
    if (counter >= N)
    {
        printf("Error: queue is full \n");
        return -1;
    }
    else
    {
        Q[last] = item;
        last = (last + 1) % N;
        counter++;
        return 0;
    }
}

int dequeue() // bu sefer her elemanı 1 kaydırmak yerine sadece firsti kaydırıyorız
{
    int item;
    if (counter <= 0)
    {
        printf("ERROR: queue is empty \n");
        return -1;
    }
    else
    {
        item = Q[front];
        front = (front + 1) % N;
        counter--;
        return item;
    }
}

void reset()
{
    counter = 0;
    front = 0;
    last = 0;
}

int main(void)
{

    return 0;
}