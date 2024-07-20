#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int queue[MAX];

int top = -1;
int front = -1;
int rear = -1;

//protocols
//stack
void push(int);
int pop();
int isSEmpty();
int isSFull();
void reverseStack();
void printStack();

//queue
void enqueue(int);
int dequeue();
int isQEmpty();
int isQFull();

int main(){

    push(1);
    push(2);
    push(3);
    push(4);
    reverseStack();
    printStack();

    return 0;
}

//is stack Empty
int isSEmpty(){
    if (top == -1) 
        return 1;
    else
        return 0;
}

//is stack FULL
int isSFull(){
    if(top == MAX - 1)
        return 1;
    else
        return 0;
}

//push to stack
void push(int data){
    if(isSFull()){
        printf("Stack is Full\n"); 
        exit(1);
    }
    stack[++top] = data;
}

//pop from stack
int pop(){
    if(isSEmpty()){
        printf("Stack is empty \n");
        exit(1);
    }
    return stack[top--];
}

//is queue Empty
int isQEmpty(){
    if(front == -1)
        return 1;
    else
        return 0;
}

//is queue full
int isQFull(){
    if((front==0 && rear==MAX-1) || (front==rear+1))
        return 1;
    else
        return 0;
}

//enqueue
void enqueue(int data){
    if(isQFull()) {
        printf("\n Queue is Full! Can't add %d.\n",data);
        exit(1);
    }
    if(front == -1)
        front = 0;
    if(rear == MAX -1)
        rear = 0;
    else
        rear++;
    queue[rear] =  data;
}
//int dequeue
int dequeue(){
    int x;
    if(isQEmpty()){
        printf("\nQueue is Empty!");
        exit(1);
    }
    x = queue[front];
    if(rear == front)
        front =  rear = -1;
    else if(front == MAX - 1)
        front = 0;
    else
        front++;
    return x;
}


//reverse stack
void reverseStack(){
    // if(isQEmpty()){
    //     printf("\nQueue is Empty!");
    //     exit(1);
    // }
    while(!isSEmpty())
        enqueue(pop());
    
    while(!isQEmpty())
        push(dequeue());
}

//print stack
void printStack(){
    int temp = top ;
    while(temp != -1){
        printf("%d ",stack[temp--]);
    }
    printf("\n");
}