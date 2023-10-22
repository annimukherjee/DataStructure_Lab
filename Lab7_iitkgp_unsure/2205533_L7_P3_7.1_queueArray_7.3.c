// Write a menu driven program to implement the following queue operations

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

int array[MAX];
int front = -1;
int rear = -1;

bool isEmpty();
void display();
void delete();
bool isFull();
void insert();

int main()
{
    int c = 1;
    int ch = 0;
    while (c == 1)
    {
        printf("\n1.Insert\n2.Delete\n3.Print\n4.Exit\nEnter choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            c = 0;
            exit(-1);
        }
    }
}

bool isEmpty()
{
    if (front == -1 || front > rear)
        return true;
    else
        return false;
}

bool isFull()
{
    if (rear == (MAX - 1))
        return true;
    else
        return false;
}

void insert()
{
    int item;
    if (isFull())
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        printf("\nEnter the value to be  inserted:\n");
        scanf("%d", &item);
        rear++;
        array[rear] = item;
    }
}

void delete()
{
    int item;
    if (isEmpty())
    {
        printf("Underflow");
        return;
    }
    else
    {
        item = array[front];
        front++;
        printf("\nThe item deleted from the queue is  %d.\n", item);
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}
