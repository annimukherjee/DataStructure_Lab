#include <stdio.h>
#include <stdlib.h>

// struct headerNode
// {
//     int length;
//     struct headerNode* next;

// }hn;

struct LinkedList
{
    int data;
    struct LinkedList *next;
};

typedef struct LinkedList node;

node *start = NULL;

// hn.next = start;

// Func Num: 1 --------------------------------------------------------
void create_LinkedList()
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

        temp = start; // taking a temp pointer and assgn to start to perfom operations with temp and not distub start.

        for (int i = 1; i < n; i++)
        {
            newnode = (node *)malloc(sizeof(node));

            printf("Enter data @ node %d: ", i);
            scanf("%d", &data_member);

            newnode->data = data_member;
            newnode->next = NULL;

            // Fixing the links
            temp->next = newnode; // Assigning the address of the new node to temp->next
            temp = newnode;       // Shifting temp to newnode's address.
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
void display_traverse()
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
                printf("\nNode %d's current memory loc: %p\n", counter, temp);
                printf("Node %d -->next: %p\n", counter, temp->next);
                temp = temp->next;
                counter++;
            }
            else
                printf("Invalid Input. Only 0 or 1 is accepted.\n");
        }
    }
}

void disp(node *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("%d ", head->data);
    if (head->next != NULL)
    {
        disp(head->next->next);
    }
    printf("%d ", head->data);
}

int main()
{
    create_LinkedList();
    display_traverse();
    printf("DISP OUTPUT\n\n-----------\n");
    disp(start);
    printf("\n");

    return 0;
}