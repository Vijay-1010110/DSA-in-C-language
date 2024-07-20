#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * left;
    char data;
    struct node * right;
};

//prototypes
struct node * constructBT(char[] , char[] , int , int , int *);
struct node * createNode(char);
struct node * helper(char[] , char[] ,int);
int searchIn(char[] , char , int , int);
void printPost(struct node * );


int main(){

    char postArr[] = {'D','E','B','F','C','A'};
    char inArr[] = {'D','B','E','A','F','C'};

    int length = sizeof(inArr)/sizeof(inArr[0]);
    struct node * root = helper(inArr, postArr , length);

    printPost(root);


    return 0;
}

//
struct node * constructBT(char inArr[] , char postArr[] ,int inStart , int inEnd , int * post){
    if (inStart > inEnd)
        return NULL;
    
    struct node * temp = createNode(postArr[*post]);
    (*post)--;

    if(inStart == inEnd)
        return  temp;
    
    int inIndex = searchIn(inArr , temp->data , inStart , inEnd);

    temp->right = constructBT(inArr , postArr , inIndex + 1 , inEnd , post);
    temp->left = constructBT(inArr , postArr , inStart , inIndex - 1 , post);

    return temp;
}

//
struct node * helper(char inArr[] , char postArr[]  , int n ){
    int postIndex = n - 1;
    return constructBT(inArr , postArr , 0 , n -1 , &postIndex);
}

//
struct node * createNode(char data){
    struct node * ptr = malloc(sizeof(struct node));
    ptr->left = NULL;
    ptr->data =  data;
    ptr->right = NULL;
}

//
int searchIn(char inArr[] , char data , int inStart , int inEnd){
    int i;
    for(i = inStart ; i <= inEnd ; i++){
        if(inArr[i] == data )
            return i;
    }
}

//
void printPost(struct node * root){
    if(!root)
    return;

    printPost(root->left);
    printPost(root->right);
    printf("%c ",root->data);
}
