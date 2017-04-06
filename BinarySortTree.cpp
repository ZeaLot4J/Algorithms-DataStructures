#include <iostream>

using namespace std;

typedef struct BinarySortTreeNode
{
    int data;
    struct BinarySortTreeNode* lchild;
    struct BinarySortTreeNode* rchild;
}BST;


void inOrderTraverse(BST* T)
{
    if(T)
    {
        inOrderTraverse(T->lchild);
        cout << T->data << " ";
        inOrderTraverse(T->rchild);
    }
}void preOrderTraverse(BST* T)
{
    if(T)
    {
        cout << T->data << " ";
        preOrderTraverse(T->lchild);
        preOrderTraverse(T->rchild);
    }
}void postOrderTraverse(BST* T)
{
    if(T)
    {
        postOrderTraverse(T->lchild);
        postOrderTraverse(T->rchild);
        cout << T->data << " ";
    }
}
//非递归建立二叉排序树
void createBST(BST* &T, int ival)
{
    if(T==NULL)
    {
        T = new BST;
        T->data = ival;
        T->lchild = NULL;
        T->rchild = NULL;
        return;
    }
    if(ival <= T->data)
    {
        createBST(T->lchild,ival);
    }else
    {
        createBST(T->rchild,ival);
    }
}
int main()
{
    BST* T = NULL;
    int ia[] = {122,99,250,110,300,280};
    for(int i=0; i<6; i++)
    {
        createBST(T, ia[i]);
    }
    preOrderTraverse(T);
    cout << endl;
    inOrderTraverse(T);
    cout << endl;
    postOrderTraverse(T);
    cout << endl;
    return 0;
}
