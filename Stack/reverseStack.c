#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * link;
};

int isEmpty(struct node * top){
     return (top == NULL);
}

struct node * push(struct node * top , int data){
    struct node * newNode = malloc(sizeof(newNode));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
    return top;
}


struct node * pop(struct node * top){
    if(isEmpty(top)){
        printf("Stack UnderFlow.\n");
        return top;
    }
    struct node *temp = top;
    top = top->link;
    return temp;
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
    struct node * top1 = NULL;
    struct node * top2 = NULL;
    struct node * temp;

    top = push(top , 3);
    top = push(top , 2);
    top = push(top , 1);

    printf("before reverse\n");
    print(top);
    
    temp = pop(top);
    top = top->link;
    top1 = push(top1 , temp->data);
     temp = pop(top);
    top = top->link;
    top1 = push(top1 , temp->data);    
     temp = pop(top);
    top = top->link;
    top1 = push(top1 , temp->data);

     temp = pop(top1);
    top1 = top1->link;
    top2 = push(top2 , temp->data);
      temp = pop(top1);
    top1 = top1->link;
    top2 = push(top2 , temp->data);
      temp = pop(top1);
    top1 = top1->link;
    top2 = push(top2 , temp->data);
   
      temp = pop(top2);
    top2 = top2->link;
    top = push(top , temp->data);
     temp = pop(top2);
    top2 = top2->link;
    top = push(top , temp->data);
     temp = pop(top2);
    top2 = top2->link;
    top = push(top , temp->data);
   
    printf("\nAfter reverse\n");
    print(top);
   

    return 0;
}