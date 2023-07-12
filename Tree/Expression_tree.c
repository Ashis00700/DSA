#include<stdio.h>
#include<stdlib.h>
#define S 100
typedef struct st
{
    struct st* left;
    struct st* right;
    char data;
}Node;

#define ITEM Node*

typedef struct st1
{
    ITEM arr[S];
    int tos;
}Stack;

void init(Stack *ptr)
{
    ptr->tos = -1;
}

int isfull(Stack *ptr)
{
    if(ptr->tos == S-1) return 1;
    else return 0;
}

int isempty(Stack* ptr)
{
    if(ptr->tos == -1) return 1;
    else return 0;
}

void push(Stack* ptr, ITEM data)
{
    if(isfull(ptr) == 1) return;
    ptr->tos++;
    ptr->arr[ptr->tos] = data;
}

ITEM pop(Stack* ptr)
{
    ITEM temp;
    if(isempty(ptr) == 1) return NULL;
    temp = ptr->arr[ptr->tos];
    ptr->tos--;
    return temp;
}

ITEM peek(Stack* ptr)
{
    if(isempty(ptr) == 1) return NULL;
    return ptr->arr[ptr->tos];
}

Node* create_node(char value)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = value;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void pop_n_push(Stack* op, Stack* tree)
{
    Node* tmp;
    tmp = pop(op);
    tmp->right = pop(tree);
    tmp->left = pop(tree);
    push(tree, tmp);
}

int pred(char ch)
{
    if(ch == '*' || ch == '/') return 3;
    else if(ch == '+' || ch == '-') return 2;
    else return 1;
}

Node* convert(char arr[])
{
    int i;
    Stack op, tree;
    init(&op);
    init(&tree);
    for(i=0; arr[i] != '\0'; i++)
    {
        if(arr[i]>='a' && arr[i]<='z')
            push(&tree, create_node(arr[i]));
        else
        {
            switch(arr[i])
            {
                case '(':
                    push(&op, create_node(arr[i]));
                    break;
                case ')':
                    while(peek(&op)->data != '(')
                        pop_n_push(&op, &tree);
                    pop(&op);
                    break;
                default:
                    while(!isempty(&op) && pred(peek(&op)->data) >= pred(arr[i]))
                        pop_n_push(&op, &tree);
                    push(&op, create_node(arr[i]));
            }
        }
    }
    while(!isempty(&op))
    {
        pop_n_push(&op, &tree);
    }
    return pop(&tree);
}

void preorder(Node*ptr)
{
    if(ptr)
    {
        printf("%c",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

int main()
{
    char arr[S];
    Node*ptr;
    printf("Start\n");
    fgets(arr,sizeof(arr),stdin);
    ptr=convert(arr);
    preorder(ptr);
    return 0;
}