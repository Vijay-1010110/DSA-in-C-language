#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

int stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int symbol)
{
    if (top == (MAX - 1))
    {
        printf("\nStack Overflow!........\n");
        return;
    }
    stack[++top] = symbol;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow!");
        exit(0);
    }
    int x = stack[top--];
}

void removeSpaces(char *input)
{
    int i, j = 0;
    for (i = 0, j = 0; input[i] != '\0'; i++)
    {
        if (input[i] != ' ' && input[i] != '\t')
        {
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0'; // Null-terminate the string.
}

int precedence(char symbol)
{
    // higher value greater precedence
    switch (symbol)
    {
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

void infix2postfix()
{
    int i, j = 0;
    char symbol, next;
    // remove all white spaces
    removeSpaces(infix);
    int infix_len = strlen(infix);

    for (i = 0; i < infix_len; i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;

        case ')':
            while ((next = pop()) != '(')
                postfix[j++] = next;
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
            break;

        default:
            postfix[j++] = symbol;
        }
    }
    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int eval_postfix()
{
    int a, b, i;
    int post_len = strlen(postfix);
    for (i = 0; i < post_len; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0'); // it means for example '7' - '0' are equivalent to ascii(55 - 48) = 7 (int)
        }
        else
        {
            a = pop();
            b = pop();

            switch (postfix[i])
            {
            case '+':
                push(b + a);
                break;

            case '-':
                push(b - a);
                break;

            case '*':
                push(b * a);
                break;

            case '/':
                push(b / a);
                break;

            case '^':
                push(pow(b, a));
                break;
            }
        }
    }
    return pop();
}

void print()
{
    printf("The equivalent postfix expression is : ");
    int i = 0;
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

int main()
{

    printf("\nEnter an InFix Expression : \n");
    fgets(infix, MAX, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character.

    infix2postfix();
    print();

    int result = eval_postfix();
    printf("\nResult of the Postfix Expression : %d\n", result);
}
