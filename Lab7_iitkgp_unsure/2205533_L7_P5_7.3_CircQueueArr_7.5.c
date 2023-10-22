// 7.3 Write a menu driven program to implement of Circular queue operations using array. The operation 
// are such as :-  
// 1.  Insert  
// 2.  Delete  
// 3.  Display 
// 4.  Exit 


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50
int array[MAX];
int front = -1;
int rear = -1;
bool isEmpty()
{
    if (front == -1 || front > rear)
        return true;
    else
        return false;
}
bool isFull()
{
    if (front == (rear + 1) % MAX)
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
        {
            front = 0;
            rear = 0;
        }
        printf("\nEnter the value to be  inserted:\n");
        scanf("%d", &item);
        rear = (rear + 1) % MAX;
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
    if (front == rear)
    {
        item = array[front];
        front = -1;
        rear = -1;
    }
    else
    {
        item = array[front];
        front = (front + 1) % MAX;
    }
    printf("\nThe item deleted from the queue is  %d.\n", item);
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
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
        }
        else
        {
            for (i = front; i < MAX - 1; i++)
            {
                printf("%d ", array[i]);
            }
            for (i = 0; i < rear; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int c = 1;
    int ch = 0;
    while (c = 1)
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