/*Write a menu driven program to perform the following operations in a Circular single linked list (using self referencing structure) by using suitable user defined functions for each case.
a. Create a list (Node Creation)
b. Display the list
c. Insert a node (at beginning/ at end / at any position)
d. Delete a node (at beginning/ at end / at any position)
e. Count the total number of nodes
f. Search for an element in the linked list*/

#include <stdio.h>
#include <stdlib.h>

struct CircularLinkedList
{
    int data;
    struct CircularLinkedList *next;
};

typedef struct CircularLinkedList cll;

cll *head = NULL;

void createCLL()
{
    int data_input;
    cll *newnode, *temp;

    if (head == NULL)
    {
        int n;
        printf("Enter the number of nodes to be created:\n");
        scanf("%d", &n);

        head = (cll *)malloc(sizeof(cll));
        printf("Enter the data for node 0: ");
        scanf("%d", &data_input);
        head->data = data_input;
        head->next = head; // points back to itself to make it circular

        temp = head;

        for (int i = 1; i < n; i++)
        {
            newnode = (cll *)malloc(sizeof(cll));
            printf("Enter the data for node %d: ", i);
            scanf("%d", &data_input);
            newnode->data = data_input;

            newnode->next = head;
            temp->next = newnode;
            temp = newnode;
        }
    }

    else
    {
        printf("A list has already been created\n");
    }
}

void traverseCLL()
{
    cll *temp;
    temp = head;
    int counter = 0;
    printf("\nThe elements in the list are:\n");
    while (temp->next != head)
    {
        printf("Data %d: %d\n", counter, temp->data);
        temp = temp->next;
        counter++;
    }
    printf("Data %d: %d\n", counter, temp->data); // as the temp stops at the last variable as temp->next=head therefore we print this separately
}

void insert_at_beg()
{
    cll *newnode;
    newnode = (cll *)malloc(sizeof(cll));
    printf("Enter the data you want to insert at beginning: ");
    scanf("%d", &newnode->data);

    newnode->next = head;

    cll *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    head = newnode;
}

void insert_at_end()
{
    cll *newnode;
    newnode = (cll *)malloc(sizeof(cll));
    printf("Enter the data you want to insert at end: ");
    scanf("%d", &newnode->data);

    cll *temp;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

void insert_at_pos()
{
    cll *newnode;
    newnode = (cll *)malloc(sizeof(cll));
    int pos;
    printf("Enter the data to insert: ");
    scanf("%d", &newnode->data);
    printf("Enter the position to insert at: ");
    scanf("%d", &pos);

    int i = 0;
    cll *temp;
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_at_beg()
{
    if (head == NULL)
    {
        printf("The list is empty.");
    }
    else
    {
        cll *temp;
        cll *last = head;
        temp = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
        printf("The element to be deleted is: %d", temp->data);
        free(temp);
    }
}

void delete_at_end()
{
    if (head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        cll *temp = head;
        cll *prev = head;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        printf("The element to be deleted is: %d", temp->data);
        free(temp);
    }
}

void delete_at_pos()
{
    cll *temp;
    cll *delnode;
    int pos = 0;
    delnode = (cll *)malloc(sizeof(cll *));
    printf("Enter the postion at to delete at: ");
    scanf("%d", &pos);
    int i = 0;
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    delnode = temp->next;
    temp->next = delnode->next;
    printf("The element to be deleted is: %d\n ", delnode->data);
    free(delnode);
}

void search()
{
    cll *temp = head;
    if (head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        int ele;
        int count = 0;
        int found = 0;
        printf("Enter the element to search: ");
        scanf("%d", &ele);
        do
        {
            if (temp->data == ele)
            {
                printf("The element %d was found successfully at position %d\n", ele, count);
                found = 1;
            }
            count++;
            temp = temp->next;

        } while (temp != head);

        if (found == 0)
        {
            printf("The element was %d not found in the list\n", ele);
        }
    }
}

void countnodes()
{
    cll *temp;
    temp = head;

    if (head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        int count = 0;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);

        printf("The number of nodes present in the list are: %d", count);
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
            createCLL();
            break;

        case 2:
            traverseCLL();
            break;

        case 3:
            insert_at_beg();
            traverseCLL();
            break;

        case 4:
            insert_at_end();
            traverseCLL();
            break;

        case 5:
            insert_at_pos();
            traverseCLL();
            break;

        case 6:
            delete_at_beg();
            traverseCLL();
            break;

        case 7:
            delete_at_end();
            traverseCLL();
            break;

        case 8:
            delete_at_pos();
            traverseCLL();
            break;

        case 9:
            countnodes();
            break;

        case 10:
            search();
            break;

        case 11:
            key = 0;
            break;

        default:
            printf("Invalid input");
        }
    }
    return 0;
}