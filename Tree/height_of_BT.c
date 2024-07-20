#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node{
    struct node* left;
    struct node* right;
    int data;
};


struct node* createNode(int data){
    struct node * newNode = malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

//height of the binary tree
int heightBT(struct node * root){
    if(!root)
        return 0;
    if(!(root->left) && !(root->right))
        return 0;
    int left = heightBT(root->left);
    int right = heightBT(root->right);

    if (left > right)
        return left + 1;
    else 
        return right + 1;
}


int main(){

    struct node * root = NULL;
    root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);
    root->left->left->left = createNode(80);


    //height of binary tree 
    printf("Height of binary tree is %d\n", heightBT(root));

    return 0;
}