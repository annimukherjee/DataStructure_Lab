#include <stdio.h>
#include <ctype.h>

// void push(char item);
// char pop();
int precedence(char x);
void convertToPostfix(char *exp);

char stack[100];
int top = -1;

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    if (top == -1)
        return -1;

    return stack[top--];
}

int main()
{
    char exp[100];

    printf("Enter the expression: ");
    scanf("%[^\n]s", exp);
    printf("\n");

    convertToPostfix(exp);

    return 0;
}

int precedence(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Function to convert infix to postfix
void convertToPostfix(char *exp)
{
    char *e = exp;
    char x;

    while (*e != '\0')
    {
        // Operand
        if (isalnum(*e))
            printf("%c ", *e);

        // Left parenthesis
        else if (*e == '(')
            push(*e);

        // Right parenthesis
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                printf("%c ", x);
        }

        // Operator
        else
        {
            while (precedence(stack[top]) >= precedence(*e))
                printf("%c ", pop());

            push(*e);
        }

        e++;
    }

    // Pop remaining operators
    while (top != -1)
        printf("%c ", pop());

    printf("\n");
}
