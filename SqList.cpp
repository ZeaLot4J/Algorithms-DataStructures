#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

const int MAXSIZE = 100;
const int ADDSIZE = 10;
typedef struct
{
    int *elem;
    int length;
    int size;
}SqList;

void initList(SqList &);				//初始化顺序表
int listLen(SqList &);					//取表的长度
int locate(SqList &, int);				//查找值的下标
void insertList(SqList &, int, int);	//在给定位置插入数值
void deleteElem(SqList &, int);			//删除给定值
void display(SqList &);					//打印顺序表
void priorElem(SqList &, int, int &);	//取给定值的前一个值
void nextElem(SqList &, int, int &);	//取给定值的后一个值
void destroyList(SqList &);				//销毁顺序表
void reallocList(SqList &);				//扩大顺序表的空间
void test_1(SqList &);					//删除下标为3的倍数的元素
bool test_2(SqList &);                  //判断是否对称
void test_3(SqList &);                  //将奇数放在偶数前面
int  main()
{
    SqList sl;
	initList(sl);
	cout << "请输入元素个数:";
	int n, elem;
	cin >> n;
	cout << "请输入" << n << "个元素:";
	for(int i=0; i<n; i++)
	{
		cin >> elem;
		insertList(sl, i, elem);
	}
	display(sl);
	if(test_2(sl)==true)
		cout << "对称" << endl;
	else
		cout << "不对称" << endl;

    test_3(sl);
    display(sl);
    return 0;
}
void test_3(SqList &sq)
{
    int *p1 = sq.elem;
    int *p2;
    int tmp;
    for(;; p1++)
    {
        if(*p1%2==0)   //如果是偶数
        {
            for(p2 = p1 + 1; *p2%2==0; p2++);
            if(p2>=sq.elem+sq.length) break;
            tmp = *p1;
            *p1 = *p2;
            *p2 = tmp;
        }
    }
}
bool test_2(SqList &sq)
{
	int *p1 = sq.elem;
	int *p2 = sq.elem+sq.length-1;
	while(p1<p2)
	{
		if(*p1==*p2) {p1++;p2--;}
		else return false;
	}
	return true;
}

void test_1(SqList &sq)
{
	for(int i=0; i<sq.length; i+=2)
			deleteElem(sq, i);
}
void initList(SqList &sq)
{
    sq.elem = (int*)malloc(MAXSIZE*sizeof(int));
    if(!sq.elem)
    {
        cerr << "Initialization failed!" << endl;
        exit(0);
    }
    sq.length = 0;
    sq.size = MAXSIZE;
}
int listLen(SqList &sq)
{
    return sq.length;
}
int locate(SqList &sq, int val)
{
    for(int i=0; i<sq.length; i++)
    {
        if(sq.elem[i] == val)
        {
            cout << "the element is [" << i << "]"<< endl;
            return i;
        }
    }
    return -1;
}
void insertList(SqList &sq, int i, int val)
{
    if(i<0 || i>sq.length)
        return;
    if(sq.length == sq.size)
    {
        reallocList(sq);
    }


    for(int k=sq.length-1; k>=i; k--)
        sq.elem[k+1] = sq.elem[k];
    sq.elem[i] = val;
    sq.length++;
}
void display(SqList &sq)
{
    if(!(sq.length))
    {
        cout << "empty!"<< endl;
        return;
    }
    for(int i=0; i<sq.length; i++)
        cout << sq.elem[i] << ' ';

    cout << "the current length is:" << sq.length << endl;
}
void deleteElem(SqList &sq, int i)
{
    if(sq.length == 0)
        return;
    if(i<0 || i>=sq.length)
        return;
    cout << "the value you delete is: " << sq.elem[i] << endl;
    for(int k=i+1; k<sq.length; k++)
        sq.elem[k-1] = sq.elem[k];
    sq.length--;
}
void priorElem(SqList &sq, int val, int &pre)
{
    if(sq.length==0)
        return;
    int flag = locate(sq, val);
    if(flag == -1 || flag == 0)
    {
        cerr << "the prior value cannot found!" << endl;
        pre = -1;
    }
    else
        pre = sq.elem[flag-1];
}
void nextElem(SqList &sq, int val, int &next)
{
    if(sq.length==0)
        return;
    int flag = locate(sq, val);
    if(flag == -1 || flag == sq.length-1)
    {
        cerr << "the prior value cannot found!" << endl;
        next = -1;
    }
    else
        next = sq.elem[flag+1];
}
void destroyList(SqList &sq)
{
    delete sq.elem;
    sq.elem = NULL;
    sq.length = 0;
    sq.size = 0;
}
void reallocList(SqList &sq)
{
    int *pt = new int(sq.size+ADDSIZE);
    if(!pt)
    {
        cerr << "error!" << endl;
        exit(-1);
    }
    for(int i=0; i<sq.length; i++)
        pt[i] = sq.elem[i];
    delete sq.elem;
    sq.elem = pt;
    sq.size += ADDSIZE;
}
