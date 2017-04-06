#include <iostream>
#define MaxSize 100
using namespace std;


typedef struct
{
    char data[MaxSize];
    int top;
}Stack;

void InitStack(Stack * S)
{
    S->top = -1;
}
int Empty(Stack * S)
{
    return S->top < 0 ? 1 : 0;
}
int Full(Stack * S)
{
    return S->top >= MaxSize - 1 ? 1 : 0;
}
int Push(Stack * S, char elem)
{
    if(Full(S))
    {
        cout << "Error!The stack is full!" << endl;
        return 0;
    }

    S->top++;
    S->data[S->top] = elem;
    return 1;
}
int Pop(Stack * S, char * x)
{
    if(Empty(S))
    {
        cout << "Error!The stack is empty!" << endl;
        return 0;
    }
    *x = S->data[S->top];
    S->top--;
    return 1;
}
int GetTop(Stack * S, char * x)
{
    if(Empty(S))
    {
        cout << "Error!The stack is empty!" << endl;
        return 0;
    }

    *x = S->data[S->top];
    return 1;
}
int main()
{
    Stack S;
    char e;
    InitStack(&S);

    cout << "栈";
    if(Empty(&S))
        cout << "空" << endl;
    else
        cout << "非空" << endl;
    cout << " a进栈" << endl; Push(&S, 'a');
    cout << " b进栈" << endl; Push(&S, 'b');
    cout << " c进栈" << endl; Push(&S, 'c');
    cout << " d进栈" << endl; Push(&S, 'd');
    cout << " 栈";
    if(Empty(&S))
        cout << "空" << endl;
    else
        cout << "非空" << endl;
    GetTop(&S, &e);
    cout << "栈顶元素" << e << endl;
    cout << "出栈次序:";
    while(!Empty(&S))
    {
        Pop(&S, &e);
        cout << e;
    }
    cout << endl;


    return 0;
}
