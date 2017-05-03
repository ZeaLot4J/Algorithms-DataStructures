#include <stdio.h>
#include <stdlib.h>
/* 红黑树 */
typedef struct RBT{
    int data;
    struct RBT* left;
    struct RBT* right;
    struct RBT* parent;
    char color;
}RBT;
/* 红黑树的左旋，从右向左转 */
static RBT* leftRotation(RBT* root, RBT* node){
    RBT* t = node->right;
    if( (node->right = t->left) != NULL ){//如果node的右孩子为NULL
        node->right->parent = node;
    }
    t->left = node;

    if( (t->parent = node->parent) != NULL ){//如果node不是根
        if(node == node->parent->left)//如果node是父结点的左孩子
            node->parent->left = t;
        else if(node == node->parent->right)//如果node是父结点的右孩子
            node->parent->right = t;
    }else{                  //如果node就是根
        root = t;
    }
    node->parent = t;
    return root;
}
/* 红黑树的右旋，从左向右转 */
static RBT* rightRotation(RBT* root, RBT* node){
    RBT* t = node->left;
    if( (node->left = t->right) != NULL ){//如果node的左孩子为NULL
        node->left->parent = node;
    }
    t->right = node;

    if( (t->parent = node->parent) != NULL ){//如果node不是根
        if(node == node->parent->left)//如果node是父结点的左孩子
            node->parent->left = t;
        else if(node == node->parent->right)//如果node是父结点的右孩子
            node->parent->right = t;
    }else{                  //如果node就是根
        root = t;
    }
    node->parent = t;
    return root;
}
/* 二分搜索 */
static RBT* binarySearch0(RBT* root, int key){
    if(root == NULL)
        return NULL;
    if(key < root->data)
        return binarySearch0(root->left, key);
    else if(key > root->data)
        return binarySearch0(root->right, key);
    else
        return root;
}
/* 修复因插入新结点被破坏的红黑树 */
static RBT* insertFixUp(RBT* node, RBT* root){
    RBT *parent, *grandParent, *uncle, *tmp;
    //如果父结点是黑色的就是正常的红黑树不用管
    while( (parent=node->parent)!=NULL && parent->color=='r' ){
        grandParent = parent->parent;
        if(grandParent->left == parent){//如果父结点是祖父的左孩子
            uncle = grandParent->right; //则叔结点就是祖父的右孩子

            //(1)第一种情况，当前结点为红色，父和叔都为红色，此时
            //要把父和叔都变成黑色，祖父变成红色，之后迭代到祖父循环
            if( uncle!=NULL && uncle->color=='r'){
                uncle->color = 'b';
                parent->color = 'b';
                grandParent->color = 'r';
                node = grandParent;
            }else{//(2)如果叔结点没有，或者是第二种情况，当前结点为红色，父为红色，叔为黑色，
                  //此时要把父和叔都变成黑色，祖父变成红色，之后迭代到祖父循环
                if( node == parent->right){//如果当前结点是父结点的右孩子，要先转到左边去，原因是这样才能保证绝对符合红黑树
                    root = leftRotation(root, node);
                    tmp = parent;
                    parent = node;
                    node = tmp;//node和parent要交换一下
                }
                //再处理，最后一种情况，
                parent->color = 'b';
                grandParent->color = 'r';
                root = rightRotation(root, grandParent);
            }
        }else if(grandParent->right == parent){//如果父结点是祖父的右孩子
            uncle = grandParent->left;         //则叔结点就是祖父的左孩子
            if( uncle!=NULL && uncle->color=='r'){
                uncle->color = 'b';
                parent->color = 'b';
                grandParent->color = 'r';
                node = grandParent;
            }else{
                if( node == parent->left){//如果当前结点是父结点的左孩子，要先转到右边去，原因是这样才能保证绝对符合红黑树
                    root = rightRotation(root, node);
                    tmp = parent;
                    parent = node;
                    node = tmp;//node和parent要交换一下
                }
                //再处理，最后一种情况，
                parent->color = 'b';
                grandParent->color = 'r';
                root = leftRotation(root, grandParent);
            }
        }
    }

    root->color = 'b';//根一定要是黑色
    return root;
}
static void deleteFixUp(RBT *root, RBT *x)//删除黑色结点后，导致黑色缺失，违背性质4,故对树进行调整
{
    while( x != root && x->color == 'b' )  //如果x是红色，则直接把x变为黑色跳出循环，这样子刚好补了一重黑色,也满足了性质4
    {
        if( x == x->parent->left )     //如果x是其父结点的左子树
        {
            RBT *w=x->parent->right;       //设w是x的兄弟结点
            if( w->color == 'r' )         //case 1: 如果w的颜色为红色的话
            {
                w->color='b';
                x->parent->color='r';
                leftRotation(root, x->parent);
                w=x->parent->right;
            }
            if( w->left->color == 'b' && w->right->color == 'b' )   //case 2: w的颜色为黑色，其左右子树的颜色都为黑色
            {
                w->color='r';
                x=x->parent;
            }
            else if( w->right->color == 'b' )         //case 3: w的左子树是红色，右子树是黑色的话
            {
                w->color='r';
                w->left->color='b';
                rightRotation(root, w);
                w=x->parent->right;
            }
            w->color=x->parent->color;            //case 4: w的右子树是红色
            x->parent->color='b';
            w->right->color='b';
            leftRotation(root , x->parent);

            x=root;
        }
        else           //对称情况，如果x是其父结点的右子树
        {
            RBT *w=x->parent->left;
            if( w->color == 'r' )
            {
                w->color='b';
                x->parent->color='r';
                rightRotation(root, x->parent);
                w=x->parent->left;
            }
            if( w->left->color == 'b' && w->right->color == 'b' )
            {
                w->color='r';
                x=x->parent;
            }
            else if( w->left->color == 'b' )
            {
                w->color='r';
                w->right->color='b';
                leftRotation(root, w);
                w=x->parent->left;
            }
            w->color=x->parent->color;
            x->parent->color='b';
            w->left->color='b';
            rightRotation(root , x->parent);

            x=root;

        }
    }
    x->color='b';
}
RBT* insertNode(RBT* root, int data){
    RBT* newNode = (RBT*)malloc(sizeof(RBT));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->color = 'r';//新结点全部为红色
    if(root == NULL){//根为NULL直接返回新结点
        root = newNode;
        return root;
    }
    RBT* curr = root;
    RBT* pre;
    while(curr != NULL){
        pre = curr;
        if(data < curr->data)
            curr = curr->left;
        else if(data > curr->data)
            curr = curr->right;
    }
    if(data < pre->data){
        pre->left = newNode;
    }else if(data > pre->data){
        pre->right = newNode;
    }
    newNode->parent = pre;
    //以上插入新结点完成

    root = insertFixUp(newNode, root);
    return root;
}
static RBT* getMinimumNode(RBT* root){
    if(root == NULL || root->left == NULL)
        return root;
    return getMinimumNode(root->left);
}
void deleteNode(RBT* root, int data){
    RBT *curr = root;
    RBT *del, *parent, *child;
    while(curr != NULL){
        if(data < curr->data){
            curr = curr->left;
        }else if(data > curr->data){
            curr = curr->right;
        }else{
            break;
        }
    }
    if(curr == NULL) return;//没有找到


    if(curr->left!=NULL && curr->right!=NULL){//有左右孩子
        del = getMinimumNode(curr->right);//去右子树中找最大的结点
    }else{//有一个孩子或者一个也没有
        del = curr;
    }
    if(del->left!=NULL){
        child = del->left;
    }else if(del->right!=NULL){
        child = del->right;
    }
    parent = curr->parent;//parent有可能为NULL
    if(child!=NULL){
        child->parent = parent;
    }
    if(parent!=NULL){
        if(parent->left == del){
            parent->left = child;
        }else{
            parent->right = child;
        }
    }else{//parent为NULL说明删除的是根
        root = child;
    }
    if(del != curr){//如果要删除的结点不是原结点，就说明是有左右孩子的情况
        curr->data = del->data;

    }
    if(del->color == 'b'){//颜色如果是红色则不用考虑
        deleteFixUp(root, child);
    }
    free(del);
}
int main(){

    return 0;
}
