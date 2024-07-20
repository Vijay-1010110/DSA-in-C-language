#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack1[MAX];
int stack2[MAX];

int top1 = -1;
int top2 = -1;

//prototypes
void enqueue(int);
int dequeue();
void push1(int);
void push2(int);
int pop1();
int pop2();
int peek(); //get the first element of the queue
void print();

    

int main(){

    enqueue(1);//1
    enqueue(2);// 1 2
    enqueue(3);//1 2 3
    enqueue(4);//1 2 3 4
    dequeue(); //2 3 4
    dequeue(); // 3 4
    print();

    return 0;
}

//push to stack1
void push1(int data){
    top1++;
    stack1[top1] = data;
}

//push to stack2
void push2(int data){
    top2++;
    stack2[top2] = data;
}

//pop from stack 1
int pop1(){
    int data;
    data = stack1[top1];
    top1--;
    return data;
}

//pop from stack 2
int pop2(){
    int data;
    data = stack2[top2];
    top2--;
    return data;
}

//enqueue function
void enqueue(int data){
    if(top1 == MAX -1){
        printf("*** Queue OverFlow ***\n");
        exit(1);
    }
    push1(data);
}

//dequeue funtion
int dequeue(){
    int temp;
    if(top2 == -1){
        if(top1 == -1){
            printf("*** Queue UnderFlow ***\n");
            exit(1);
        }
        
        while(top1 != -1){
            temp = pop1();
            push2(temp);
        }
    }
    return pop2();
}

//peek funtion get the first element of the queue
int peek(){
    if(top1 == -1 && top2 == -1){
        printf("*** Queue UnderFlow ***\n");
            exit(1);
    }
    else if(top2 == -1)
        return stack1[0];
    else
        return stack2[top2];
}

//print all elements of the queue
void print(){
    int i;
    if(top1 == -1 && top2 == -1){
        printf("*** Queue UnderFlow ***\n");
            exit(1);
    }
    for(i = top2 ; i >= 0 ; i--){
        printf("%d ",stack2[i]);
    }
    for(i = 0 ; i <= top1 ; i++){
        printf("%d ",stack1[i]);
    }
    printf("\n");
}