#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
}Node;

int getHeight(Node* root);                          //获取当前结点所代表的树的高度
Node* createNode(int data, Node* left, Node* right);//创建一个树结点
Node* getMaximumNode(Node* root);                     //取得树中值最大的结点
Node* getMinimumNode(Node* root);                     //取得树中值最小的结点
Node* insertNode(Node* root, int data);             //向树中插入新的结点
Node* deleteNode(Node* root, int data);             //从树中删除指定结点
void inOrder(Node* root);                           //中序遍历
Node* searchNode(Node* root, int data);             //根据值查找结点

#endif
