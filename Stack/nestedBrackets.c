#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


int top = -1;
char stack[MAX];

int isEmpty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(int data){
    if(top == MAX - 1){
        printf("Stack OverFlow\n");
        return;
    }
    stack[++top] = data;
}

int pop(){
    if (top==-1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x=stack[top--];
}

int match_bracket(char a ,char b){
    if((a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')')){
        return 1;
    }else return 0;
}

int check_balance(char * s){
    int i;
    char temp;
    for( i = 0 ; i < strlen(s) ; i++){
        if(s[i] == '[' || s[i] == '{' || s[i] == '('){
            push(s[i]);
        }

        if(s[i] == ']' || s[i] == '}' || s[i] == ')'){
            if(isEmpty()){
                printf("right brackets are more than the left");
                return 0;
            }
            temp = pop();
            if(!match_bracket(temp , s[i])){
                printf("Mismatch brackets\n");
                return 0;
            }
        }
    }
    if(isEmpty()){
        printf("brackets are well balanced.\n");
        return 1;
    }
    else{
        printf("left brackets are more than the right");
                return 0;
    }
}

int main(){

    char expr[MAX];
    int balanced;
    printf("Enter a algebric expression : ");
    gets(expr);

    printf("\n");
    balanced = check_balance(expr);
    if(balanced){
        printf("The given algebraic expression is balanced.\n");
    }else{
        printf("Invalid expresion!...\n");
    }

    return 0;
}

