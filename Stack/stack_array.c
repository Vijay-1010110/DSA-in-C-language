#include <stdio.h>
#include <stdlib.h> // for exit() function
#define MAX 5

int stack_arr[MAX];
int first = -1;

int isEmpty(){
    if(first == -1)
    return 1;
    else
    return 0;
}

int isFull(){
    if(first == MAX-1)
    return 1;
    else
    return 0;
}

int peek(){
    if(isEmpty()){
        printf("Stack UnderFlow\n");
    }
    return stack_arr[0];
}

void push(int element){
    if(first == (MAX-1))
        printf("Stack OverFlow\n");
    else{
        int i;
        first += 1;
        for(i = first ; i > 0 ; i--)
            stack_arr[i] = stack_arr[i-1];
        stack_arr[0] = element;
    }
}

int pop(){
    if(first == -1)
    printf("Stack UnderFlow..\n");
    else{
        int i;
        int value = stack_arr[0];
        for(i = 0 ; i < first ; i++){
            stack_arr[i] = stack_arr[i+1];
        }
        first--;
    }
}

void print(){
    if(first == -1)
    printf("Stack UnderFlow\n");
    else{
        int i;
        for(i = 0 ; i <= first ; i++){
            printf("%d ",stack_arr[i]);
        }
        printf("\n");
    }
}

int main(){
    while(1){
        printf("1 -> push\n");
        printf("2 -> pop\n");
        printf("3 -> isEmpty\n");
        printf("4 -> isFull\n");
        printf("5 -> peek\n");
        printf("6 -> print\n");
        printf("0 -> exit \n");

        int choice;
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: int element;
            printf("Enter the number to be pushed in the Stack : ");
            scanf("%d",&element);
            push(element);
            break;

            case 2:
            int popped = pop();
            printf("popped element %d\n",popped);
            break;

            case 3:
            if(isEmpty())
            printf("Stack UnderFlow\n");
            break;

            case 4:
            isFull();
            if(isFull())
            printf("Stack Overflow\n");
            break;

            case 5:
            printf("last element of the stack is : %d \n",peek());
            break;

            case 6:
            print();
            break;

            case 0: 
            exit(1);

            default:
            printf("Invalid Choice\n");
        }

    }

    return 0;
}