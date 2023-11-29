/*Write a menu driven program for PQ implementation with array options: insert, delete, display, exit.*/

#include <stdio.h>

#define SIZE 50

typedef struct
{
    int data[SIZE];
    int front;
    int rear;
} pQueue;

void pInsert(pQueue *q, int item);
void pDelete(pQueue *q);
void pDisplay(pQueue *q);
int isEmpty(pQueue *q);
int isFull(pQueue *q);

int main()
{
    pQueue q;
    q.front = -1;
    q.rear = -1;
    int choice;
    int item;

    do
    {
        printf("\n1. Insert an element \n");
        printf("2. Delete an element \n");
        printf("3. Display the queue \n");
        printf("4. Exit \n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &item);
            pInsert(&q, item);
            break;
        case 2:
            pDelete(&q);
            break;
        case 3:
            pDisplay(&q);
            break;
        case 4:
            printf("Exiting program... \n");
            break;
        default:
            printf("Enter number from 1 to 4 \n");
            break;
        }
    } while (choice != 4);

    return 0;
}

void pInsert(pQueue *q, int item)
{
    if (isFull(q))
    {
        printf("Overflow\n");
        return;
    }
    else if (isEmpty(q))
    {
        q->front++;
        q->rear++;
        q->data[q->rear] = item;
    }
    else
    {
        int i;
        for (i = q->rear; i >= 0 && item > q->data[i]; i--) // Check priority and insert
        {
            q->data[i + 1] = q->data[i];
        }
        q->data[i + 1] = item;
        q->rear++;
    }
}

void pDelete(pQueue *q)
{
    if (isEmpty(q))
    {
        printf("Underflow \n");
        return;
    }

    int minIndex = 0;
    for (int i = 1; i <= q->rear; i++)
    {
        if (q->data[i] < q->data[minIndex])
        {
            minIndex = i;
        }
    }

    while (minIndex < q->rear)
    {
        q->data[minIndex] = q->data[minIndex + 1];
        minIndex++;
    }

    q->rear--;
    if (q->rear == -1)
    {
        q->front = -1;
    }
}

void pDisplay(pQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty \n");
        return;
    }
    printf("Queue elements: \n");
    while (q->front <= q->rear)
    {
        printf("%d\n", q->data[q->front]);
        q->front++;
    }
    q->front = 0;
}

int isEmpty(pQueue *q)
{
    return (q->front == -1 && q->rear == -1);
}

int isFull(pQueue *q)
{
    return (q->rear == SIZE - 1);
}