#include <iostream>
using namespace std;

const int MAX = 100;
typedef struct
{
    char data[MAX];
    int top;
}Stack;
void initStack(Stack &S)
{
    S.top = 0;
}
bool empty(Stack &S)
{
    return !S.top ? true : false;
}
void push(Stack &S, char val)
{
    S.top++;
    S.data[S.top] = val;
}
bool pop(Stack &S, char *val)
{
    if(empty(S))
    {
        cout << "the stack is empty!" << endl;
        return false;
    }
    else
    {
        *val = S.data[S.top];
        S.top--;
        return true;
    }
}

void numConvert(Stack &S)
{
    char ch[] = "0123456789ABCDEF";
    int scale, num;

    cout << "please input the number: ";
    cin >> num;
    cout << "please input the scale: ";
    cin >> scale;

    while(num)
    {
        push(S, ch[num%scale]);
        num /= scale;
    }
}
int main()
{
    char ch;
    Stack S;
    initStack(S);
    numConvert(S);


    while(S.top)
    {
        pop(S, &ch);
        cout << ch;
    }
    cout << endl;
    return 0;
}
