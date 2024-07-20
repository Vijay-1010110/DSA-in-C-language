#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * link;
} *top = NULL;

int isEmpty(){
    if(top)return 0;
    else return 1;
}

void push(int data){
    struct node *newNode = malloc(sizeof(newNode));
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

int pop(){
    if (top == NULL) {
        printf("Stack UnderFLow\n");
        return -1;
    }
    struct node * temp = top;
    int poppedData = top -> data;
    top = top->link;
    free(temp);
    temp = NULL;
    return poppedData;
}
void isPalindrone(char* s){
    int i = 0;
    while(s[i] != 'X'){
        push(s[i]);
        i++;
    }
    i++;

    while(s[i]){
        if(isEmpty() ||  s[i] != pop() ){
        printf("Not a palindrone\n");
        exit(1);
       }
       i++;
    }
    if(isEmpty())
    printf("is a palindrone\n");
    else printf("not a palindrone\n");
}

int main(){
    printf("check whether is string plindrone or not (Note : string must contain a X in middle of character)\n");
    printf("Please Enter a string : ");
    char s[100];
    scanf("%s",s);
    isPalindrone(s);


    return 0;
}