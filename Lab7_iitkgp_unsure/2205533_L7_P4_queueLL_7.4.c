// randomq_implement_queue_with_LL


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *front = NULL;
node *rear = NULL;

bool isEmpty(node *nodePtr);
void insert(int item);
void delete();
void display();

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Print\n4.Exit\nEnter choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted:\n");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

bool isEmpty(node *nodePtr)
{
    return nodePtr == NULL;
}

void insert(int item)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(front) && isEmpty(rear))
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("The node has been inserted.\n");
}

void delete()
{
    if (isEmpty(front))
    {
        printf("Underflow");
        return;
    }
    node *temp = front;
    front = front->next;
    int item = temp->data;
    free(temp);
    printf("\nThe value being dequeued is %d.\n", item);
}

void display()
{
    if (isEmpty(front))
    {
        printf("Queue is Empty\n");
        return;
    }
    node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
