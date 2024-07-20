#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int height;
    struct node * left;
    struct node * right;
}avl_tree;

avl_tree * createNode(int);
avl_tree * insert(avl_tree * , int);
int max(int,int);
void printPreOrder(avl_tree * );
int height(avl_tree *);
int getBalanceF(avl_tree *);
avl_tree * leftRotate(avl_tree * );
avl_tree * rightRotate(avl_tree * );
avl_tree * balance(avl_tree * , int,int);

int main(){

    avl_tree * root = NULL;
    root = insert(root,56);
    root = insert(root,67);
    root = insert(root,69);
    root = insert(root,41);

    printPreOrder(root);

    return 0;
}

//create Node
avl_tree * createNode(int key){
    avl_tree * newNode = malloc(sizeof(avl_tree));
    newNode->key = key;
    newNode->height = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//insert
avl_tree * insert(avl_tree * root, int key){
    if(root == NULL)
    return createNode(key);

    if(root->key > key )
    root->left = insert(root->left , key);

    else if(root->key < key)
    root->right = insert(root->right, key);
    

    else{
        printf("\nDulicate key!...\n");
        return  root;
    }

    //update Height
    root->height = 1 + max(height(root->left) , height(root->right));

    int balanceF = getBalanceF(root);
    return balance(root,balanceF , key);
    


}

//balance
avl_tree * balance(avl_tree * n, int BF , int key){
    //Balance the node if BF > 1 or BF < -1
    if(BF > 1){
        if(key > n->left->key)
        n->left = leftRotate(n->left);

        return rightRotate(n);
    }
    if(BF < -1){
        if(key < n->right->key)
        n->right = rightRotate(n->right);

        return leftRotate(n);
    }

    //otherwise return the node 
    return n;
}


//calculate the maximum of two values
int max(int x, int y){
    return (x > y)? x : y ;
}

///get the balance factor of the node
int getBalanceF(avl_tree * n){
    if(n == NULL)
        return 0;

    return height(n->left) - height(n->right);  // Corrected formula
}

// Calculate the height of the node
int height(avl_tree * n){
    if(n == NULL)
        return -1;

    return 1 + max(height(n->left), height(n->right));  // Corrected formula
}

//rotate

avl_tree * leftRotate(avl_tree * A){
    avl_tree * B = A -> right;
    A->right = B->left;
    B->left = A;

    A->height = 1 + max(height(A->left) , height(A->right));
    B->height = 1 + max(height(B->left) , height(B->right));

    return B;
}

//right Rotation
avl_tree * rightRotate(avl_tree * B){
    avl_tree * A = B -> left;
    B->left = A->right;
    A->right = B;

    B->height = 1 + max(height(B->left) , height(B->right));
    A->height = 1 + max(height(A->left) , height(A->right));

    return A;
}


//print pre order
void printPreOrder(avl_tree * root) {
    if(root == NULL)
    return;

    printf("key : %d -> height : %d\n",root->key,root->height);
    printPreOrder(root->left);
    printPreOrder(root->right);
}


void displayTree(avl_tree * root){
    if (root != NULL) {
        print("Empty Tree\n");
        return;
    }

}