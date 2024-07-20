#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

//prototypes
void enqueueFront(int);
void enqueueRear(int);
int dequeueFront();
int dequeueRear();
int isEmpty();
int isFull();
int peek(); //get the first element of the queue
void print();

int main(){

     // design the prompt for the user
    while (1)
    {
        int choice,data;
        printf("\n\n************************  Menu  ************************\n");
        printf("1 - > Insert element at the Front end\n");
        printf("2 - > Insert element at the Rear end\n");
        printf("3 - > Delete from the Front end\n");
        printf("4 - > Delete from the Rear end\n");
        printf("5 - > Get the first element of the queue\n");
        printf("6 - > Display All Elements \n");
        printf("\n\n0 - > Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
        printf("Enter the Inserted element at the Front end : ");
        scanf("%d",&data);
        enqueueFront(data);
        break;

        case 2:
        printf("Enter the Inserted element at the Rear end : ");
        scanf("%d",&data);
        enqueueRear(data);
        break;

        case 3:
        printf("Deleted element from the Front end : %d\n",dequeueFront());
        break;

        case 4:
        printf("Deleted element from the Rear end : %d\n",dequeueRear());
        break;

        case 5:
        printf("The first element of the queue is %d\n",peek());
        break;

        case 6:
        printf("Elements in the queue\n");
        print();
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

//insert at the front end
void enqueueFront(int data){
    if(isFull()){
        printf("*** Queue Overflow ***\n");
        exit(1);
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }else if(front == 0)
        front = MAX - 1;
    else   
        front--;
    deque[front] = data;
}

//insert at the rear end
void enqueueRear(int data){
    if(isFull()){
        printf("*** Queue Overflow ***\n");
        exit(1);
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else if(rear == MAX - 1)
        rear = 0;
    else
        rear++;
    deque[rear] = data;
}

//delete from the front
int dequeueFront(){
    int data;
    if(isEmpty()){
        printf("*** Queue Underflow ***\n");
        exit(1);
    }
    data = deque[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        if(front == MAX - 1)
            front = 0;
        else
            front++;
    }
    return data;
}

//delete from the rear end
int dequeueRear(){
    int data;
    if(isEmpty()){
        printf("*** Queue Underflow ***\n");
        exit(1);
    }
    data = deque[rear];
    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        if(rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }
    return data;
}

//is Empty
int isEmpty(){
    if(front == -1)
        return 1;
    else
        return 0;
}

//is Full
int isFull(){
    if((front == 0 && rear == MAX - 1) || front == rear + 1)
        return 1;
    else
        return 0;
}

//int peek
int peek() //get the first element 
{
    if(isEmpty()){
        printf("*** Queue Underflow ***\n");
        exit(1);
    }
    return deque[front];
}

//print all element
void print(){
    int i;
    if(isEmpty()){
        printf("*** Queue Underflow ***\n");
        exit(1);
    }
    i = front;
    while(1){
        printf("%d ",deque[i]);

        if(i == rear)
            break;

        if(i == MAX - 1){
            i = 0;
            continue;
        }

        i++;
    }
}