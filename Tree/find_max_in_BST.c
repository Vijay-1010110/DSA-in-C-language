#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

//protocols 
struct node * createNode(int );
struct node * nonRecFindMax(struct node *);
struct node * recFindMax(struct node *);

int main(){

    struct node* root = NULL;
    root = createNode(55);
    root->left = createNode(20);
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right = createNode(56);

    printf("The Maximum value the of the tree using non recrusive : %d\n",nonRecFindMax(root)->data);
    printf("The Maximum value the of the tree using recrusive : %d\n",recFindMax(root)->data);



    return 0;
}

//
struct node* createNode(int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

//
struct node * nonRecFindMax(struct node * root){
    if(root != NULL){
        while(root->right != NULL){
            root = root->right;
        }
    }
    return root;
}

//
struct node * recFindMax(struct node * root){
    if(!root)
        return NULL;
    else if(!root->right)
        return root;
    else
        return recFindMax(root->right);
}