#include <iostream>
#include <string>
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
bool comp(char a, char b)
{
    if(a == '(' && b == ')')
        return true;
    else if(a == '[' && b == ']')
        return true;
    else if(a == '{' && b == '}')
        return true;
    else
        return false;
}
void bracket(Stack S)
{
    string brac;
    char ch;
    cout << "please input the brackets: ";
    cin >> brac;


    for(string::size_type pos = 0; pos!=brac.size(); pos++)
    {
        switch(brac[pos])
        {
        case '(':
        case '[':
        case '{':
            push(S, brac[pos]);
            break;
        case ')':
        case ']':
        case '}':
            if(empty(S))
            {
                cout << "matching failed!" << endl;
                return;
            }
            pop(S, &ch);
            if(!comp(ch, brac[pos]))
            {
                cout << "matching failed!" << endl;
                return;
            }
            break;
        }
    }
    if(empty(S))
        cout << "success!" << endl;
    else
        cout << "matching failed!" << endl;
}
int main()
{
    Stack S;
    initStack(S);
    bracket(S);
    return 0;
}
