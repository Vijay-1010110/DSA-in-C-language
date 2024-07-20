#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cqueue[MAX];
int front = -1;
int rear = -1;
int stack[MAX]; //for reverse the queue
int top = -1;
//protypes 
void enqueue(int);
int dequeue();
int isEmpty();
int isFull();
int peek(); //return the first element of the queue
void print();
void push(int);
int pop();
void reverse();

int main(){

     // design the prompt for the user
    while (1)
    {
        int choice,data;
        printf("\n\n************************  Menu  ************************\n");
        printf("1 - > Enqueue\n");
        printf("2 - > Dequeue\n");
        printf("3 - > Get the first element of the queue\n");
        printf("4 - > Display All Elements \n");
        printf("5 - > Reverse Queue\n");
        printf("\n\n0 - > Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
        printf("Enter the element to be Inserted : ");
        scanf("%d",&data);
        enqueue(data);
        break;

        case 2:
        data = dequeue();
        printf("The deleted element from the queue is %d\n",data);
        break;


        case 3:
        data = peek();
        printf("The first element of the queue is %d\n\n",data);
        break;

        case 4:
        printf("Elements in the queue\n");
        print();
        break;

        case 5:
        reverse();
        printf("\n*** Queue is reversed ***:\n");
        break;

        case 0:
        printf("\n\nquit....\n");
        return 0;
        break;

        default:
        printf("Invalid choice");
        }
    }

    return 0;
}

//is empty
int isEmpty(){
    if(front == -1)
    return 1;
    else
    return 0;
}

//is full
int isFull(){
    if((front==0 && rear==MAX-1) || (front==rear+1))
    return 1;
    else
    return 0;
}

//enqueue
void enqueue(int x){
    if(isFull()){
        printf("\n**** Queue Overflow ****\n");
        exit(1);
    }
    if(front == -1)
        front = 0;
    if(rear == MAX -1)
        rear = 0;
    else
        rear++;
    cqueue[rear] =  x ;
}

//dequeue
int dequeue(){
    int x;
    if(isEmpty()){
        printf("\n**** Queue Underflow ****\n");
        exit(1);
    }
    x = cqueue[front];
    if(front == rear)
        front =  rear = -1;
    else if(front == MAX - 1)
        front = 0;
    else
        front++;
    return x;
}

//print element 
void print(){
    int temp;
    if(isEmpty()){
        printf("\n**** Queue Underflow ****\n");
        exit(1);
    }
    temp = front;

    while(1){
        printf("%d ",cqueue[temp]);

        if(temp == rear)
        break;

        if(temp == MAX -1){
            temp = 0 ;
            continue;
        }
        
        temp++;
    }
}

//peek get the first element of queue
int peek(){
    if(isEmpty()) {
        printf("Queue is empty \n");
        exit(1);
    }
    int x = cqueue[front];
    return x;
}

//push to stack
void push(int data){
    top++;
    stack[top] = data;
}

//pop from stack
int pop(){
    return stack[top--];
}

//reverse
void reverse(){
    
    while(!(isEmpty()))
        push(dequeue());

    while(top != -1)
        enqueue(pop());
}