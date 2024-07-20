#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * left;
    struct node * right;
    int data;
};
//protocol
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
int main(){

   struct node * root = createTree(); 
   printf("%d ",root->data); 
      printf("%d ",root->left->data);

   printf("%d ",root->right->data);

   printf("%d ",root->left->left->data);

   printf("%d ",root->right->left->data);


    return 0;
}