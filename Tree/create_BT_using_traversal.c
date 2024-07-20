#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * left;
    char data;
    struct node * right;
};

//prototypes
struct node * constructBT(char[],char[],int,int);
struct node * createNode(char);
int searchIn(char[],char,int,int);
void printPre(struct node *);

int main(){

    char preArr[] = {'A','B','D','E','C'};
    char inArr[] = {'B','D','E','A','C'};
    int length = sizeof(inArr)/sizeof(inArr[0]);
    struct node * root = constructBT(inArr , preArr , 0 , length - 1);

    printPre(root);

    return 0;
}

//construct Binary tree
struct node *constructBT(char inArr[], char preArr[], int inStart, int inEnd) {
    static int preIndex = 0;

    if (inStart > inEnd) {
        return NULL;
    }

    struct node *temp = createNode(preArr[preIndex]);
    preIndex++;

    if (inStart == inEnd) {
        return temp;
    }

    int inIndex = searchIn(inArr, temp->data, inStart, inEnd);
    temp->left = constructBT(inArr, preArr, inStart, inIndex - 1);
    temp->right = constructBT(inArr, preArr, inIndex + 1, inEnd);

    return temp;
}


//create a new Node
struct node * createNode(char data){
    struct node * ptr = malloc(sizeof(struct node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->data = data;
    return ptr;
}

//search In
int searchIn(char inArr[] , char data , int inStart ,int inEnd){
    int i;
    for(i = inStart ; i <= inEnd ; i++){
        if(inArr[i] == data)
            return i;
    }
}

//print pre
void printPre(struct node * root){
    if (root == NULL) 
        return;
    printf("%c ",root->data);
    printPre(root->left);
    printPre(root->right);
}