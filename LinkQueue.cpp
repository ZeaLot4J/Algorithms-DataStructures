#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
    string data;
    struct node * pnext;
}Lnode;
typedef struct
{
    Lnode * front;
    Lnode * end;
}LinkQueue;

int empty(LinkQueue * LQ)
{
    return LQ->front == LQ->end ? 1 : 0;
}

void InitLinkQueue(LinkQueue * LQ)
{
    Lnode * pt;
    pt = new Lnode;
    pt->pnext = NULL;
    LQ->front = pt;
    LQ->end = pt;
}

void EnQueue(LinkQueue * LQ, string elem)
{
    Lnode * pt;
    pt = new Lnode;
    if(!pt)
    {
        cout << "内存分配失败。" << endl;
        return;
    }
    pt->data = elem;
    pt->pnext = LQ->end->pnext;
    LQ->end->pnext = pt;
    LQ->end = pt;
}
void OutQueue(LinkQueue * LQ, string * elem)
{
    if(empty(LQ))
    {
       cout << "队列已经是空的。" << endl;
       return;
    }

    Lnode * pt = LQ->front->pnext;
    LQ->front->pnext = pt->pnext;
    *elem = pt->data;
    delete pt;
    if(LQ->front->pnext==NULL)
    {
        LQ->end = LQ->front;
    }
}

void GetHead(LinkQueue * LQ, string * elem)
{
    if(empty(LQ))
    {
        cout << "队列已经是空的。" << endl;
        return;
    }
    *elem = LQ->front->pnext->data;
}

int main()
{
    LinkQueue LQ;
    InitLinkQueue(&LQ);
    EnQueue(&LQ, "zhang");
    EnQueue(&LQ, "lei");
    EnQueue(&LQ, "shi");
    EnQueue(&LQ, "hao");
    EnQueue(&LQ, "ren");

    string str;
    OutQueue(&LQ, &str);
    cout << str << endl;
    OutQueue(&LQ, &str);
    cout << str << endl;
    OutQueue(&LQ, &str);
    cout << str << endl;
    OutQueue(&LQ, &str);
    cout << str << endl;
    OutQueue(&LQ, &str);
    cout << str << endl;
    OutQueue(&LQ, &str);
    cout << str << endl;
    return 0;
}
