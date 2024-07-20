#include <stdio.h>
#include <stdlib.h>
#define MAX 5

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

void print() {
    if (isEmpty())
        return;
    else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack_arr[i]);
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        printf("1 -> push element\n");
        printf("2 -> pop element\n");
        printf("3 -> last element of the stack\n");
        printf("4 -> print all elements of the stack\n");
        printf("0 -> exit\n");

        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element: ");
                int input;
                scanf("%d", &input);
                push(input);
                break;
            case 2:
                if (!isEmpty()) {
                    int element = pop();
                    printf("popped element: %d\n", element);
                }
                break;
            case 3:
                if (!isEmpty()) {
                    int lastElement = peek();
                    printf("last element is %d\n", lastElement);
                }
                break;
            case 4:
                print();
                break;
            case 0:
                exit(0); // Exit the program
            default:
                printf("Invalid choice!...\n");
        }
    }

    return 0;
}
