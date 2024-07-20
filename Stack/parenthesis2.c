#include <stdio.h>
#include <stdlib.h>

struct node {
    int size;
    int top;
    char *arr;
};

int isFull(struct node *ptr) {
    return ptr->top == ptr->size - 1;
}

int isEmpty(struct node *ptr) {
    return ptr->top == -1;
}

void push(struct node *ptr, char ch) {
    if (isFull(ptr)) {
        printf("Stack Overflow\n");
        return;
    }
    ptr->arr[++(ptr->top)] = ch;
}

char pop(struct node *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return ptr->arr[(ptr->top)--];
}

int match_bracket(char a, char b) {
    return (a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')');
}

int checkParenthesis(struct node *exp) {
    struct node *brackets = malloc(sizeof(struct node));
    brackets->size = exp->size; // Use the same size as the input expression
    brackets->top = -1;

    int i;
    char ch;
    char b;
    
    for (i = 0; exp->arr[i] != '\0'; i++) {
        ch = exp->arr[i];

        if (ch == '[' || ch == '{' || ch == '(') {
            push(brackets, ch);
        } else if (ch == '}' || ch == ')' || ch == ']') {
            if (isEmpty(brackets)) {
                printf("Mismatched brackets: right brackets more than left brackets\n");
                return 0;
            }
            b = pop(brackets);
            if (!match_bracket(b, ch)) {
                printf("Mismatched brackets: incorrect matching\n");
                return 0;
            }
        }
    }
    
    if (!isEmpty(brackets)) {
        printf("Mismatched brackets: left brackets more than right brackets\n");
        return 0;
    } else {
        printf("The expression is well balanced\n");
        return 1;
    }
}

int main() {
    struct node *exp = malloc(sizeof(struct node));
    exp->size = 100;
    exp->top = -1;
    exp->arr = (char*)malloc(exp->size * sizeof(char));

    printf("Enter an expression: ");
    fgets(exp->arr, exp->size, stdin); // Use fgets to read input safely

    if (checkParenthesis(exp)) {
        printf("The given expression is balanced.\n");
    } else {
        printf("Mismatched Brackets\n");
    }

    free(exp->arr);
    free(exp);

    return 0;
}
