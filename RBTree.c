#include <stdio.h>
#include <stdlib.h>
/* ����� */
typedef struct RBT{
    int data;
    struct RBT* left;
    struct RBT* right;
    struct RBT* parent;
    char color;
}RBT;
/* ���������������������ת */
static RBT* leftRotation(RBT* root, RBT* node){
    RBT* t = node->right;
    if( (node->right = t->left) != NULL ){//���node���Һ���ΪNULL
        node->right->parent = node;
    }
    t->left = node;

    if( (t->parent = node->parent) != NULL ){//���node���Ǹ�
        if(node == node->parent->left)//���node�Ǹ���������
            node->parent->left = t;
        else if(node == node->parent->right)//���node�Ǹ������Һ���
            node->parent->right = t;
    }else{                  //���node���Ǹ�
        root = t;
    }
    node->parent = t;
    return root;
}
/* ���������������������ת */
static RBT* rightRotation(RBT* root, RBT* node){
    RBT* t = node->left;
    if( (node->left = t->right) != NULL ){//���node������ΪNULL
        node->left->parent = node;
    }
    t->right = node;

    if( (t->parent = node->parent) != NULL ){//���node���Ǹ�
        if(node == node->parent->left)//���node�Ǹ���������
            node->parent->left = t;
        else if(node == node->parent->right)//���node�Ǹ������Һ���
            node->parent->right = t;
    }else{                  //���node���Ǹ�
        root = t;
    }
    node->parent = t;
    return root;
}
/* �������� */
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
/* �޸�������½�㱻�ƻ��ĺ���� */
static RBT* insertFixUp(RBT* node, RBT* root){
    RBT *parent, *grandParent, *uncle, *tmp;
    //���������Ǻ�ɫ�ľ��������ĺ�������ù�
    while( (parent=node->parent)!=NULL && parent->color=='r' ){
        grandParent = parent->parent;
        if(grandParent->left == parent){//�����������游������
            uncle = grandParent->right; //����������游���Һ���

            //(1)��һ���������ǰ���Ϊ��ɫ�������嶼Ϊ��ɫ����ʱ
            //Ҫ�Ѹ����嶼��ɺ�ɫ���游��ɺ�ɫ��֮��������游ѭ��
            if( uncle!=NULL && uncle->color=='r'){
                uncle->color = 'b';
                parent->color = 'b';
                grandParent->color = 'r';
                node = grandParent;
            }else{//(2)�������û�У������ǵڶ����������ǰ���Ϊ��ɫ����Ϊ��ɫ����Ϊ��ɫ��
                  //��ʱҪ�Ѹ����嶼��ɺ�ɫ���游��ɺ�ɫ��֮��������游ѭ��
                if( node == parent->right){//�����ǰ����Ǹ������Һ��ӣ�Ҫ��ת�����ȥ��ԭ�����������ܱ�֤���Է��Ϻ����
                    root = leftRotation(root, node);
                    tmp = parent;
                    parent = node;
                    node = tmp;//node��parentҪ����һ��
                }
                //�ٴ������һ�������
                parent->color = 'b';
                grandParent->color = 'r';
                root = rightRotation(root, grandParent);
            }
        }else if(grandParent->right == parent){//�����������游���Һ���
            uncle = grandParent->left;         //����������游������
            if( uncle!=NULL && uncle->color=='r'){
                uncle->color = 'b';
                parent->color = 'b';
                grandParent->color = 'r';
                node = grandParent;
            }else{
                if( node == parent->left){//�����ǰ����Ǹ��������ӣ�Ҫ��ת���ұ�ȥ��ԭ�����������ܱ�֤���Է��Ϻ����
                    root = rightRotation(root, node);
                    tmp = parent;
                    parent = node;
                    node = tmp;//node��parentҪ����һ��
                }
                //�ٴ������һ�������
                parent->color = 'b';
                grandParent->color = 'r';
                root = leftRotation(root, grandParent);
            }
        }
    }

    root->color = 'b';//��һ��Ҫ�Ǻ�ɫ
    return root;
}
static void deleteFixUp(RBT *root, RBT *x)//ɾ����ɫ���󣬵��º�ɫȱʧ��Υ������4,�ʶ������е���
{
    while( x != root && x->color == 'b' )  //���x�Ǻ�ɫ����ֱ�Ӱ�x��Ϊ��ɫ����ѭ���������Ӹպò���һ�غ�ɫ,Ҳ����������4
    {
        if( x == x->parent->left )     //���x���丸����������
        {
            RBT *w=x->parent->right;       //��w��x���ֵܽ��
            if( w->color == 'r' )         //case 1: ���w����ɫΪ��ɫ�Ļ�
            {
                w->color='b';
                x->parent->color='r';
                leftRotation(root, x->parent);
                w=x->parent->right;
            }
            if( w->left->color == 'b' && w->right->color == 'b' )   //case 2: w����ɫΪ��ɫ����������������ɫ��Ϊ��ɫ
            {
                w->color='r';
                x=x->parent;
            }
            else if( w->right->color == 'b' )         //case 3: w���������Ǻ�ɫ���������Ǻ�ɫ�Ļ�
            {
                w->color='r';
                w->left->color='b';
                rightRotation(root, w);
                w=x->parent->right;
            }
            w->color=x->parent->color;            //case 4: w���������Ǻ�ɫ
            x->parent->color='b';
            w->right->color='b';
            leftRotation(root , x->parent);

            x=root;
        }
        else           //�Գ���������x���丸����������
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
    newNode->color = 'r';//�½��ȫ��Ϊ��ɫ
    if(root == NULL){//��ΪNULLֱ�ӷ����½��
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
    //���ϲ����½�����

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
    if(curr == NULL) return;//û���ҵ�


    if(curr->left!=NULL && curr->right!=NULL){//�����Һ���
        del = getMinimumNode(curr->right);//ȥ�������������Ľ��
    }else{//��һ�����ӻ���һ��Ҳû��
        del = curr;
    }
    if(del->left!=NULL){
        child = del->left;
    }else if(del->right!=NULL){
        child = del->right;
    }
    parent = curr->parent;//parent�п���ΪNULL
    if(child!=NULL){
        child->parent = parent;
    }
    if(parent!=NULL){
        if(parent->left == del){
            parent->left = child;
        }else{
            parent->right = child;
        }
    }else{//parentΪNULL˵��ɾ�����Ǹ�
        root = child;
    }
    if(del != curr){//���Ҫɾ���Ľ�㲻��ԭ��㣬��˵���������Һ��ӵ����
        curr->data = del->data;

    }
    if(del->color == 'b'){//��ɫ����Ǻ�ɫ���ÿ���
        deleteFixUp(root, child);
    }
    free(del);
}
int main(){

    return 0;
}
