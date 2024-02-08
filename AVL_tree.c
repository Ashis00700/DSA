#include<stdio.h>
#include<stdlib.h>

typedef struct AVL_tree
{
    root*left,*right;
    int data,bfactor;
}root;

int height(root* node)
{
    int left_h,right_h;
    if(node==NULL) return;
    else
    {
        left_h=height(node->left);
        right_h=height(node->right);
    }
    return (left_h>right_h)? left_h +1 : right_h +1;
}

void insert_Avl(root**node,int data)
{
    if(*node==NULL)
    {
        *node=(root*)malloc(sizeof(root));
        (*node)->left=(*node)->right=NULL;
        (*node)->data=data;
        (*node)->bfactor=0;
    }
    else if(data<(*node)->data) insert_Avl(&(*node)->left,data);
    else insert_Avl(&(*node)->right,data);
}

void B_factor(root**node)
{
    int lh,rh;
    lh= height((*node)->left);
    rh= height((*node)->right);
    (*node)->bfactor= lh-rh;
}

void rotate(root**node)
{
    root* tmp;
    if((*node)->bfactor<-1)
    {
        tmp=(*node)->right->left;
        (*node)->right->left=(*node);
        (*node)=(*node)->right;
        (*node)->left->right=tmp;
        B_factor(&(*node));
        B_factor(&(*node)->left);
    }
    else if((*node)->bfactor>1)
    {
        tmp=(*node)->left->left;
        (*node)->left->right=(*node);
        (*node)=(*node)->left;
        (*node)->right->left=tmp;
        B_factor(&(*node));
        B_factor(&(*node)->right);
    }

}