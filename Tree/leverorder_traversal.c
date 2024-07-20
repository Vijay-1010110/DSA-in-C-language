#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node{
    struct node * left;
    int data;
    struct node * right;
};

struct node * queue[MAX];
int front = -1, rear = -1;

//prototypes
struct node * createNode(int);
void levelorder(struct node * root);
void enqueue(struct node * x);
struct node * dequeue();
int isEmpty();



int main(){

    struct node * root = NULL;
    root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    levelorder(root);

    return 0;
}


//create node
struct node* createNode(int data){
    struct node * newNode = malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

//lever order
void levelorder(struct node * root) {
    struct node * ptr = root;
    if(ptr == NULL){
        printf("Tree is empty\n");
        return;
    }
    while(!isEmpty()){
        ptr = dequeue();
        printf("%d ", ptr->data);
        if(ptr->left != NULL)
            enqueue(ptr->left);
        if(ptr->right != NULL)
            enqueue(ptr->right);
    }
}

//enqueue
void enqueue(struct node * x) {
    if(front == 0 && front == rear + 1){
        printf("\nqueue overflow\n");
        exit(1);
    }
    if(front == -1)
        front = 0;
    if(rear == MAX - 1)
        rear = 0;
    else
        rear++;
    queue[rear] = x;
}

//dequeue
struct node * dequeue(){
    struct node * x;
    if(isEmpty()){
        printf("\n**** Queue Underflow ****\n");
        exit(1);
    }
    x = queue[front];
    if(front == rear)
        front =  rear = -1;
    else if(front == MAX - 1)
        front = 0;
    else
        front++;
    return x;
}

//is queue empty
int isEmpty(){
    if(front == -1)
        return 1;
    else
        return 0;
}