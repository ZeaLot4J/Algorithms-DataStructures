#include <iostream>
#define MaxSize 10
using namespace std;

typedef struct
{
    int data[MaxSize];
    int front, rear;
}Looque;

bool empty(Looque * LQ)
{
    return LQ->rear == LQ->front ? true : false;
}

bool full(Looque * LQ)
{
    return (LQ->rear+1)%MaxSize == LQ->front ? true : false;
}

void InitQueue(Looque * LQ)
{
    LQ->front = 0;
    LQ->rear = 0;
}

void EnQueue(Looque * LQ, int elem)
{
    if(full(LQ))
    {
        cout << "the queue is full!" << endl;
        return;
    }
    LQ->rear = (LQ->rear+1)%MaxSize;
    LQ->data[LQ->rear] = elem;
}

void OutQueue(Looque * LQ, int * elem)
{
    if(empty(LQ))
    {
        cout << "the queue is empty!" << endl;
        return;
    }
    LQ->front = (LQ->front+1)%MaxSize;
    *elem = LQ->data[LQ->front];
}

void Getfront(Looque * LQ, int * elem)
{
    if(empty(LQ))
    {
        cout << "the queue is empty!" << endl;
        return;
    }
    *elem = LQ->data[(LQ->front+1)%MaxSize];
}

int main()
{
    Looque LQ;
    InitQueue(&LQ);

    for(int i=0; i<8; i++)
    {
        EnQueue(&LQ, i);
    }

    int tmp;
    OutQueue(&LQ, &tmp);
    OutQueue(&LQ, &tmp);
    OutQueue(&LQ, &tmp);

    EnQueue(&LQ, 13);
    EnQueue(&LQ, 14);
    EnQueue(&LQ, 15);

    OutQueue(&LQ, &tmp);
    OutQueue(&LQ, &tmp);
    OutQueue(&LQ, &tmp);

    while(!empty(&LQ))
    {
        OutQueue(&LQ, &tmp);
        cout << tmp << ' ';
    }
    return 0;
}
