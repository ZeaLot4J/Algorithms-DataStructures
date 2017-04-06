#include <iostream>
using namespace std;

typedef struct DuLNode
{
    int data;
    struct DuLNode * prior;
    struct DuLNode * next;
}DuLNode, *DuLinkList;

DuLinkList CreatDuLinkList()
{
    int cnt = 0;
    cout << "please input the number of the Nodes you want to creat:";
    cin >> cnt;

    if(!cnt)
    {
        return NULL;
    }
    DuLinkList head = new DuLNode;
    DuLinkList p1 = head;
    for(int i=1; i<cnt; i++)
    {
        DuLinkList p2 = new DuLNode;
        p1->next = p2;
        p2->prior = p1;
        p1 = p1->next;
    }
    p1->next = head;
    head->prior = p1;

    return head;
}

void InputData(DuLinkList head)
{
    DuLinkList pt = head;
    if(!pt)
    {
        return;
    }
    cout << "please input datas:";
    cin >> pt->data;
    pt = pt->next;
    while(pt!=head)
    {
        cout << "please input datas:";
        cin >> pt->data;
        pt = pt->next;
    }
}
void DisplayData(DuLinkList head)
{
    DuLinkList pt = head;
    if(!pt)
    {
        return;
    }
    cout << pt->data << endl;
    pt = pt->next;
    while(pt!=head)
    {
        cout << pt->data << endl;
        pt = pt->next;
    }
}

int main()
{
    DuLinkList head1 = CreatDuLinkList();
    InputData(head1);
    DuLinkList head2 = CreatDuLinkList();
    InputData(head2);


    return 0;
}
