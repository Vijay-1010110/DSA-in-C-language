#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * left;
    struct node * right;
    int data;
};
//protocol
struct node *createTree();
int count_nodes(struct node*);
int isCompleteBinaryT(struct node*,int,int);

int main(){

    struct node * root = createTree(); 
    int count = count_nodes(root);
    printf("Number of Nodes in given binary tree is %d\n",count);
    
    if(isCompleteBinaryT(root , 0 , count)){
        printf("given tree is a complete binary Tree\n");
    }
    else{
        printf("given tree is not a complete binary Tree\n");
    }


    return 0;
}

struct node * createTree(){
    int input,data;
    printf("Do you want to add a node? (0 for NO and 1 for YES) : ");
    scanf("%d",&input);
    if(!input)
        return NULL;
    else{
        struct node * newNode = malloc(sizeof(struct node));
        printf("\nEnter the Data of the Node: ");
        scanf("%d",&data);
        newNode->data = data;
        printf("Left Child of %d ? ",data);
        newNode->left = createTree();
        printf("Right Child of %d ? ",data);
        newNode->right = createTree();
        return newNode;
    }
}

int count_nodes(struct node * root){
    if(root == NULL)
        return 0;
    else if(!(root->left) && !(root->right))
        return 1;
    else{
        int left = count_nodes(root->left);
        int right = count_nodes(root->right);
        return (1 + right + left);
    }
}

int isCompleteBinaryT(struct node * root , int index , int count){
    if(!(root))
        return 1;
    if(index >= count)
        return 0;
    int left = isCompleteBinaryT(root->left, 2 * index + 1 ,count);
    int right = isCompleteBinaryT(root->right , 2 * index + 2 , count);
    return (left && right);
}