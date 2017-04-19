#include <iostream>
using namespace std;
const int MAX_SIZE = 1000;
typedef struct BiTreeNode{
    int data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiNode;
typedef struct Stack{
    int top;
    BiNode* elem[MAX_SIZE+1];
    int length;
    int size;
}Stack;
bool isEmpty(Stack &S){
    return S.length==0?true:false;
}
void initStack(Stack &S){
    S.top = 0;
    S.length = 0;
    S.size = MAX_SIZE;
}
void push(Stack &S, BiNode* T){
    if(S.length==S.size){
        cerr << "The current stack is full!" << endl;
        return;
    }
    S.top++;
    S.elem[S.top] = T;
    S.length++;
}
void pop(Stack &S){
    if(isEmpty(S)){
        cerr << "The current stack is empty!" << endl;
        return;
    }
    S.top--;
    S.length--;
}
void getTop(Stack &S, BiNode* &elem){
    if(isEmpty(S)){
        cerr << "The current stack is empty!" << endl;
        return;
    }
    elem = S.elem[S.top];
}
void CreateBiTree(BiNode*& T){
    int ival;
    cin >> ival;
    if(!ival) T = NULL;
    else{
        T = new BiNode;
        T->data = ival;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void preOrderTraverse(BiNode* T, Stack &S){
    while(!(T==NULL&&isEmpty(S))){
        while(T){
            cout << T->data << ' ';
            push(S, T);
            T = T->lchild;
        }
        getTop(S, T);
        pop(S);
        T = T->rchild;
    }
}
//前序遍历优化后的版本 java版 先压入右结点再压入左结点
void preOrder(Node root) {
    Deque<Node> stack = new ArrayDeque<Node>();
    stack.push(root);
    while(!stack.isEmpty()){
        root = stack.pop();   
        System.out.print(root.data+" ");
        if(root.right!=null) stack.push(root.right);
        if(root.left!=null) stack.push(root.left);
    }
}
//前序遍历的最佳版本，Morris Traversal，时间复杂度O(n)，空间复杂度O(1)
void preOrder(Node root) {
    Node pre = null;
    Node curr = root;
    while(curr != null){
        if(curr.left != null){
            pre = curr.left;
            while(pre.right!=null && pre.right!=curr){
                pre = pre.right;
            }
            if(pre.right==null){
                pre.right = curr;
                System.out.print(curr.data+" ");
                curr = curr.left;
            }else{//pre.right == curr
                pre.right = null;
                curr = curr.right;
            }
        }else{
            System.out.print(curr.data+" ");
            curr = curr.right;
        }
    }
}
void inOrderTraverse(BiNode* T, Stack &S){
    Stack S;
    initStack(S);
    while(!(T==NULL&&isEmpty(S))){
        while(T){
            push(S, T);
            T = T->lchild;
        }
        getTop(S, T);
        pop(S);
        cout << T->data << ' ';
        T = T->rchild;
    }
}
//中序遍历优化后的版本 java版 凭感觉
void inOrder(Node root) {
    Deque<Node> stack = new ArrayDeque<Node>();
    while(!stack.isEmpty() || root!=null){
        if(root!=null){
            stack.push(root);
            root = root.left;
        }else{
            root = stack.pop();
            System.out.print(root.data+" ");
            root = root.right;
        }
    }
}
//中序最佳版本，Morris Traversal，时间复杂度O(n)，空间复杂度O(1)
void inOrder(Node root) {
    Node pre = null;
    Node curr = root;
    while(curr != null){
        if(curr.left != null){
            pre = curr.left;
            while(pre.right!=null && pre.right!=curr){
                pre = pre.right;
            }
            if(pre.right==null){
                pre.right = curr;
                curr = curr.left;
            }else{//pre.right==curr
                pre.right = null;
                System.out.print(curr.data+" ");
                curr = curr.right;
            }
        }else{
            System.out.print(curr.data+" ");
            curr = curr.right;
        }
    }
}
/*
this traverse is pretty good !
the order of the stack pushing is right firstly, then left secondly.
*/
void postOrderTraverse(BiNode* T, Stack &S){
    BiNode* tmp = NULL;
    if(!T) return;
    push(S, T);
    while(!isEmpty(S)){
        getTop(S, T);
        if((T->lchild==NULL&&T->rchild==NULL)||((tmp!=NULL)&&(T->lchild==tmp||T->rchild==tmp))){
            cout << T->data << ' ';
            pop(S);
            tmp = T;
        }else{
            if(T->rchild!=NULL)
                push(S, T->rchild);
            if(T->lchild!=NULL)
                push(S, T->lchild);
        }
    }
}

int main(){
    Stack S;
    initStack(S);
    BiNode *T;
    CreateBiTree(T);
    preOrderTraverse(T, S);
    cout << endl;
    inOrderTraverse(T, S);
    cout << endl;
    postOrderTraverse(T, S);
    cout << endl;
    return 0;
}
