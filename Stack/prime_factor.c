#include <stdio.h>
#define MAX 100

int stack_arr[MAX];
int top = -1;

int isEmpty() {
    if (top == -1) {
        printf("Stack Underflow..\n");
        return 1;
    } else {
        return 0;
    }
}

int isFull() {
    if (top >= MAX - 1) {
        printf("Stack Overflow..\n");
        return 1;
    } else {
        return 0;
    }
}

void push(int element) {
    if (isFull())
        return;
    stack_arr[++top] = element;
}

int pop() {
    if (isEmpty())
        return -1; // Return a sentinel value to indicate an error
    int x = stack_arr[top--];
    return x;
}

int peek() {
    if (isEmpty())
        return -1; // Return a sentinel value to indicate an error
    return stack_arr[top];
}


void prime_factor(int num){
    int i = 2 ;
    //push all prime factor of number onto stack
    while(num != 1){
        while(num % i == 0){
            push(i);
            num /= i;
        }
        i++;
    }

    printf("prime factor of a number in descending order\n");
    while(top != -1){
        printf("%d ",pop());
    }
}

int main(){
    int n;
    printf("Enter the number would you want to get prime factor : ");
    scanf("%d",&n);

    prime_factor(n);
    return 0;
}