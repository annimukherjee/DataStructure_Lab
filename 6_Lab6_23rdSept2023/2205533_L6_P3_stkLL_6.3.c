// Write a menu driven program to demonstrate the operations performed on stack using linked list and
// suitable user defined functions for each case.
// Operations: PUSH, POP, DISPLAY, EXIT

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *nxt;
} *stkTop, *tmpTop, *tmp;

typedef struct node Stack;

int cnt = 0;

void push(int val);
int pop();
void display();

int main()
{
    int choice, val;
    printf("\nImplementation of Stack using Linked List\n");
    while (1)
    {
        printf("\n-----\n--MENU--\n1. Push\n2. Pop\n3. Display\n4. Exit\n----\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}

void push(int val)
{
    if (stkTop == NULL)
    {
        stkTop = (Stack *)malloc(1 * sizeof(Stack));
        stkTop->nxt = NULL;
        stkTop->val = val;
    }
    else
    {
        tmp = (Stack *)malloc(1 * sizeof(Stack));
        tmp->nxt = stkTop;
        tmp->val = val;
        stkTop = tmp;
    }
    cnt++;
    printf("Stack is Inserted\n\n");
}

int pop()
{
    tmpTop = stkTop;
    if (tmpTop == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
    {
        tmpTop = tmpTop->nxt;
    }

    int popped = stkTop->val;
    free(stkTop);
    stkTop = tmpTop;
    cnt--;
    return popped;
}

void display()
{
    tmpTop = stkTop;

    if (tmpTop == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }

    printf("The stack is \n");
    while (tmpTop != NULL)
    {
        printf("%d ", tmpTop->val);
        tmpTop = tmpTop->nxt;
    }
}
