#include <stdio.h>
#include <stdlib.h> //for exit function
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

// protocols
void enqueue(int data);
int dequeue();
int isEmpty();
int isFull();
int peek();   // return the first element of the queue;
void displayQueue(); // display all elements


int main()
{

    // design the prompt for the user
    while (1)
    {
        int choice,data;
        printf("\n\n************************  Menu  ************************\n");
        printf("1 - > Insert element in the queue\n");
        printf("2 - > Delete the last element from the queue\n");
        printf("3 - > Check queue is Empty\n");
        printf("4 - > Check queue is FUll\n");
        printf("5 - > Get the first element of the queue\n");
        printf("6 - > Display All Elements \n");
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
        if(isEmpty())
        printf("The queue is Empty\n");
        else
        printf("The queue is not Empty\n");
        break;

        case 4:
        if(isFull())
        printf("The queue is Full\n");
        else
        printf("The queue is not Full\n");
        break;

        case 5:
        data = peek();
        printf("The first element of the queue is %d\n\n",data);
        break;

        case 6:
        printf("Elements in the queue\n");
        displayQueue();
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

//is Empty
int isEmpty(){
    if(front == -1 || front == rear + 1)
    return 1;
    else
    return 0;
}

//ia Full
int isFull(){
    if(rear == MAX - 1)
    return 1;
    else
    return 0;
}

/* Function to insert an element at the end of the queue */
void enqueue(int data){
    if(front == -1)
    front = 0;
    if(isFull()){
        printf("Queue is full.\n");
        exit(1);
    }
    rear++;
    queue[rear] = data;
}

/* Function to delete an element at the front of the queue */
int dequeue(){
    int x;
    if(isEmpty()){
        printf("Queue is empty.\n");
        exit(1);
    }
    x = queue[front];
    front++;
    return x;
}

//peek for get the first element of the   queue
int peek(){
    int x;
    if(isEmpty()){
        printf("Queue is empty.\n");
        exit(1);
    }
    x = queue[front];
}

//display Queue
void displayQueue(){
    int i;
    if(isEmpty()){
        printf("Queue is empty.\n");
        exit(1);
    }
    for(i = front ; i <= rear ; i++){
        printf("%d ", queue[i]);
    }
}
