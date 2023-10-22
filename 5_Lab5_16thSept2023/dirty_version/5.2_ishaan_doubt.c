#include <stdio.h>
#include <stdlib.h>

struct ls
{
    int data;
    struct ls *next;
};

typedef struct ls node;
node *start = NULL;

void insert_end()
{
    node *newnode, *temp;
    int elem;
    printf("Enter the element to be inserted at the end:\n");
    scanf("%d", &elem);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = elem;
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
        newnode->next = start;
    }
    else
    {
        temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = start;
    }
}

void insert_beg()
{
    node *newnode, *temp;
    printf("Enter the element to be added at the beginning:\n");
    int elem;
    scanf("%d", &elem);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = elem;
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
        newnode->next = start;
    }
    else
    {
        temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = start;
        start = newnode;
    }
}

void insert_pos()
{
    node *newnode, *temp = start;
    node *temp1;
    int pos, i, elem;
    printf("Enter the position where you want to insert the element:\n");
    scanf("%d", &pos);
    printf("Enter the element you wish to enter to the list at the respective position:\n");
    scanf("%d", &elem);
    newnode->data = elem;
    newnode->next = NULL;
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = newnode;
    newnode->next = temp1;
}

void delete_beg()
{
    node *temp, *temp1;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else if (start->next == start)
    {
        temp = start;
        start = NULL;
        printf("%d is being deleted from the list.\n");
        free(temp);
    }
    else
    {
        temp = start;
        start = start->next;
        printf("%d is now being deleted.\n");
        free(temp);
    }
}
void delete_end()
{
    node *temp = start;
    node *temp1;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else if (start->next == start)
    {
        temp = start;
        start = NULL;
        printf("%d is being deleted from the list\n");
        free(temp);
    }
    else
    {
        while (temp->next->next != start)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = start;
        printf("%d is being deleted.\n", temp1->data);
        free(temp1);
    }
}

void delete_pos()
{
    node *temp = start;
    node *temp1;
    int pos, i;
    printf("Enter the position at which the element needs to be deleted:\n");
    scanf("%d", &pos);
    for (i = 1; i <= pos; i++)
    {
        temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    printf("%d is being deleted from the list", temp1->data);
    temp1 = NULL;
    free(temp1);
}

void traverse()
{
        
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        // if (temp == start)
        // {
        //     printf("temp and start, they are equal sad\n");
        // }
        node *temp = start;

        while (temp->next != start)
        {
            printf("Data:%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    printf("\nCircular list\n");
    int ch = 1;
    int c = 1;
    int elem;
    while (ch == 1)
    {
        printf("\n Enter choice:\n");
        printf("1.Insert at the beginning of Circular List.\n2.Insert at ending of circular list.\n3.Insert at a specific  position\n4.Delete from start\n5.Delete from end\n6.Delete from position\n7.Print the circular list\n8.Exit\n-->");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert_beg();
            break;
            
        case 2:
            insert_end();
            break;
        case 3:
            insert_pos();
            break;
        case 4:
            delete_beg();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_pos();
            break;
        case 7:
            traverse();
            break;
        case 8:
            ch = 0;
            break;
        default:
            printf("Wrong input");
        }
    }
    return 0;
}