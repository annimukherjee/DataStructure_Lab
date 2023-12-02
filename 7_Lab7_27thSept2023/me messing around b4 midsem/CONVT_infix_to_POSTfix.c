// // 6.3. Write a Program  to convert an infix expression into its equivalent postfix expression using suitable
// // user defined function.

// // a+b*c
// // a+T

// // aT+

// // abc*+

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// struct StackStruct
// {
//     int top;
//     int maxCapacity;
//     int *elements;
// };
// typedef struct StackStruct Stack;

// Stack *createNewStack(int capacity);
// bool is_Empty(Stack *stack);
// bool is_Full(Stack *stack);
// void pushElement(Stack *stack, int element);
// int popElement(Stack *stack);
// void displayStack(Stack *stack);
// bool isOperand(char c);

// char *infixtoPost(char *);

// int main()
// {
//     char a[50];
//     printf("Enter a math expression\n");
//     scanf("%[^\n]s", a);

//     printf("%s\n", a);

//     printf("The postfix expresssion is: \n");
//     // printf("%s\n", infixtoPost(a));
//     printf("%d\n", isOperand('+'));
//     printf("%d\n", isOperand('-'));
//     printf("%d\n", isOperand('*'));
//     printf("%d\n", isOperand('/'));
//     printf("%d\n", isOperand('('));
//     printf("%d\n", isOperand(')'));

//     return 0;
// }

// char *infixtoPost(infix)
// {
//     Stack *stk = createNewStack(50);
//     char post[50];

//     post[0] = "";

//     int i = 0, k = 0;

//     while (*(infix + i) != '\0')
//     {
//         char item = *infix[i];

//         if (item == '(')
//         {
//             pushElement(stk, item);
//         }
//         if (isOperand(item) == false &&item != "(" &&item = "')")
//         {
//             post[k] = item;
//             k++;
//         }

//         i++;
//     }

//     return post;
// }

// bool isOperand(char c)
// {
//     char g[4] = {'+', '-', '*', '/'};

//     for (int i = 0; i < 4; i++)
//     {
//         if (c == g[i])
//         {
//             return true;
//         }
//     }
//     return false;
// }

// Stack *createNewStack(int capacity)
// {
//     Stack *stack = (Stack *)malloc(sizeof(Stack));
//     stack->maxCapacity = capacity;
//     stack->top = -1;
//     stack->elements = (int *)malloc(stack->maxCapacity * sizeof(int));
//     return stack;
// }

// bool is_Empty(Stack *stack)
// {
//     return (stack->top == -1);
// }

// bool is_Full(Stack *stack)
// {
//     return (stack->top == (stack->maxCapacity - 1));
// }

// void pushElement(Stack *stack, int element)
// {
//     if (is_Full(stack))
//     {
//         printf("------------\nOVERFLOW, STACK IS FULL\n------------\n");
//         return;
//     }
//     stack->top += 1;
//     stack->elements[stack->top] = element;
//     printf("%d has been pushed into the stack.\n", element);
// }

// int popElement(Stack *stack)
// {
//     if (is_Empty(stack))
//     {
//         printf("------------\nUNDERFLOW, STACK IS EMPTY\n------------\nExiting...\n");
//         exit(0);
//     }
//     return stack->elements[stack->top--];
// }

// void displayStack(Stack *stack)
// {
//     if (is_Empty(stack))
//     {
//         printf("Stack is empty.\n");
//     }
//     else
//     {
//         printf("The elements present in the stack are:\n");
//         for (int i = stack->top; i >= 0; i--)
//         {
//             printf("%d ", stack->elements[i]);
//         }
//         printf("\n");
//     }
// }

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x);
char pop();
int precedence(char x);

int main()
{
    char exp[100];
    char *e, x;

    printf("Enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c", *e);

        else if (*e == '(')
            push(*e);

        else if (*e == ')') // pop everything until u get (
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else // basically small lok cant sit on top of big lok or already present small
        {
            // say stack = { `(` `+` `*` } and `-` comes, then pop until all higher and equal is out, then push '-'
            // while (precedence(stack[top]) >= precedence(*e))
            while (precedence(*e) <= precedence(stack[top]))
                printf("%c ", pop());

            push(*e);
        }
        e++;
    }

    while (top != -1)
        printf("%c", pop());

    printf("\n");
    return 0;
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
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