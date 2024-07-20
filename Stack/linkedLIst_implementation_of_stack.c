#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
}*top = NULL;


int isEmpty(){
    if(top)
        return 0;
    else
        return 1;
}


void push(int el){
    struct node *newNode = malloc(sizeof(newNode));
    if(newNode == NULL){
        printf("Stack Overflow\n");
        return ;
    }
    newNode->data = el;
    newNode->link = top;
    top = newNode;
}

int pop(){
    if(isEmpty()){
        printf("Stack UnderFlow..\n");
        return -1;
    }
    struct node *temp = top;
    int poppedData = temp -> data;
    top =  top->link;
    free(temp);
    temp = NULL;
    return poppedData;
}

int peek(){
    if(isEmpty()){
        printf("Stack UnderFlow..\n");
        return -1;
    }
    return (top->data);
}

void print(){
    if(isEmpty()){
        printf("Stack UnderFlow\n");
        return;
    }
    struct node *ptr = top;
    printf("stak elements\n");
    printf("\n");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n\n");
}

int main(){

    printf("*********Linked List representation of stackk\n");
    while(1){
        int choice, item;
        printf("1 -> push\n");
        printf("2 -> pop\n");
        printf("3 -> get last element\n");
        printf("4 -> is Empty\n");
        printf("5 -> print\n");
        printf("0 -> exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("enter the number to be pushed in stack : ");
            scanf("%d",&item);
            push(item);
            break;

            case 2:
            printf("\nPopped Item : %d",pop());
            break;

            case 3:
            printf("\nthe last element in stack is : %d\n",peek());
            break;

            case 4:
            printf("\nis Stack empty ? %s \n",isEmpty()?"Yes":"No");
            break;

            case 5:
            print();
            break;

            case 0:
            return 0;

            default:
            printf("\nInvalid Choice. Please enter again.\n");
        }

    }

    return 0;
}