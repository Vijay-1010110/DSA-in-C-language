#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

//protocols 
struct node * createNode(int );
struct node * nonRecFindMin(struct node *);
struct node * recFindMin(struct node *);

int main(){

    struct node* root = NULL;
    root = createNode(55);
    root->left = createNode(20);
    root->left->left = createNode(10);
    root->left->right = createNode(30);

    printf("The minimum value the of the tree using non recrusive : %d\n",nonRecFindMin(root)->data);
    printf("The minimum value the of the tree using recrusive : %d\n",recFindMin(root)->data);



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
struct node * nonRecFindMin(struct node * root){
    if(root != NULL){
        while(root->left != NULL){
            root = root->left;
        }
    }
    return root;
}

//
struct node * recFindMin(struct node * root){
    if(!root)
        return NULL;
    else if(!root->left)
        return root;
    else
        return recFindMin(root->left);
}