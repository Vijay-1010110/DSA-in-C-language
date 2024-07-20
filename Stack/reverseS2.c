#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * link;
};

int isEmpty(struct node * top){
     return (top == NULL);
}

void push(struct node **top , int x){
    struct node * newNode = malloc(sizeof(newNode));
    if(newNode == NULL){
        printf("memory allocation failed!..\n");
        return;
    }
    newNode->data  = x ;
    newNode->link = *top;
    *top = newNode;
}

int pop(struct node **top){
    if(*top == NULL){
        printf("Stack UnderFlow\n");
        return -1;
    }
    struct node *temp = NULL;
    temp = *top;
    int x = temp->data;
    *top = (*top)->link;
    free(temp);
    temp = NULL;
    return x;
}

void reverseStack(struct node** top){
    struct node * top1 = NULL; 
    struct node * top2 = NULL;

    while(*top != NULL){
        push(&top1 , pop(top));
    }

    while(top1 != NULL){
        push(&top2 , pop(&top1));
    }

    while(top2 != NULL){
        push(top , pop(&top2));
    }
}


void print(struct node* top){
    if(isEmpty(top)){
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
    struct node * top = NULL;
    struct node * topA = NULL;
    
    push(&top , 1);
    push(&top , 2);
    push(&top , 3);
    printf("Before Reverse\n");
    print(top);
    reverseStack(&top);
    printf("After Reverse\n");
    print(top);
    return 0;
}