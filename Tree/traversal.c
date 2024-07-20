#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* left;
    struct node* right;
    int data;
};



//protocols
struct node* createNode(int);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);


int main(){

    struct node * root = NULL;
    root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);
    
    printf("Preorder traversal of binary tree is \n");
    printf("Preorder\n");
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
    if(root == NULL)
    return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node * root){
    if(root == NULL)
    return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node * root){
    if(root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}