#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX] , postfix[MAX];
int top = -1 ;

int isEmpty(){
    if(top == -1)
    return 1;
    else 
    return 0;
}

void push(char symbol){
    if(top == (MAX-1)){
        printf("\nStack Overflow!........\n");
        return;
    }
    stack[++top]=symbol;
}

int pop(){
    if (isEmpty()){
        printf("Stack Underflow!");
        exit(0);
    }
        int x = stack[top--];
}


void removeSpaces(char* input) {
    int i, j=0;
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ' && input[i] != '\t') {
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0'; // Null-terminate the string.
}

int precedence(char symbol){
    //higher value greater precedence
    switch(symbol){
        case '^':
        return 3;

        case '*':
        case '/':
        return 2;

        case '+':
        case '-':
        return 1;

        default:
        return 0;
    }
}


void infix2postfix(){
    int i, j = 0;
    char symbol , next ;
    //remove all white spaces
    removeSpaces(infix);
    int infix_len = strlen(infix);

    for(i = 0 ; i < infix_len ; i++){
    symbol = infix[i];
    switch(symbol){
        case '(':
        push(symbol);
        break;

        case ')':
        while((next=pop())!='(')
            postfix[j++] = next;
        break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
        postfix[j++]= pop();
        push(symbol);
        break;

        default:
        postfix[j++] = symbol;
    }
    }
    while(!isEmpty())
    postfix[j++] = pop();
    postfix[j] = '\0';     
}

void print(){
    printf("The equivalent postfix expression is : ");
    int i = 0;
    while(postfix[i]){
        printf("%c",postfix[i++]);
    }
    printf("\n");
}

int main(){
    printf("\nEnter a InFix Expression : \n");
    gets(infix);

    infix2postfix();
    print();


}
