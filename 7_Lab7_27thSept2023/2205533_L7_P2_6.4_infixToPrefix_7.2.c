// Write a Program to convert an infix expression into its equivalent prefix expression using suitable user defined function.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char elem)
{
    stack[++top] = elem;
}

char pop()
{
    return stack[top--];
}


// void push(char elem);
// char pop();
int precedence(char elem);

void convertToPrefix(char *infix, char *prefix);
void reverseString(char *str);

int main()
{
    char infix[50], prefix[50];

    printf("\n\nRead the Infix expression: ");
    scanf("%[^\n]s", infix);

    convertToPrefix(infix, prefix);

    printf("\n\nGiven infix expression: %s\nPrefix expression: %s\n", infix, prefix);

    return 0;
}



int precedence(char elem)
{
    switch (elem)
    {
    case '#':
        return 0;
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    default:
        return -1;
    }
}

void convertToPrefix(char *infix, char *prefix)
{
    int i = 0, k = 0;
    char ch, elem;

    push('#');
    reverseString(infix);

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == ')')
            push(ch);

        else if (isalnum(ch))
            prefix[k++] = ch;

        else if (ch == '(')
        {
            while (stack[top] != ')')
                prefix[k++] = pop();

            elem = pop();
        }
        
        else
        {
            while (precedence(stack[top]) >= precedence(ch))
                prefix[k++] = pop();

            push(ch);
        }
    }

    while (stack[top] != '#')
        prefix[k++] = pop();

    prefix[k] = '\0';
    reverseString(prefix);
    reverseString(infix);
}

void reverseString(char *str)
{
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
