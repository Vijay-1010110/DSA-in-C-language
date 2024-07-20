#include <stdio.h>
#define MAX  5


int stack_arr[MAX];
int top = -1;

void push(int data){
    if(top == MAX - 1){
        printf("Stack OverFlow\n");
        return;
    }
    stack_arr[++top] = data;
}

int pop(){
    if (top==-1) {
        printf("Stack Underflow\n");
        return ;
    }
    int x=stack_arr[top--];
}

void print(){
    int i;
    if(top == -1){
        printf("stack underflow\n");
        return;
    }
    for(i = top ; i >= 0 ; i--){
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}


int main(){

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    int x;
    x = pop();
    x = pop();



    print();

    return 0;
}