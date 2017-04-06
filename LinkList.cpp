#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef struct Node{
    int data;
    struct Node* pnext;
}Node;
void initLinkList(Node* &L){
    if((L = new Node)==NULL){
        cout << "Memory allocation failed!" << endl;
        exit(-1);
    }
    L->pnext = NULL;
}
void createLinkList(Node* L){
    Node* p = NULL;
    int data;
    cout << "please input datas: ";
    cin >> data;
    while(data!=0){
        if((p = new Node)==NULL){
            cout << "Memory allocation failed!" << endl;
            exit(-1);
        }
        p->pnext = L->pnext;
        L->pnext = p;
        p->data = data;
        cout << "please input datas: ";
        cin >> data;
    }
}
void traverseLinkList(Node* L){
    if(L==NULL){
        cout << "Not initialized" << endl;
        return;
    }
    Node* p = L->pnext;
    cout << "( ";
    while(p){
        cout << p->data << " ";
        p = p->pnext;
    }
    cout << ")";
}
void insertNode(Node* L, int pos, int data){
    Node* pt = L->pnext;
    Node* p = NULL;
    int j = 1;
    while(j!=pos&&pt!=NULL){
        p = pt;
        pt = pt->pnext;
        j++;
    }
    Node* q = new Node;
    q->data = data;
    p->pnext = q;
    q->pnext = pt;
}
void reverseLinkList(Node* L){//good!!!!!
    Node* p = L->pnext;
    Node* q = NULL;
    L->pnext = NULL;
    while(p){
        q = p;
        p = p->pnext;
        q->pnext = L->pnext;
        L->pnext = q;
    }
}
void MergeLinkList(Node* L1, Node* L2){
    Node* p1 = L1->pnext;
    Node* p2 = L2->pnext;
    Node* pre = L1;
    while(p1!=NULL&&p2!=NULL){
        if(p1->data>p2->data){
            pre->pnext = p1;
            pre = p1;
            p1 = p1->pnext;
        }else{
            pre->pnext = p2;
            pre = p2;
            p2 = p2->pnext;
        }
    }
    if(p1==NULL){
        pre->pnext = p2;
    }else{
        pre->pnext = p1;
    }
    delete L2;
}
void selectSort(Node* L){
    Node* p1 = NULL;
    Node* p2 = NULL;
    Node* pt = NULL;
    for(p1=L->pnext; p1!=NULL; p1=p1->pnext){
        pt = p1;
        for(p2=p1->pnext; p2!=NULL; p2=p2->pnext){
            if(p2->data<pt->data) pt = p2;
        }
        if(pt!=p1){
            int tmp = pt->data;
            pt->data = p1->data;
            p1->data = tmp;
        }
    }
}

int main(){
    Node* L1 = NULL;
    initLinkList(L1);
    createLinkList(L1);
    traverseLinkList(L1);
    cout << endl;
    selectSort(L1);
    traverseLinkList(L1);
    return 0;
}
