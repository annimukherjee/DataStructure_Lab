#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *start = NULL;

void insertHead(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (start == NULL)
    {
        newNode->next = newNode;
        start = newNode;
    }
    else
    {
        Node *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = start;
        start = newNode;
    }
}

void insertEnd(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (start == NULL)
    {
        newNode->next = newNode;
        start = newNode;
        return;
    }

    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = start;
}

void insertPos(int data, int pos)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (start == NULL || pos == 1)
    {
        insertHead(data);
        return;
    }

    Node *temp = start;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteHead()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (start->next == start)
    {
        free(start);
        start = NULL;
        return;
    }

    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }

    Node *toDelete = start;
    start = start->next;
    temp->next = start;

    free(toDelete);
}

void deleteEnd()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (start->next == start)
    {
        free(start);
        start = NULL;
        return;
    }

    Node *secondLast = start;
    while (secondLast->next->next != start)
    {
        secondLast = secondLast->next;
    }

    Node *toDelete = secondLast->next;
    secondLast->next = start;
    free(toDelete);
}

void deletePos(int pos)
{
    if (start == NULL || pos == 1)
    {
        deleteHead();
        return;
    }

    Node *temp = start;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void reverse()
{
    if (start == NULL || start->next == start)
    {
        return;
    }

    Node *prev = NULL;
    Node *current = start;
    Node *next;

    do
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    } while (current != start);

    start = prev;
}
void sort()
{

    Node *temp = start;

    while (temp->next != start)
    {

        Node *temp1 = temp->next;
        Node *tempNext = temp1->next;

        while (temp1 != start)
        {

            if (temp->data > temp1->data)
            {

                int t = temp->data;
                temp->data = temp1->data;
                temp1->data = t;

                temp->next = temp1->next;
                temp1->next = tempNext;
            }

            temp1 = temp1->next;
        }

        temp = temp->next;
    }
}
void display()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = start;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != start);

    printf("\n");
}

int main()
{
    int choice, data, pos;
    printf("1. Insert at head\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("4. Delete at head\n");
    printf("5. Delete at tail\n");
    printf("6. Delete at position\n");
    printf("7. Reverse\n");
    printf("8. Sort\n");
    printf("9. Display\n");
    printf("10. Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertHead(data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertEnd(data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertPos(data, pos);
            break;
        case 4:
            deleteHead();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePos(pos);
            break;
        case 7:
            reverse();
            break;
        case 8:
            sort();
            break;
        case 9:
            display();
            break;
        case 10:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 10);

    return 0;
}
