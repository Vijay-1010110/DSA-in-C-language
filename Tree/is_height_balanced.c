#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    struct node* right;
    int data;
};

// Function Prototypes
struct node* createNode(int);
int isBalanced(struct node*);
int heightBT(struct node*);

int main() {
    struct node* root = NULL;
    root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    if (isBalanced(root))
        printf("The tree is a height-balanced binary tree\n");
    else
        printf("The tree is not a height-balanced binary tree\n");

    return 0;
}

struct node* createNode(int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
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
