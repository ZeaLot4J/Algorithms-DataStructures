/*
*   Basic operations of Binary Tree:
*   1.Creating a Binary Tree.
*   2.Traversing a Binary Tree.
*   3.Getting the height of a Binary Tree.
*   4.Getting the number of the leaf node in a Binary Tree.
*   5.Inverting the Binary Tree.
*   6.Judging whether the Binary Tree is empty or not.
*   7.Clearing a Binary Tree.
*   8.Destroying a Binary Tree.
*   9.Getting the root of a Binary Tree.
*   10.Getting one node's parent node of a Binary Tree.
*/
#include <iostream>
#include <cstdlib>
#include <queue>//used for BFS
using namespace std;
typedef struct BiTreeNode{
    int data;
    struct BiTreeNode* lchild, * rchild;
}BiNode;
void CreateBiTree(BiNode* &T){
    int ival;
    cin >> ival;
    if(!ival) T = NULL;//if ival is 0, end this node.
    else{              //else, create the node
        T = new BiNode;
        if(!T){
            cerr << "Memory allocation failed!";
            exit(-1);
        }
        T->data = ival;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

int leafNode(BiNode* T)//get the number of leaf node
{
    if(!T)
        return 0;
    if(T->lchild==NULL && T->rchild==NULL)//is leaf node.
        return 1;
    return leafNode(T->lchild) + leafNode(T->rchild);
}
void preOrderTraverse(BiNode* T){
    if(T){
        cout << T->data << ' ';
        preOrderTraverse(T->lchild);
        preOrderTraverse(T->rchild);
    }
}
void inOrderTraverse(BiNode* T){
    if(T){
        inOrderTraverse(T->lchild);
        cout << T->data << ' ';
        inOrderTraverse(T->rchild);
    }
}
void postOrderTraverse(BiNode* T){
    if(T){
        postOrderTraverse(T->lchild);
        postOrderTraverse(T->rchild);
        cout << T->data << ' ';
    }
}
void levelOrderTraverse(BiNode* T){//by BFS
    queue<BiNode*> Q;
    if(!T) return;
    else{
        Q.push(T);
        while(!Q.empty()){
            if(T->lchild!=NULL) Q.push(T->lchild);
            if(T->rchild!=NULL) Q.push(T->rchild);
            cout << Q.front()->data << ' ';
            Q.pop();
            T = Q.front();
        }
    }
}

int height(BiNode* T){
    int hl, hr;
    if(!T) return 0;
    hl = height(T->lchild) + 1;
    hr = height(T->rchild) + 1;
    return hl > hr ? hl : hr;
}
int leaf(BiNode* T){
    if(!T) return 0;
    if(T->lchild==NULL && T->rchild==NULL){
        return 1;
    }
    return leaf(T->lchild)+leaf(T->rchild);
}
void invert(BiNode* T){
    BiNode* tmp;
    if(T){
        tmp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = tmp;
        invert(T->lchild);
        invert(T->rchild);
    }
}
//java，求树根的topview
void top_view(Node root){
    tool(root, 0);
}
void tool(Node root, int order){
    if(root!=null){
        if(order>=0)
            tool(root.left, 1);
        System.out.print(root.data+" ");
        if(order<=0)
            tool(root.right, -1);
    }
}
//BiNode* leftChild(BiNode* T, BiNode* p){
//    if(T==NULL) return NULL;
//    if(T==p)
//}
bool treeEmpty(BiNode* T){
    return T==NULL ? true : false;
}
void clearTree(BiNode* T){
    if(T){
        T->data = 0;
        clearTree(T->lchild);
        clearTree(T->rchild);
    }
}
void destroyTree(BiNode* &T){//good!
    if(T){
        destroyTree(T->lchild);
        destroyTree(T->rchild);
        delete T;
        T = NULL;
    }
}
BiNode* root(BiNode* T){
    return T;
}
bool isNodeInTree(BiNode* T, BiNode* p){

}
int main(){

    BiNode* T = NULL;
    CreateBiTree(T);
    preOrderTraverse(T);
    cout << endl;
    destroyTree(T);
    if(treeEmpty(T)) cout << "empty" << endl;
    else cout << "not empty" << endl;
    return 0;
}
