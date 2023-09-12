#include <stdio.h>
#include <stdlib.h>

struct ls
{
    int data;
    struct ls *next;
    struct ls *prev;
};

typedef struct ls node;

node *start, *tail = NULL;

// void create()
// {

//     if (start == NULL) // will always be tru when u want to create a dll
//     {
//         int n, i, elem;

//         // printf("Enter the number of nodes (has to be 1 or more):\n");
//         // scanf("%d", &n);
//         n = 3;

//         node *p;
//         p = (node *)malloc(sizeof(node));

//         printf("Enter the 1st value of node:\n");
//         scanf("%d", &p->data);
//         p->next = NULL;
//         p->prev = NULL;

//         node *hi;

//         start = p;

//         printf("\n-\n");
//         printf("start next: %d\n", start->next);
//         printf("start data: %d\n", start->data);
//         printf("start prev: %d\n", start->prev);
//         printf("\n-\n");

//         for (int i = 1; i < 3; i++)
//         {
//             printf("\n-------\ni: %d\n----\n\n", i);
//             node *temp = (node *)malloc(sizeof(node));
//             if (i == 1)
//             {
//                 hi = start;
//             }
//             else
//             {
//                 hi = temp;
//             }

//             temp->next=NULL;
//             temp->prev=NULL;

//             printf("Enter the %dth value of node:\n", i + 1);

//             scanf("%d", &temp->data);

//             temp->next = NULL;
//             temp->prev = hi;
//             hi->next = temp;

//             printf("\n\nhi==start location %d\n", hi);

//             printf("\n%dth node next: \n", (i + 1));
//             printf("%d", temp->next);

//             printf("\n%dth node data: \n", (i + 1));
//             printf("%d", temp->data);

//             printf("\n%dth node prev:\n", (i + 1));
//             printf("%d", temp->prev);

//             printf("\n\ntemp location %d", temp);

//             printf("\nhi node next: %d\n", hi->next);
//             printf("hi th node prev: %d\n", hi->prev);
//             printf("hi th node data: %d\n", hi->data);
//         }
//     }

void create()
{
    node *newnode;
    node *temp;
    int n, i, elem;
    printf("Enter the number of nodes to be created:\n");
    scanf("%d", &n);
    start = (node *)malloc(sizeof(node));
    printf("Enter the data to be stored in the first node:\n");
    scanf("%d", &elem);
    start->data = elem;
    start->next = NULL;
    start->prev = NULL;

    temp = start;
    for (i = 2; i <= n; i++)
    {
        newnode = (node *)malloc(sizeof(node));

        printf("Enter data for node %d:\n", i);
        scanf("%d", &elem);

        newnode->data = elem;
        newnode->next = NULL;
        newnode->prev = temp;

        temp->next = newnode;

        temp = temp->next;
    }
}

// else
// {
//     for (int i = 0; i <= n; i++)
//     {
//     }
// }
// }

// void create()
// {
//     node *newnode;
//     node *temp;
//     if (start == NULL)
//     {
//         int n, i, elem;
//         printf("Enter the number of nodes:\n");
//         scanf("%d", &n);
//         printf("Enter the 1st value of node:\n");
//         scanf("%d", &elem);
//         temp = start;
//         for (i = 2; i <= n; i++)
//         {
//             newnode = malloc(sizeof(node));
//             if (newnode == NULL)
//             {
//                 printf("Memory cannot be allocated\n");
//             }
//             else
//             {
//                 printf("Enter data for node %d\n", i);
//                 scanf("%d", &elem);
//                 newnode->data = elem;
//                 newnode->next = NULL;
//                 newnode->prev = NULL;
//                 temp->next = newnode;
//                 temp = temp->next;
//                 temp->prev = newnode;
//             }
//         }
//         printf("The list was created successfully\n");
//     }
//     else
//     {
//         printf("The list was already created\n");
//     }
// }

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
    node *temp;
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
        temp = start;
        while (start != NULL)
        {
            temp = temp->next;
        }
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
    scanf("%d", &elem);
    scanf("%d", &pos);
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
        ptr->next = temp;
        ptr->prev = temp->prev;
        temp->prev = ptr;
    }
}

void delete()
{
    node *temp;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else if (start->next == NULL)
    {
        temp = start;
        start = start->next;
        printf("The deleted data:%d\n", temp->data);
        free(temp);
        start->prev = NULL;
    }
}

void delete_end()
{
    node *temp = start;
    if (start == NULL)
    {
        printf("Empty List\n");
    }
    else if (start->next == NULL)
    {
        start = start->next;
        printf("Deleted data:%d", temp->data);
        free(temp);
        start->prev = NULL;
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
        while (temp->next != NULL)
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
        char *strs[11];

        strs[0] = "1.Create a Node";
        strs[1] = "2.Display the list";
        strs[2] = "3.Insert the element at beginning";
        strs[3] = "4.Insert the element at the end";
        strs[4] = "5.Insert the element at specific position";
        strs[5] = "6.Delete the element from the beginning";
        strs[6] = "7.Delete the element from the end";
        strs[7] = "8.Delete the element from specific position";
        strs[8] = "9.Count the total number of nodes";
        strs[9] = "10.Search an element in the linked list";
        strs[10] = "11.Exit";
        printf("\n\n-----\n\n");
        for (int i = 0; i < 11; i++)
        {
            printf("%s\n", strs[i]);
        }

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