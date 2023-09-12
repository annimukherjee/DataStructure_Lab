#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    int data;
    struct LinkedList *next;
};

typedef struct LinkedList node;
node *start = NULL;

void create()
{
    node *newnode, *temp;
    int n, i, elem;

    // i/p of number of nodes
    printf("Enter the number of nodes to be created:\n");
    scanf("%d", &n);

    start = (node *)malloc(sizeof(node)); // Allocate memory to start.

    // i/p of data of nodes
    printf("Enter the data to be stored in the first node:\n");
    scanf("%d", &elem);

    start->data = elem;
    start->next = NULL;

    temp = start; // taking a temp pointer and assgn to start to perfom operations with temp and not distub start.

    for (i = 2; i <= n; i++)
    {
        newnode = (node *)malloc(sizeof(node));

        printf("Enter data for node %d:\n", i);
        scanf("%d", &elem);

        newnode->data = elem;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
}

void traverse()
{
    node *temp;
    temp = start;

    if (temp == NULL)
        printf("List is Empty\n");

    else
    {
        while (temp != NULL)
        {
            printf("Data: %d\n", temp->data);
            temp = temp->next;
        }
    }
}

void insertAtFront()
{
    int elem;

    // Create the ele to be inserted
    node *p;
    p = malloc(sizeof(node));
    // --------------------------------

    printf("\nEnter number to be inserted :\n ");
    scanf("%d", &elem);

    p->data = elem;  // assgn the i/p to the insrtee
    p->next = start; // curr start is the next node for the intertee

    start = p;
}

void insertAtEnd()
{
    int elem;
    node *temp, *head;
    temp = malloc(sizeof(node));
    printf("\nEnter number to be inserted :\n ");
    scanf("%d", &elem);
    temp->next = 0;
    temp->data = elem;
    head = start;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;
}
void insertAtPosition()
{
    node *temp, *newnode;
    int pos, elem, i = 1;
    newnode = malloc(sizeof(node));
    printf("\nEnter position and data :\n");
    scanf("%d %d", &pos, &elem);
    temp = start;
    newnode->data = elem;
    newnode->next = 0;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void deleteFirst()
{
    node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        start = start->next;
        printf("Data to be deleted:%d\n", temp->data);
        free(temp);
    }
}
void deleteEnd()
{
    node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else
    {
        temp = start;
        while (temp->next != 0)
        {
            prevnode = temp;
            temp = temp->next;
        }
        printf("Data to be deleted:%d\n", temp->data);
        free(temp);
        prevnode->next = 0;
    }
}
void deletePosition()
{
    node *temp, *position;
    int i = 1, pos;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        position = malloc(sizeof(node));
        temp = start;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        position = temp->next;
        printf("Data to be deleted:%d\n", position->data);
        temp->next = position->next;
        free(position);
    }
}
void countNodes()
{
    int count = 0;
    node *temp = start;
    if (start == NULL)
    {
        count = 0;
    }
    else if (temp->next == NULL)
    {
        count = 1;
    }
    else
    {
        while ((temp != NULL))
        {
            count++;
            temp = temp->next;
        }
    }
    printf("The Number of nodes present:%d\n", count);
}
void search()
{
    node *temp = start;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        int elem;
        printf("Enter the element to be searched:\n");
        scanf("%d", &elem);
        while (temp != NULL)
        {
            if (temp->data == elem)
            {
                printf("%d was found in the list successfully\n", elem);
                exit(1);
            }
            temp = temp->next;
        }
        printf("%d was not found in the list\n", elem);
    }
}
int main()
{
    int key = 1;
    while (key == 1)
    {
        printf("1.Create a Node\n2.Display the list\n3.Insert the element at beginning\n4.Insert the element at the end\n5.Insert the element at specific position\n6.Delete the element from the beginning\n7.Delete the element from the end\n8.Delete the element from specific position\n9.Count the total number of nodes\n10.Search an element in the linked list\n11.Exit");
        printf("\nEnter choice:\n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            traverse();
            break;
        case 3:
            insertAtFront();
            break;
        case 4:
            insertAtEnd();
            break;
        case 5:
            insertAtPosition();
            break;
        case 6:
            deleteFirst();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            deletePosition();
            break;
        case 9:
            countNodes();
            break;
        case 10:
            search();
            break;
        case 11:
            key = 0;
            break;
        default:
            printf("\nInvalid input\n");
        }
    }
    return 0;
}