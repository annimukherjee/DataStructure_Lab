#include <stdio.h>
#include <stdlib.h>
struct DoubleLinkedList
{
    int data;
    struct DoubleLinkedList *next;
    struct DoubleLinkedList *prev;
};

typedef struct DoubleLinkedList node;

node *start = NULL;

void create_the_LinkedList()
{
    node *newnode, *temp;
    int data_member;

    if (start == NULL)
    {
        // i/p of number of nodes
        int n; // Stores the number of nodes to be created.
        printf("Enter the number of nodes to be created: ");
        scanf("%d", &n);

        start = (node *)malloc(sizeof(node)); // Allocate memory to start which was previously NULL.

        // i/p of data of 1st node
        printf("Enter data @ 0th node: ");
        scanf("%d", &data_member);

        start->data = data_member;
        start->next = NULL;
        start->prev = NULL;

        temp = start; // taking a temp pointer and assgn to start to perfom operations with temp and not distub start.

        for (int i = 1; i < n; i++)
        {
            newnode = (node *)malloc(sizeof(node));

            printf("Data @ node %d: ", i);
            scanf("%d", &data_member);

            newnode->data = data_member;

            newnode->next = NULL;
            newnode->prev = temp;

            temp->next = newnode; // Assigning the address of the new node to temp->next

            // temp = newnode; // Shifting temp to newnode's address.
            // OR
            temp = temp->next;
        }
        printf("List was created successfully\n");
    }
    else
        printf("A list has already been created. \n");
}

void traverse()
{
    node *temp = start; // Performing operations with temp as we don't want to disturb start.
    int counter = 0;
    if (temp == NULL)
        printf("List is Empty\n");
    else
    {
        int memory = 0;
        printf("[1]-Display with memory locations\n[0]-Display without memory locations\n-->");
        scanf("%d", &memory);
        while (temp != NULL)
        {
            if (memory == 0)
            {
                printf("\n");
                printf("Data %d: %d-----", counter, temp->data);
                temp = temp->next;
                counter++;
            }
            else if (memory == 1)
            {
                printf("\n--------------\nData %d: %d\n", counter, temp->data);
                printf("\nNode %d's-->prev: %p", counter, temp->prev);
                printf("\nNode %d's current memory loc: %p\n", counter, temp);
                printf("Node %d's-->next: %p\n", counter, temp->next);
                temp = temp->next;
                counter++;
            }
            else
                printf("Invalid Input. Only 0 or 1 is accepted.\n");
        }
    }
}

// Func Num: 3 --------------------------------------------------------
void insert_begin()
{
    int insertee_data;

    // Create the node to be inserted
    node *p;
    p = (node *)malloc(sizeof(node));

    printf("\nEnter number to be inserted : ");
    scanf("%d", &insertee_data);

    p->data = insertee_data; // assgn the i/p to the insrtee
    p->next = start;         // curr start is the next node for the intertee

    p->data = insertee_data;
    p->next = NULL;
    p->prev = NULL;

    if (start == NULL)
        start = p;
    else
    {
        p->next = start;
        start->prev = p;
        start = p;
    }

    start = p;
}

void insert_end()
{
    node *p, *temp = start;
    p = (node *)malloc(sizeof(node));

    printf("Enter the value to be inserted at the last:\n");
    int insertee_data;
    scanf("%d", &insertee_data);
    p->data = insertee_data;
    p->next = NULL;
    p->prev = NULL;

    if (start == NULL)
    {
        start = p;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        p->data = insertee_data;
        temp->next = p;
        p->prev = temp;
    }
}

void insert_pos()
{
    node *p;
    p = (node *)malloc(sizeof(node));

    node *temp = start;
    int insertee_data, pos;

    printf("Enter position and data: ");
    scanf("%d %d", &pos, &insertee_data);
    p->data = insertee_data;
    p->next = NULL;
    p->prev = NULL;

    if (start == NULL)
        start = p;
    else
    {
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        p->prev = temp;
        p->next = temp->next;
        temp->next = p;
    }
}

void delete()
{
    node *temp;
    if (start == NULL)
        printf("List is empty\n");
    else
    {
        temp = start;
        start = start->next;
        printf("The deleted data: %d---\n", temp->data);
        free(temp);
    }
}

void delete_end()
{
    node *temp = start;
    if (start == NULL)
        printf("Empty List\n");
    else if (temp->next == NULL)
    {
        start = NULL;
        printf("Deleted data: %d---", temp->data);
        free(temp);
    }
    else
    {
        node *temp1;
        while (temp->next != NULL)
            temp = temp->next;
        temp1 = temp->prev;
        printf("Deleted data: %d---\n", temp->data);
        temp = NULL;
        free(temp);
        temp1->next = NULL;
    }
}

void delete_pos()
{
    node *temp = start;
    if (start == NULL)
        printf("Empty list\n");
    else if (start->next == NULL)
    {
        start = NULL;
        printf("Data to be deleted:%d\n", temp->data);
        free(temp);
    }
    else
    {
        int pos;
        printf("Enter position from where data needs to be deleted: ");
        scanf("%d", &pos);
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("Data to be deleted:%d\n", temp->data);
        temp = NULL;
        free(temp);
    }
}

void countNodes()
{
    node *temp = start;
    int count = 0;
    if (start == NULL)
        count = 0;
    else if (temp->next == NULL)
        count = 1;
    else
    {
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
    }
    printf("The Number of nodes: %d\n", count);
}

void search()
{
    node *temp = start;
    int elem;
    printf("Enter the element to be searched:\n");
    scanf("%d", &elem);
    if (start == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        int pos = 0;
        while (temp->next != NULL)
        {

            if (temp->data == elem)
            {
                printf("Found %d in the list successfully @ position %d\n", elem, pos);
                return;
            }
            pos++;
            temp = temp->next;
        }
    }
}

int main()
{
    int key = 1;
    while (key == 1)
    {
        printf("\n\n----\n\n");
        printf("1. Create a Node\n2. Display the list\n\n3. Insert the element at beginning\n4. Insert the element at the end\n5. Insert the element at specific position\n\n6. Delete the element from the beginning\n7. Delete the element from the end\n8. Delete the element from specific position\n\n9. Count the total number of nodes\n10. Search an element in the linked list\n11. Exit");
        printf("\nEnter choice:\n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_the_LinkedList();
            break;
        case 2:
            traverse();
            break;
        case 3:
            insert_begin();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            insert_pos();
            break;
        case 6:
            delete ();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            delete_pos();
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