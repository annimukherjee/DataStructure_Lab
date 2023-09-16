#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    int data;
    struct LinkedList *next;
};

typedef struct LinkedList node;

node *start = NULL;

// Func Num: 1 --------------------------------------------------------
void create_the_LinkedList()
{
    node *newnode, *temp;
    int data_member;

    if (start == NULL)
    {
        // i/p of number of nodes
        int n; // Stores the number of nodes to be created.
        printf("Enter the number of nodes to be created:\n");
        scanf("%d", &n);

        start = (node *)malloc(sizeof(node)); // Allocate memory to start which was previously NULL.

        // i/p of data of 1st node
        printf("Enter the data to be stored in the 0th node:\n");
        scanf("%d", &data_member);

        start->data = data_member;
        start->next = NULL;

        temp = start; // taking a temp pointer and assgn to start to perfom operations with temp and not distub start.

        for (int i = 1; i < n; i++)
        {
            newnode = (node *)malloc(sizeof(node));

            printf("Enter data for node %d:\n", i);
            scanf("%d", &data_member);

            newnode->data = data_member;
            newnode->next = NULL;

            temp->next = newnode; // Assigning the address of the new node to temp->next

            temp = newnode; // Shifting temp to newnode's address.
            // OR
            // temp = temp->next;
        }
    }
    else
    {
        printf("A list has already been created. \n");
    }
}

// Func Num: 2 --------------------------------------------------------
void traverse()
{
    node *temp = start; // Performing operations with temp as we don't want to disturb start.
    int counter = 0;
    if (temp == NULL)
        printf("List is Empty\n");
    else
    {
        int memory = 0;
        printf("Display with memory locations [1]\nDisplay without memory locations [0]\n-->");
        scanf("%d", &memory);
        while (temp != NULL)
        {
            if (memory == 0)
            {
                printf("\n");
                printf("Data %d: %d-----\n", counter, temp->data);
                temp = temp->next;
                counter++;
            }
            else if (memory == 1)
            {
                printf("\n--------------\nData %d: %d\n", counter, temp->data);
                printf("\nNode %d's current memory loc: %p\n", counter, temp);
                printf("Node %d's next memory loc: %p\n", counter, temp->next);
                temp = temp->next;
                counter++;
            }
            else
            {
                printf("Invalid Input. Only 0 or 1 is accepted.");
            }
        }
    }
}

// Func Num: 3 --------------------------------------------------------
void insertAtFront()
{
    int insertee_data;

    // Create the node to be inserted
    node *p;
    p = (node *)malloc(sizeof(node));

    printf("\nEnter number to be inserted : ");
    scanf("%d", &insertee_data);

    p->data = insertee_data; // assgn the i/p to the insrtee
    p->next = start;         // curr start is the next node for the intertee

    start = p;
}

// Func Num: 4 --------------------------------------------------------
void insertAtEnd()
{
    int insertee_data;
    node *temp, *p = (node *)malloc(sizeof(node));

    printf("\nEnter number to be inserted: ");
    scanf("%d", &insertee_data);

    p->next = 0;
    p->data = insertee_data;

    temp = start;
    if (start != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    else
    {
        printf("No list was created. Creating one now.\n");
        start = p;
    }

    // free(temp);
    // free(p);
}

// Func Num: 5 --------------------------------------------------------
void insertAtPosition()
{
    node *temp, *p;
    int pos, insertee_data;
    p = (node *)malloc(sizeof(node));

    printf("\nEnter position and data : ");
    scanf("%d %d", &pos, &insertee_data);
    temp = start; // Performing operations with temp and not start.
    p->data = insertee_data;
    p->next = 0;

    int i = 0;
    while (i < pos-1)
    {
        temp = temp->next;
        i++;
    }

    p->next = temp->next; // Point the incoming node to the next node
    temp->next = p;       // Point the prev node to the address of the incoming node
}

// Func Num: 6 --------------------------------------------------------
void deleteFirst()
{
    node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        start = start->next; // Shifting start to the next node.
        printf("Data to be deleted:%d\n", temp->data);
        free(temp);
    }
}

// Func Num: 7 --------------------------------------------------------
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

// Func Num: 8 --------------------------------------------------------
void deletePosition()
{
    node *temp, *to_delete_node;

    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        int pos;
        printf("\nEnter index : ");
        scanf("%d", &pos);

        to_delete_node = (node *)malloc(sizeof(node));
        temp = start;

        int i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        to_delete_node = temp->next;
        printf("Data to be deleted: %d\n", to_delete_node->data);
        temp->next = to_delete_node->next;
        free(to_delete_node);
    }
}

// Func Num: 9 --------------------------------------------------------
void countNodes()
{
    int count = 0;
    node *temp = start;

    if (start == NULL)
        count = 0;

    else if (temp->next == NULL)
        count = 1;

    else
    {
        while ((temp != NULL))
        {
            count++;
            temp = temp->next;
        }
    }

    printf("The Number of nodes present: %d\n", count);
}

// Func Num: 10 --------------------------------------------------------
void search()
{
    node *temp = start;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        int counter = 0;
        int target;
        printf("Enter the element to be searched:\n");
        scanf("%d", &target);

        while (temp != NULL)
        {

            if (temp->data == target)
            {

                printf("%d was found in the list successfully at pos %d\n", target, counter);
                exit(1);
            }
            counter++;
            temp = temp->next;
        }
        printf("%d was not found in the list\n", target);
    }
}

int main()
{
    int key = 1;
    while (key == 1)
    {
        printf("\n\n##############################################\n1.Create a Node\n2.Display the list\n3.Insert the element at beginning\n4.Insert the element at the end\n5.Insert the element at specific position\n6.Delete the element from the beginning\n7.Delete the element from the end\n8.Delete the element from specific position\n9.Count the total number of nodes\n10.Search an element in the linked list\n11.Exit\n=====================***======================\n");

        printf("\nEnter choice\n-->");
        int choice;
        scanf("%d", &choice);
        printf("\n\n------------------------------\n");
        switch (choice)
        {
        case 1:
            create_the_LinkedList();
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