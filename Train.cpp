#include <iostream>
#include <string>
using namespace std;

const int MAXSIZE=100;
typedef struct
{
    char train[MAXSIZE];
    int top;
}Stack;
void initStack(Stack &S)
{
    S.top = -1;
}
bool empty(Stack &S)
{
    return S.top == -1 ? true : false;
}
void pushStack(Stack &S, char ch)
{
    S.top++;
    S.train[S.top] = ch;
}
void popStack(Stack &S, char *ch)
{
    if(empty(S))
    {
        cerr << "the stack is empty!" << endl;
        return;
    }
    *ch = S.train[S.top];
    S.top--;
}
char getTop(Stack &S)
{
    if(empty(S))
    {
        cerr << "the stack is empty!" << endl;
        return 0;
    }
    return S.train[S.top];
}

int main()
{
    Stack S;
    char ch;
    string train;
    initStack(S);

    cout << "please input the kind of carriage compartment(H/S): ";
    cin >> train;

    string::size_type pos = 0;
    pushStack(S, train[pos]);
    for(pos++; pos < train.size(); pos++)
    {
        if(getTop(S) == 'H')    pushStack(S, train[pos]);
        if(getTop(S) == 'S')
        {
            popStack(S, &ch);
            cout << ch;
            pushStack(S, train[pos]);
        }
    }
    while(!empty(S))
    {
        popStack(S, &ch);
        cout << ch;
    }
    cout << endl;

    return 0;
}
