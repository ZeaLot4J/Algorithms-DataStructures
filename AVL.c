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
Node* getMinimumNode(Node* root){
    if(root == NULL || root->left == NULL)
        return root;
    return getMinimumNode(root->left);
}
Node* getMaximumNode(Node* root){
    if(root == NULL || root->right == NULL)
        return root;
    return getMaximumNode(root->right);
}
//插入  相同值无视
Node* insertNode(Node* root, int data){
    if(root == NULL)
        root = createNode(data, NULL, NULL);
    else if(data < root->data){
        root->left = insertNode(root->left, data);
        if(getHeight(root->left) - getHeight(root->right) == 2){//在左边插入只可能左边更高
            if(getHeight(root->left->left) > getHeight(root->left->right))//也可以比较高度，if(root->left->left的高度 ? root->left->right的高度)
                root = LL(root);
            else
                root = LR(root);
        }
    }else if(data > root->data){
        root->right = insertNode(root->right, data);
        if(getHeight(root->right) - getHeight(root->left) == 2){//在右边插入只可能右边更高
            if(getHeight(root->right->right) > getHeight(root->right->left))
                root = RR(root);
            else
                root = RL(root);
        }
    }
    root->height = MAX(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}
//删除结点
Node* deleteNode(Node* root, int data){
    Node* t = NULL;
    if(root==NULL)//空树
        return root;
    if(data < root->data){
        root->left = deleteNode(root->left, data);
        if(getHeight(root->right) - getHeight(root->left) == 2){//左边删除只可能是右边更高
            if(getHeight(root->right->right) > getHeight(root->right->left)){
                root = RR(root);
            }else{
                root = RL(root);
            }
        }
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
        if(getHeight(root->left) - getHeight(root->right) == 2){//右边删除只可能是左边更高
            if(getHeight(root->left->left) > getHeight(root->left->right)){
                root = LL(root);
            }else{
                root = LR(root);
            }
        }
    }else{//如果找到了
        if(root->left!=NULL && root->right!=NULL){//有左右孩子
            if(getHeight(root->left) > getHeight(root->right)){//去高度更高的子树找替代结点
                t = getMaximumNode(root->left);//去左子树找最大的
                root->data = t->data;
                root->left = deleteNode(root->left, t->data);
            }else{
                t = getMinimumNode(root->right);//去右子树找最小的
                root->data = t->data;
                root->right = deleteNode(root->right, t->data);
            }
        }else{//只有一个孩子或者没有孩子
            t = root;
            root = root->left != NULL ? root->left : root->right;
            free(t);
        }
    }
    if(root != NULL)
        root->height = MAX(getHeight(root->left), getHeight(root->right)) + 1;//更新高度
    return root;
}
Node* searchNode(Node* root, int data){
    if(root == NULL || root->data == data)
        return root;
    else if(root->data > data)
        return searchNode(root->left, data);
    else
        return searchNode(root->right, data);
}
//Morris Traversal 中序
void inOrder(Node* root){
    Node* curr = root;
    Node* pre = NULL;
    while(curr!=NULL){
        if(curr->left!=NULL){
            pre = curr->left;
            while(pre->right!=NULL && pre->right!=curr)
                pre = pre->right;
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }else{//pre == curr
                pre->right = NULL;
                printf("%d ", curr->data);
                curr = curr->right;
            }
        }else{
            printf("%d ", curr->data);
            curr = curr->right;
        }
    }
    printf("\n");
}
#include <windows.h>
int main(){
    int i;
    Node* root = NULL;
    while(1){
        system("cls");
        printf("1.插入元素\n");
        printf("2.删除元素\n");
        printf("3.求高度\n");
        printf("4.求最大值\n");
        printf("5.求最小值\n");
        inOrder(root);
        scanf("%d", &i);
        switch(i){
        case 1:
            printf("请输入待插入元素值:");
            scanf("%d", &i);
            root = insertNode(root, i);
            break;
        case 2:
            printf("请输入待删除元素值:");
            scanf("%d", &i);
            root = deleteNode(root, i);
            break;
        case 3:
            printf("%d\n", getHeight(root));
            getch();
            break;
        case 4:
            printf("%d\n", getMaximumNode(root)->data);
            getch();
            break;
        case 5:
            printf("%d\n", getMinimumNode(root)->data);
            getch();
            break;
        default:break;
        }
        //getch();
    }
    return 0;
}

