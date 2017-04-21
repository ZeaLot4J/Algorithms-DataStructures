#include "AVL.h"

//最后试验一下把函数都改成static，在另一个文件中调用试一下

//使用这个方法来取一个结点所代表树的高度，而不直接->height是希望屏蔽掉NULL指针所带来的差异
int getHeight(Node* root){
    if(root!=NULL) return root->height;
    return -1;
}
Node* createNode(int data, Node* left, Node* right){
    Node* curr = NULL;
    if((curr = (Node*)malloc(sizeof(Node)))==NULL){
        printf("memory allocation error...\n");
        exit(1);
    }
    curr->data = data;
    curr->left = left;
    curr->right = right;
    curr->height = 0;
    return curr;
}
//左旋
static Node* LL(Node* root){
    Node* t = root->left;
    root->left = t->right;
    t->right = root;
    root->height = MAX(getHeight(root->left), getHeight(root->right)) + 1;
    t->height = MAX(getHeight(t->left), getHeight(t->right)) + 1;
    root = t;
    return root;
}
//右旋
static Node* RR(Node* root){
    Node* t = root->right;
    root->right = t->left;
    t->left = root;
    root->height = MAX(getHeight(root->left), getHeight(root->right)) + 1;
    t->height = MAX(getHeight(t->left), getHeight(t->right)) + 1;
    root = t;
    return root;
}
//LR
static Node* LR(Node* root){
    root->left = RR(root->left);
    return LL(root);
}
//RL
static Node* RL(Node* root){
    root->right = LL(root->right);
    return RR(root);
}
//插入  相同值无视
Node* insertNode(Node* root, int data){
    if(root == NULL)
        root = createNode(data, NULL, NULL);
    else if(data < root->data){
        root->left = insertNode(root->left, data);
        if(getHeight(root->left) - getHeight(root->right) == 2){//在左边插入只可能左边更高
            if(root->left->data > data)
                root = LL(root);
            else
                root = LR(root);
        }
    }else if(data > root->data){
        root->right = insertNode(root->right, data);
        if(getHeight(root->right) - getHeight(root->left) == 2){//在右边插入只可能左边更高
            if(root->right->data > data)
                root = RR(root);
            else
                root = RL(root);
        }
    }
    root = MAX(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}
//Morris Traversal 中序
void inOrder(Node* root){
    Node* curr = root;
    Node* pre = NULL;
    while(curr!=NULL){
        if(curr->left!=NULL){
            pre = curr->left;
            while(pre!=NULL && pre!=curr)
                pre = pre->right;
            if(pre == NULL){
                pre = curr;
                curr = curr->left;
            }else{//pre == curr
                pre = NULL;
                printf("%d ", curr->data);
                curr = curr->right;
            }
        }else{
            printf("%d ", curr->data);
            curr = curr->right;
        }
    }
}
int main(){
    int i, arr[] = {5, 2, 8, 4, 1, 9, 7, 6, 3};
    Node* root = NULL;
    for(i=0; i<9; i++){
        root = insertNode(root, arr[i]);
    }
    inOrder(root);
    return 0;
}

