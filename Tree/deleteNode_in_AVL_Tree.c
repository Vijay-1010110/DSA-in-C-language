#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int height;
    struct node * left;
    struct node * right;
};

//protocols
struct node * createNode(int );
int height(struct node *);
int max(int ,int);
int getBalanceF(struct node *);
struct node * balance(struct node *,int,int);
struct node * leftRotate(struct node *);
struct node * rightRotate(struct node *);
struct node * insert(struct node *,int);
struct node * getSuccessor(struct node *);
struct node * deleteNode(struct node *,int);
void printPreOrder(struct node * root);



int heightBT(struct node* root) {
    if (root == NULL)
        return -1;

    int left = heightBT(root->left);
    int right = heightBT(root->right);

    if (left > right)
        return left + 1;
    else
        return right + 1;
}
int isBalanced(struct node* root) {
    int lh, rh, diff;

    if (root == NULL)
        return 1;

    int l = isBalanced(root->left);
    int r = isBalanced(root->right);

    lh = heightBT(root->left);
    rh = heightBT(root->right);

    diff = abs(lh - rh);

    if (l && r && diff <= 1)
        return 1;

    return 0;
}



int main(){

    struct node * root = NULL;
    root = insert(root,45);
    root = insert(root,56);
    root = insert(root,87);
    root = insert(root, 89);
    root = insert(root, 97);
    root = insert(root, 101);

    root = deleteNode(root,101);
    root = deleteNode(root,97);

    printPreOrder(root);

    if(isBalanced(root))
    printf("\nbalanced");

    else
    printf("\not balanced");

    return 0;
}

//create Node
struct node* createNode(int key) {
    struct node * temp = malloc(sizeof(struct node));
    temp->data = key;
    temp->height = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}



//calculate the maximum of two values
int max(int x, int y){
    return (x > y)? x : y ;
}

///get the balance factor of the node
int getBalanceF(struct node * n){
    if(n == NULL)
        return 0;

    return height(n->left) - height(n->right);  // Corrected formula
}

// Calculate the height of the node
int height(struct node * n){
    if(n == NULL)
        return -1;

    return 1 + max(height(n->left), height(n->right));  // Corrected formula
}

//left Rotation
struct node * leftRotate(struct node * A){
    struct node * B = A -> right;
    A->right = B->left;
    B->left = A;

    A->height = 1 + max(height(A->left) , height(A->right));
    B->height = 1 + max(height(B->left) , height(B->right));

    return B;
}

//right Rotation
struct node * rightRotate(struct node * B){
    struct node *  A = B -> left;
    B->left = A->right;
    A->right = B;

    B->height = 1 + max(height(B->left) , height(B->right));
    A->height = 1 + max(height(A->left) , height(A->right));

    return A;
}

//balance
struct node* balance(struct node* n, int BF , int key){
    //Balance the node if BF > 1 or BF < -1
    if(BF > 1){
        if(key > n->left->data)
        n->left = leftRotate(n->left);

        return rightRotate(n);
    }
    if(BF < -1){
        if(key < n->right->data)
        n->right = rightRotate(n->right);

        return leftRotate(n);
    }

    //otherwise return the node 
    return n;
}

//Insert
struct node * insert(struct node * currentNode , int key){
    //Recursive procedure to find the correct position for the newly created Node
    if(currentNode == NULL)
    return createNode(key);

    if(key < currentNode->data)
    currentNode->left = insert(currentNode->left , key);

    else if(key > currentNode->data)
    currentNode->right = insert(currentNode->right , key);

    else
    return currentNode;

    //update the height of  the current node currenrtNode
    currentNode->height = 1 + max(height(currentNode->left) , height(currentNode->right));

    //calculate the Balancee Factor of current node
    int balanceF = getBalanceF(currentNode);
    return balance(currentNode , balanceF , key);
}


//print pre order
void printPreOrder(struct node* root) {
    if(root == NULL)
    return;

    printf("%d ",root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}



//get successor
struct node * getSuccessor(struct node * temp){
    while(temp->left != NULL)
    temp = temp->left;

    return temp;
}

//delete the node 
struct node* deleteNode(struct node* currentNode, int key){
    if(currentNode == NULL)
    return currentNode;

    if(key < currentNode->data)
    currentNode->left = deleteNode(currentNode->left , key);

    else if(key > currentNode->data)
    currentNode->right = deleteNode(currentNode->right , key);

    else{
        //key is found
        //delete the Node
        //Node with one child or no  child
        if(currentNode->left == NULL || currentNode->right == NULL){
            struct node * temp = NULL;
            if(currentNode->left != NULL)
            temp = currentNode->left;

            else if(currentNode->right != NULL)
            temp = currentNode->right;

            //if node has no child
            if(temp == NULL){
                temp = currentNode ;
                currentNode = NULL ;
            }
            else //if node has one child
            *currentNode = *temp;

            free(temp);
        }
        else{
            //node with two children
            struct node * temp = getSuccessor(currentNode->right);
            //copy the data of the inorder successor
            currentNode->data = temp->data;
            currentNode->right = deleteNode(currentNode->right , temp->data);
        }
    }
    if(currentNode == NULL)
    return currentNode;

    //update the balance factor of each node
    currentNode->height = 1 + max(height(currentNode->left) , height(currentNode->right));

    int balance = getBalanceF(currentNode);

    if(balance > 1){
        if(getBalanceF(currentNode->left) < 0 )
        currentNode->left = leftRotate(currentNode->left);

        return rightRotate(currentNode);
    }
    if(balance < -1 ){
        if(getBalanceF(currentNode->right) > 0)
        currentNode->right = rightRotate(currentNode->right);

        return leftRotate(currentNode);
    }
    return currentNode;
}