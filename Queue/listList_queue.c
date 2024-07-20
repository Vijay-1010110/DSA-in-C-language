#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
}*front = NULL , *rear = NULL;

//prototypes
void enqueue(int);
int dequeue();
int isEmpty();
int peek(); //return the first element of the queue
void print();

int main(){

     // design the prompt for the user
    while (1)
    {
        int choice,data;
        printf("\n\n************************  Menu  ************************\n");
        printf("1 - > Insert element in the queue\n");
        printf("2 - > Delete the last element from the queue\n");
        printf("3 - > Get the first element of the queue\n");
        printf("4 - > Display All Elements \n");
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

//IsEmpty

int isEmpty(){
    if(front == NULL)
    return 1;
    else 
    return 0;
}

//enqueue
void enqueue(int data){
    struct node * temp = malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory error");
        exit(1);
    }
    temp->data = data;
    temp->link = NULL;

    if(rear == NULL)
        front = rear = temp;
    else{
        rear->link = temp;
        rear = temp;
    }
}

//dequeue
int dequeue(){
    int x;
    struct node * temp = malloc(sizeof(struct node));
    if(isEmpty()){
        printf("Queue Underflow\n");
        exit(1);
    }
    x = front->data;
    temp = front;
    front = front->link;
    free(temp);
    temp = NULL;
    return x;
}

//peek get the first element of the queue 
int peek(){
    int x;
    if(isEmpty()) {
        printf("Queue Underflow \n");
        exit(1);
    }
    x= front->data;
    return x;
}

//print the queue
void print(){
    struct node* ptr;
    if(isEmpty()) {
        printf("Queue Underflow \n");
        exit(1);
    }
    ptr = front;

    printf("\n\nQueue \n");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n\n");
}