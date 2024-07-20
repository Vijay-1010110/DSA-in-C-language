#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * left;
    struct node * right;
    int data;
};
//protocol
struct node * createTree();
int isFullBinaryT(struct node * );

int main(){

   struct node * root = createTree(); 
   
   if(isFullBinaryT(root)){
        printf("\nGiven Tree is Full Binary Tree\n");
   }
   else{
        printf("\nGiven Tree is not a Full Binary Tree\n");
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

int isFullBinaryT(struct node * root){
    int left,right;
    if(root == NULL){
        return 1;
    }
    else if(!(root->left) && !(root->right)){
        return 1;
    }
    else if((root->left) && (root->right)){
        left = isFullBinaryT(root->left);
        right = isFullBinaryT(root->right);
        return (left && right);
    }
    return 0;
}