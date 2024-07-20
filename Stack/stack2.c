#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int *arr;
    int top;
};

int isEmpty(struct stack *s){
    if(s->top == -1)
    return 1;
    else
    return 0;
}

int isFull(struct stack *s){
    if(s->top == (s->size)-1)
    return 1;
    else
    return 0;
}

void push(struct stack * s , int data){
    if(isFull(s)){
        printf("\nStack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = data;
}

int pop(struct stack *s){
    if(isEmpty(s)){
        printf("\nStack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(struct stack *s){
    if(isEmpty(s)){
        printf("\nStack UnderFlow\n");
        return -1;
    }
    return s->arr[s->top];
}

void print(struct stack *s){
    if(isEmpty(s)){
        printf("\nStack UnderFlow\n");
        return ;
    }
    for(int i = 0 ; i <= s->top ; i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

int main(){
    struct stack *s = malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));

    printf("***********Stack******************");
    while(1){
        int choice;
        int input;
        printf("\n************Menu*******************************:\n1.Push\n2.Pop\n3.Print Stack\n4.last element\n5.isEmpty\n6.isFull\n0.Exit\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
        printf("\nEnter the value to be pushed : ");
        scanf("%d",&input);
        push(s,input);
        break;

        case 2:
        printf("\nPopped Element %d \n",pop(s));
        break;

        case 3:
        print(s);
        break;

        case 4:
        printf("\nlast element of the stack : %d",peek(s));
        break;

        case 5:
        isEmpty(s)?(printf("\nYES\n")):(printf("\nNO\n"));
        break;

        case 6:
        isFull(s)?(printf("\nYES\n")):(printf("\nNO\n"));
        break;

        case 0:
        return 0;

        default:
        printf("\nInvalid Choice!!!\n");
        }
    }
        

}
