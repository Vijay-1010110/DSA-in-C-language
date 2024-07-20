#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    struct node* right;
    int data;
};

// Function Prototypes
struct node* createNode(int);
struct node * nonRecSearch(struct node * , int);
struct node * recSearch(struct node * , int);

int main() {
    struct node* root = NULL;
    root = createNode(50);
    root->left = createNode(20);
    root->left->right = createNode(30);
    root->left->left = createNode(10);
    root->right = createNode(55);
    root->right->right = createNode(60);
    root->right->right->right = createNode(70);

    // if(nonRecSearch(root,55)){
    //     printf("Element is present in the tree\n");
    // }
    // else
    //     printf("Element is not present in the tree");

    if(recSearch(root,55)){
        printf("Element is present in the tree\n");
    }
    else
        printf("Element is not present in the tree");

    return 0;
}

struct node* createNode(int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

//
struct node * nonRecSearch(struct node * root, int skey){
    while(root != NULL){
        if(skey < root->data)
            root = root->left;
        else if(skey > root->data)
            root = root->right;
        else 
            return root;
    }
    return NULL;
}

//
struct node * recSearch(struct node * root , int skey){
    if(root == NULL)
        return NULL;
    else if(skey < root->data)
        return recSearch(root->left,skey);
    else if(skey > root->data)
        return recSearch(root->right , skey);
    else    
        return root;
}