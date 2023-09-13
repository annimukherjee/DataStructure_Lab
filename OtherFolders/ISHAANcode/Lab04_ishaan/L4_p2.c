#include <stdio.h>
#include <stdlib.h>
struct ls
{
    int data;
    struct ls *next;
    struct ls *prev;
};
typedef struct ls node;
node *start = NULL;

void create()
{
    if (start == NULL)
    {
        node *newnode, *temp;
        int n, i, elem;
        printf("Enter the number of nodes to be created:\n");
        scanf("%d", &n);
        start = (node *)malloc(sizeof(node));
        printf("Enter the data for node 1:\n");
        scanf("%d", &elem);
        start->data = elem;
        start->next = NULL;
        start->prev = NULL;
        temp = start;
        for (i = 2; i <= n; i++)
        {
            newnode = (node *)malloc(sizeof(node));
            printf("Enter the data for node %d:\n", i);
            scanf("%d", &elem);
            newnode->data = elem;
            newnode->next = NULL;
            newnode->prev = temp;
            temp->next = newnode;
            temp = temp->next;
        }
        printf("List was created successfully\n");
    }
    else
    {
        printf("A list has already been created\n");
    }
}
void traverse()
{
    node *temp = start;
    if (start == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("Data: %d\n", temp->data);
            temp = temp->next;
        }
    }
}
void insert_begin()
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    printf("Enter the value to be inserted at the beginning:\n");
    int elem;
    scanf("%d", &elem);
    ptr->data = elem;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        ptr->next = start;
        start->prev = ptr;
        start = ptr;
    }
}
void insert_end()
{
    node *ptr;
    node *temp = start;
    ptr = (node *)malloc(sizeof(node));
    printf("Enter the value to be inserted at the last:\n");
    int elem;
    scanf("%d", &elem);
    ptr->data = elem;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->next;
        }
        ptr->data = elem;
        temp->next = ptr;
        ptr->prev = temp;
    }
}
void insert_pos()
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    node *temp = start;
    int elem, pos;
    printf("Enter the value and location at which you want to input the data:\n");
    scanf("%d %d", &elem, &pos);
    ptr->data = elem;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
        ptr->prev = temp;
        ptr->next = temp->next;
        temp->next = ptr;
    }
}
void delete()
{
    node *temp;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = start;
        start = start->next;
        printf("The deleted data:%d\n", temp->data);
        free(temp);
    }
}
void delete_end()
{
    node *temp = start;
    if (start == NULL)
    {
        printf("Empty List\n");
    }
    else if (temp->next == NULL)
    {
        start = NULL;
        printf("Deleted data:%d", temp->data);
        free(temp);
    }
    else
    {
        node *temp1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp1 = temp->prev;
        printf("Deleted data:%d\n", temp->data);
        temp = NULL;
        free(temp);
        temp1->next = NULL;
    }
}
void delete_pos()
{
    node *temp = start;
    if (start == NULL)
    {
        printf("Empty list\n");
    }
    else if (start->next == NULL)
    {
        start = NULL;
        printf("Data to be deleted:%d\n", temp->data);
        free(temp);
    }
    else
    {
        int pos;
        printf("Enter position from where it needs to be deleted:\n");
        scanf("%d", &pos);
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
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
    {
        count = 1;
    }
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
        while (temp->next != NULL)
        {
            if (temp->data == elem)
            {
                printf("Found %d in the list successfully", elem);
                exit(1);
            }
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