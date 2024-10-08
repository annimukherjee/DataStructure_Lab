#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *create_list(node *start);
void display(node *);
node *addtoempty(node *start, int data);
node *addatbeg(node *start, int data);
node *addatend(node *start, int data);
node *addafter(node *start, int data, int item);
node *del(node *start, int data);
int main()
{
    int choice, data, item;
    node *start = NULL;

    while (1)
    {
        printf("\n\n1.Create List\n");
        printf("2.Display\n");
        printf("3.Add to empty list\n");
        printf("4.Add at beginning\n");
        printf("5.Add at end\n");
        printf("6.Add after x element\n");
        printf("7.Delete x element\n");
        printf("8.Quit\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &data);
            start = addtoempty(start, data);
            break;
        case 4:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &data);
            start = addatbeg(start, data);
            break;
        case 5:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &data);
            start = addatend(start, data);
            break;
        case 6:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &data);
            printf("\nEnter the element after which to insert : ");
            scanf("%d", &item);
            start = addafter(start, data, item);
            break;
        case 7:
            printf("\nEnter the element to be deleted : ");
            scanf("%d", &data);
            start = del(start, data);
            break;
        case 8:
            exit(1);
        default:
            printf("\nWrong choice\n");
        }
    }
    return 0;
}
node *create_list(node *start)
{
    int i, n, data;
    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    printf("Enter the element to be inserted : ");
    scanf("%d", &data);
    start = addtoempty(start, data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
} /*End of create_list()*/

node *addtoempty(node *start, int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    start = temp;
    start->next = start;
    return start;
} /*End of addtoempty( )*/

node *addatbeg(node *start, int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = start->next;
    start->next = temp;
    return start;
} /*End of addatbeg( )*/

node *addatend(node *start, int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = start->next;
    start->next = temp;
    start = temp;
    return start;
} /*End of addatend( )*/

node *addafter(node *start, int data, int item)
{
    node *temp, *p;
    p = start->next;
    do
    {
        if (p->data == item)
        {
            temp = (node *)malloc(sizeof(node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            if (p == start)
                start = temp;
            return start;
        }
        p = p->next;
    } while (p != start->next);
    printf("%d not present in the list\n", item);
    return start;
} /*End of addafter()*/

node *del(node *start, int data)
{
    node *temp, *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    /*Deletion of only node*/
    if (start->next == start && start->data == data)
    {
        temp = start;
        start = NULL;
        free(temp);
        return start;
    }
    /*Deletion of first node*/
    if (start->next->data == data)
    {
        temp = start->next;
        start->next = temp->next;
        free(temp);
        return start;
    }
    /*Deletion in between*/
    p = start->next;
    while (p->next != start)
    {
        if (p->next->data == data)
        {
            temp = p->next;
            p->next = temp->next;
            free(temp);
            return start;
        }
        p = p->next;
    }
    /*Deletion of start node*/
    if (start->data == data)
    {
        temp = start;
        p->next = start->next;
        start = p;
        free(temp);
        return start;
    }
    printf("\nElement %d not found\n", data);
    return start;
} /*End of del( )*/

void display(node *start)
{
    node *p;
    if (start == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    p = start->next;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != start->next);
    printf("\n");
} /*End of display( )*/