#include <iostream>
#include <cstdlib>
#define MAXSIZE 100
using namespace std;
/*
    可以输入０~９之间的数，进行表达式加减乘除运算
*/
typedef struct iStack
{

    int data[MAXSIZE];
    int top;
}iStack;
typedef struct cStack
{

    char data[MAXSIZE];
    int top;
}cStack;
void InitStack(iStack &S)
{
    S.top = -1;
}
void InitStack(cStack &S)
{
    S.top = -1;
}
int empty(iStack &S)
{
    return S.top == -1 ? 1 : 0;
}
int empty(cStack &S)
{
    return S.top == -1 ? 1 : 0;
}
void PushStack(cStack &S, char ch)
{
    S.top++;
    S.data[S.top] = ch;
}
void PushStack(iStack &S, int elem)
{
    S.top++;
    S.data[S.top] = elem;
}
char PopStack(cStack &S)
{
    char tmp;
    if(empty(S))
    {
        cerr << "stack is empty!" << endl;
        exit(-1);
    }
    tmp = S.data[S.top];
    S.top--;
    return tmp;
}
int PopStack(iStack &S)
{
    int tmp;
    if(empty(S))
    {
        cerr << "stack is empty!" << endl;
        exit(-1);
    }
    tmp = S.data[S.top];
    S.top--;
    return tmp;
}
char GetStackTop(cStack &S)
{
    char tmp;
    if(empty(S))
    {
        cerr << "stack is empty!" << endl;
        exit(-1);
    }
    tmp = tmp = S.data[S.top];
    return tmp;
}
int GetStackTop(iStack &S)
{
    int tmp;
    if(empty(S))
    {
        cerr << "stack is empty!" << endl;
        exit(-1);
    }
    tmp = tmp = S.data[S.top];
    return tmp;
}
char OperCompare(char oper1, char oper2)//oper1 is the top element
{
    char r;
    switch(oper2)
    {
    case '+':
    case '-':
        if(oper1=='(' || oper1=='#')
            r = '<';
        else
            r = '>';
        break;
    case '*':
    case '/':
        if(oper1=='*' || oper1=='/' || oper1==')')
            r = '>';
        else
            r = '<';
        break;
    case '(':
        if(oper1==')')
        {
            cerr << "error!" << endl;
            exit(-1);
        }
        else
            r = '<';
        break;
    case ')':
        if(oper1=='#')
        {
            cerr << "error!" << endl;
            exit(-1);
        }
        else if(oper1=='(')
            r = '=';
        else
            r = '>';
        break;
    case '#':
        if(oper1=='(')
        {
            cerr << "error!" << endl;
            exit(-1);
        }
        else
            r = '>';
        break;
    default:
        cerr << "input error!" << endl;
        exit(-1);
    }
    return r;
}
int Operation(int left, char ch, int right)
{
    int result;
    switch(ch)
    {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        if(0==right)
        {
            cerr << "division error!" << endl;
            exit(-1);
        }
        result = left / right;
        break;
    default:
        cerr << "error!" << endl;
        exit(-1);
    }
    return result;
}
int ExpressionCalc()
{
    char ch;
    int left, right;
    char oper;
    iStack operation;
    cStack operand;                     //operation是操作数，operand是运算符
    InitStack(operation);
    InitStack(operand);
    operand.top++;
    operand.data[operand.top] = '#';

    cin >> ch;
    while(!(ch=='#' && GetStackTop(operand) == '#'))
    {
        if(ch>='0' && ch<='9')
        {
            PushStack(operation, ch-48);
            cin >> ch;
        }
        else
        {
            switch(OperCompare(GetStackTop(operand), ch))
            {
            case '<':
                PushStack(operand, ch);
                cin >> ch;
                break;
            case '=':
                PopStack(operand);
                cin >> ch;
                break;
            case '>':
                oper = PopStack(operand);
                right = PopStack(operation);
                left = PopStack(operation);
                PushStack(operation, Operation(left, oper, right));

            }
        }
    }
    return GetStackTop(operation);
}
int main()
{
    while(1)
    {
        cout << "请输入表达式（以#结束）：" << endl;
        cout << ExpressionCalc() << endl;
    }



    return 0;
}
