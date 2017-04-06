#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node * pnext;
}LinkStack;
bool isEmpty(LinkStack* top)
{
    return top->pnext != NULL ? 0 : 1;
}

void InitStack(LinkStack *& top)
{
    top = new LinkStack;
    top->pnext = NULL;
}

void Push(LinkStack* top, int elem)
{
    LinkStack * pt;
    pt = new LinkStack;
    pt->pnext = top->pnext;
    top->pnext = pt;
    cout << "压栈：" << endl;
    pt->data = elem;
}

void Pop(LinkStack* top, int &elem)
{
    if(isEmpty(top))
    {
        cout << "empty." << endl;
        return;
    }
    LinkStack * tmp = top->pnext->pnext;
    elem = top->pnext->data;
    delete top->pnext;
    top->pnext = tmp;
}
void destroyStack(LinkStack* top){
    LinkStack* p, * pt;
    p = pt = top;
    while(p){
        pt = p;
        p = p->pnext;
        delete pt;
    }
    if(!p) cout << "栈已销毁" << endl;
}
void getTop(LinkStack* top, int &elem){
    if(isEmpty(top))
    {
        cout << "empty." << endl;
        return;
    }
    elem = top->pnext->data;
}
int main()
{
    LinkStack * sp;
    InitStack(sp);
    for(int i=0; i<100; i++)
    {
        Push(sp, i);
    }
    cout << "取元素： ";
    int tmp;
    while(sp->pnext)
    {
        Pop(sp, tmp);
        cout << tmp << endl;
    }
    destroyStack(sp);
    return 0;
}
