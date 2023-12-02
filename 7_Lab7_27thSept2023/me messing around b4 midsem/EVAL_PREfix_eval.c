#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX 20

int stack[MAX];
int top = -1;

void push(int x);
int pop();
void prefixeval(char[]);

int main()
{
    char prefix[20];
    printf("Enter string: ");
    scanf("%s", prefix);
    prefixeval(prefix);
    return 0;
}

// User defined funcs start.

void prefixeval(char prefix[])
{
    int len = strlen(prefix);
    
    for (int i = len - 1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            push(prefix[i] - '0'); // More readable than 48
        }
        else
        {
            int opp1 = pop();
            int opp2 = pop();
            int res;

            switch (prefix[i])
            {
            case '+':
                push(opp1 + opp2);
                break;
            case '-':
                push(opp1 - opp2);
                break;
            case '*':
                push(opp1 * opp2);
                break;
            case '/':
                if (opp2 != 0)
                    push(opp1 / opp2);
                else
                {
                    printf("Division by zero error.\n");
                    return;
                }
                break;
            case '^':
                res = pow(opp1, opp2);
                push(res);
                break;
            default:
                printf("Unsupported operator: %c\n", prefix[i]);
                return;
            }
        }
    }
    printf("Result is: %d\n", pop());
}

void push(int x)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
