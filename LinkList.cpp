#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* 不使用辅助头结点的单链表 */
typedef struct Node{
    int data;
    struct Node* next;
}Node;
/* 打印链表 */
void print(Node* head) {
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* 尾插 */
Node* insert1(Node* head,int data) {
    Node* curr = head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(curr==NULL){
        head = newNode;
    }else{
        while(curr->next!=NULL)
            curr = curr->next;
        curr->next = newNode;
    }
    return head;
}
/* 头插法 */
Node* insert2(Node* head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}
Node* create(){
    int val;
    Node* head = NULL;
    printf("请输入数值:");
    while(1){
        scanf("%d", &val);
        if(val==0) break;
        head = insert1(head, val);
    }
    return head;
}
/* 转置链表 递归法 */
Node* reverse1(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;
    Node* remaining = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    return remaining;
}
/* 转置链表 迭代法 */
Node* reverse2(Node* head){
    Node* p = head;
    Node* q = NULL;
    head = NULL;
    while(p){
        q = p;
        p = p->next;
        q->next = head;
        head = q;
    }
    return head;
}
/* 合并两个有序链表，迭代方式 */
Node* merge1(Node *headA, Node* headB){
    Node* ta = headA;
    Node* tb = headB;
    Node* pre = (Node*)malloc(sizeof(Node));
    Node* t = pre;
    while(headA!=NULL && headB!=NULL){
        if(headA->data < headB->data){
            pre->next = headA;
            pre = pre->next;
            headA = headA->next;
        }else{
            pre->next = headB;
            pre = pre->next;
            headB = headB->next;
        }
    }
    if(headA==NULL)
        pre->next = headB;
    else
        pre->next = headA;
    if(t->next == ta){
        free(t);
        return ta;
    }else{
        free(t);
        return tb;
    }
}
/* 合并两个有序链表，递归方式，没有无用的头结点 */
Node* merge2(Node* headA, Node* headB){
    if(headA == NULL) return headB;
    if(headB == NULL) return headA;
    if(headA->data < headB->data){
        headA->next = merge2(headA->next, headB);
        return headA;
    }else{
        headB->next = merge2(headA, headB->next);
        return headB;
    }
}
/* 获取断链位置 */
static Node* getMidPos(Node* head){
    if(head==NULL || head->next==NULL)
        return head;
    Node* quick, *slow, *pre;
    pre = quick = slow = head;
    while(quick!=NULL && quick->next!=NULL){
        quick = quick->next->next;
        pre = slow;
        slow = slow->next;
    }
    return pre;
}
//
static Node* mergeSort(Node* head){
    if(head==NULL || head->next==NULL)//head只有在链表本身为空时等于NULL
        return head;
    if(head!=NULL && head->next!=NULL){//5 3 7 1 4 2 9 6 8
        Node* mid = getMidPos(head);
        Node* head2 = mid->next;
        mid->next = NULL;
        head = mergeSort(head);
        head2 = mergeSort(head2);
        return merge2(head, head2);
    }
}
void selectSort(Node* L){
    Node* p1 = NULL;
    Node* p2 = NULL;
    Node* pt = NULL;
    for(p1=L->next; p1!=NULL; p1=p1->next){
        pt = p1;
        for(p2=p1->next; p2!=NULL; p2=p2->next){
            if(p2->data<pt->data) pt = p2;
        }
        if(pt!=p1){
            int tmp = pt->data;
            pt->data = p1->data;
            p1->data = tmp;
        }
    }
}

int main(){//5 3 6 1 8 7 9 2 4
    Node* head = create();
    print(head);
    head = mergeSort(head);
    print(head);
    return 0;
}
