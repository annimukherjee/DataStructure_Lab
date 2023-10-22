// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack *stack)
{
    int to_push;
    to_push = 0;
    printf("Enter element to push\n");
    scanf("%d", &to_push);

    if (isFull(stack))
        return;
    stack->array[++stack->top] = to_push;
    printf("%d pushed to stack\n", to_push);
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

void disp(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct Stack *temp = stack;
        printf("%d, temptop\n", temp->top);
        while (temp->top > 0)
        {
            printf("%d ", stack->array[temp->top]);
            temp->top--;
        }
    }
}

// Driver program to test above functions
int main()
{
    struct Stack *stack = createStack(100);
    int key = 1;
    while (key)
    {

        int choice;
        printf("\n------------\n");
        printf("1 push\n");
        printf("2 pop\n");
        printf("3 peek\n");
        printf("4 disp\n");
        printf("5 exit\n-->");
        scanf("%d", &choice);
        printf("\n------------\n\n");

        switch (choice)
        {
        case 1:

            push(stack);
            break;
        case 2:
            printf("Popped element: %d\n", pop(stack));
            break;
        case 3:
            printf("%d\n", peek(stack));
            break;
        case 4:
            disp(stack);
        case 5:
            exit(0);
            break;

        default:
            printf("wrong input\n");
            break;
        }

        // // push(stack, 10);
        // // push(stack, 20);
        // // push(stack, 30);

        // printf("%d popped from stack\n", pop(stack));
    }

    return 0;
}
