#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node{
    struct node* left;
    struct node* right;
    int data;
};

struct node * stack[MAX];
int top = -1;

//protocols
struct node* createNode(int);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
void push(struct node *);
struct node* pop();
int isEmpty();


int main(){

    struct node * root = NULL;
    root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    printf("\nPreorder\n");
    preorder(root);
    printf("\nInorder\n");
    inorder(root);
    printf("\nPostorder\n");
    postorder(root);

    return 0;
}


struct node* createNode(int data){
    struct node * newNode = malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

void preorder(struct node * root){
    struct node * ptr = root ;
    if(ptr == NULL){
        printf("Tree is empty\n");
        exit(1);
    }
    push(ptr);
    while(!isEmpty()){
        ptr = pop();
        printf("%d ", ptr->data) ;
        if(ptr->right != NULL)
            push(ptr->right);
        if(ptr->left != NULL)
            push(ptr->left);
    }
}

void inorder(struct node * root){
    struct node * ptr = root;
    while(1){
        while(ptr->left != NULL){
            push(ptr);
            ptr = ptr->left;
        }
        while(ptr->right == NULL){
            printf("%d ",ptr->data);
            if(isEmpty())
                return;
            ptr = pop();
        }
        printf("%d ",ptr->data);
        ptr=ptr->right;
    }
}

void postorder(struct node * root){
    struct node * ptr = root;
    struct node * temp = root;

    while(1){
        while(ptr->left != NULL){
            push(ptr);
            ptr = ptr->left;
        }

        while(ptr->right == NULL || ptr->right == temp){
            printf("%d ",ptr->data);
            temp = ptr ;
            if(isEmpty())
                return;
            ptr = pop();
        }
        push(ptr);
        ptr = ptr->right;
    }
}

void push(struct node * ptr){
    if(top == MAX - 1){
        printf("\nStack Overflow \n") ;
        exit(1);
    }
    top = top + 1;
    stack[top] = ptr;
}

struct node * pop(){
    struct node * ptr;
    if(top == -1){
        printf("\n Stack Underflow \n") ;
        exit(1);
    }
    ptr = stack[top];
    top = top - 1;
    return ptr;
}

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}
