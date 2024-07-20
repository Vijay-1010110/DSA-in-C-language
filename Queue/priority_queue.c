#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//Lower value has highest priority

struct node {
    int priority;
    int data;
    struct node * link;
}*front = NULL;

//protypes
void enqueue(int,int);
int dequeue();
int isEmpty();
int peek(); // get the highest priority element
void print();

int main(){

    while(1){
        int choice, data, priority;
        printf("\n*****************************************\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. get highest priority element\n");
        printf("4. print all element\n");
        printf("0. exit\n");

        printf("\n Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the element to be inserted and priority: ");
            scanf("%d %d",&data , &priority);
            enqueue(data,priority);
            break;

            case 2:
            printf("deleted element is : %d",dequeue());
            break;

            case 3:
            printf("highest priority value is : %d",peek());
            break;

            case 4:
            print();
            break;

            default:
            printf("  Invalid choice!......   \n");
        }
    }

    return 0;
}

//enqueue
void enqueue(int data , int priority){
    struct node * newNode = malloc(sizeof(struct node));    
    if(newNode == NULL){
        printf("\nmemeory not available\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->link = NULL;

    //case : if queue is empty or one element in the queue
    if((isEmpty()) || priority < front->priority){
        newNode->link = front;
        front = newNode;
    }
    else{
        struct node * temp = NULL;
        temp = front;
        while(temp->link != NULL && temp->link->priority <= priority)
            temp = temp->link;
        
        newNode->link = temp->link;
        temp->link = newNode;
    }
}

//dequeu funtion
int dequeue(){
    struct node * temp;
    int data;
    if(isEmpty()){
        printf("*** Queue Underflow ***\n");
        exit(1);
    }
    else{
        temp = front;
        data = temp->data;
        front = front->link;
        free(temp);
        temp = NULL;
    }
    return data;
}

//is empty
int isEmpty(){
    if(front == NULL)
        return 1;
    else
        return 0;
}

//get highest priority value 
int peek(){
    if(isEmpty()){
        printf("*** Queue Underflow ***\n");
        exit(1);
    }
    int data = front->data;
    return data;
}

//print all elements
void print(){
    struct node * ptr;
    ptr = front;
    if(isEmpty()){
        printf("*** Queue Underflow ***\n");
        exit(1);
    }
    else{
        printf("\n***  Queue  ***\n");
        while(ptr != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
    printf("\n");
}