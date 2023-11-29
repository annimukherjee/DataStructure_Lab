// 2205533_L8_P1_PrioQueueUsingArray

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAX_SIZE 5

void enqueue_with_priority(int);
void dequeue_with_priority(int);
void sort_insertion(int);
void display_priority_queue();

int priorityQueue[QUEUE_MAX_SIZE];
int front = -1, rear = -1;

int main()
{
    int number, choice;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be enqueued:\n");
            scanf("%d", &number);
            enqueue_with_priority(number);
            break;

        case 2:
            printf("Enter the value to be dequeued:\n");
            scanf("%d", &number);
            dequeue_with_priority(number);
            break;

        case 3:
            display_priority_queue();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Choice is not recognised. Please enter a valid option:\n");
            break;
        }
    }
}

void enqueue_with_priority(int value)
{
    if (rear >= QUEUE_MAX_SIZE - 1)
    {
        printf("Queue has reached maximum capacity.\n");
        return;
    }

    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        priorityQueue[rear] = value;
        return;
    }
    else
    {
        sort_insertion(value);
    }
    rear++;
}

void sort_insertion(int value)
{
    int i, j;
    for (i = 0; i <= rear; i++)
    {
        if (value >= priorityQueue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                priorityQueue[j] = priorityQueue[j - 1];
            }
            priorityQueue[i] = value;
            return;
        }
    }
    priorityQueue[i] = value;
}

void dequeue_with_priority(int value)
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    for (int i = 0; i <= rear; i++)
    {
        if (value == priorityQueue[i])
        {
            for (; i < rear; i++)
            {
                priorityQueue[i] = priorityQueue[i + 1];
            }
            priorityQueue[i] = -1; // Representing an empty space with -1
            rear--;

            if (rear == -1)
            {
                front = -1;
            }
            return;
        }
    }
    printf("\nValue %d is not in the queue to be dequeued.\n", value);
}

void display_priority_queue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", priorityQueue[i]);
    }
    printf("\n");
}
