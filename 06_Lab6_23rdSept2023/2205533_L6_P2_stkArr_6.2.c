// // Write a menu driven program to demonstrate the operations performed on stack using array and
// // suitable user defined functions for each case.
// // Operations: PUSH, POP, DISPLAY, EXIT

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StackStruct
{
    int top;
    int maxCapacity;
    int *elements;
};
typedef struct StackStruct Stack;

// Function definitions
Stack *createNewStack(int capacity);
bool is_Empty(Stack *stack);
bool is_Full(Stack *stack);
void pushElement(Stack *stack, int element);
int popElement(Stack *stack);
void displayStack(Stack *stack);

int main()
{
    int stackSize = 0;
    int choice, newElement, poppedElement, continueFlag = 1;
    printf("Enter the size of the stack:\n");
    scanf("%d", &stackSize);
    Stack *stack = createNewStack(stackSize);

    while (continueFlag == 1)
    {
        printf("\n===MENU===\n1.Push\n2.Pop\n3.Display\n4.Exit\n----\n");
        printf("Enter your choice:\n-->");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n---\nEnter the element to be inserted into the stack:\n");
            scanf("%d", &newElement);
            pushElement(stack, newElement);
            break;
        case 2:
            printf("\n---\n");
            poppedElement = popElement(stack);
            printf("%d has been popped from the stack\n", poppedElement);
            break;
        case 3:
            printf("\n---\n");
            displayStack(stack);
            break;
        case 4:
            continueFlag = 0;
            break;
        }
    }
    return 0;
}

Stack *createNewStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->maxCapacity = capacity;
    stack->top = -1;
    stack->elements = (int *)malloc(stack->maxCapacity * sizeof(int));
    return stack;
}

bool is_Empty(Stack *stack)
{
    return (stack->top == -1);
}

bool is_Full(Stack *stack)
{
    return (stack->top == (stack->maxCapacity - 1));
}

void pushElement(Stack *stack, int element)
{
    if (is_Full(stack))
    {
        printf("------------\nOVERFLOW, STACK IS FULL\n------------\n");
        return;
    }
    stack->top += 1;
    stack->elements[stack->top] = element;
    printf("%d has been pushed into the stack.\n", element);
}

int popElement(Stack *stack)
{
    if (is_Empty(stack))
    {
        printf("------------\nUNDERFLOW, STACK IS EMPTY\n------------\nExiting...\n");
        exit(0);
    }
    return stack->elements[stack->top--];
}

void displayStack(Stack *stack)
{
    if (is_Empty(stack))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("The elements present in the stack are:\n");
        for (int i = stack->top; i >= 0; i--)
        {
            printf("%d ", stack->elements[i]);
        }
        printf("\n");
    }
}
