#include <stdio.h>
#define MAX 100


int binary_arr[MAX];
int binary_top = -1;


int isEmpty() {
    if (binary_top == -1) {
        printf("Stack Underflow..\n");
        return 1;
    } else {
        return 0;
    }
}

int isFull() {
    if (binary_top >= MAX - 1) {
        printf("Stack Overflow..\n");
        return 1;
    } else {
        return 0;
    }
}

void push(int element) {
    if (isFull())
        return;
    binary_arr[++binary_top] = element;
}

int pop() {
    if (isEmpty())
        return -1; // Return a sentinel value to indicate an error
    int x = binary_arr[binary_top--];
    return x;
}

int peek() {
    if (isEmpty())
        return -1; // Return a sentinel value to indicate an error
    return binary_arr[binary_top];
}

void deimalToBinary(int decimal){
    while(decimal > 0){
        push(decimal%2);
        decimal /= 2;
    }
    printf("Binary converted value \n\n");
    while(binary_top != -1){
        printf("%d",pop());
    }
}


int main(){

    printf("*****************Decimal to binary*******************\n");
   int n;
   printf("Enter a decimal number\n");
   scanf("%d",&n);
   deimalToBinary(n);

    return 0;
}