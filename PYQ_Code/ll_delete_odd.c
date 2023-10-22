#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start = NULL;


void createLL();
void print_list();
int count_odd();
void delete_odd_ele(int odds);

int main()
{
    createLL();
    printf("Linked List Created\n");

    printf("Prinitng inputted LL now: \n");
    print_list();




    printf("Travaersing through LL now: \n");
    int odds = count_odd();


    delete_odd_ele(odds);

    printf("Updated LL-------\nNow Printing\n");
    print_list();
    return 0;
}

void createLL()
{
    int num;
    printf("Enter the number of nodes in LL: ");
    scanf("%d", &num);


    NODE *prev;

    int c = 0;
    for (int i = 0; i < num; i++)
    {
        NODE *newNode = (NODE *)malloc(sizeof(NODE));
        if (start == NULL)
        {
            start = newNode;
            printf("Enter data @ %d: \n", i);
            scanf("%d", &newNode->data);
            prev = start;
            start->next = NULL;
        }
        else
        {
            prev->next = newNode;
            printf("Enter data @ %d: \n", i);
            scanf("%d", &newNode->data);
            newNode->next = NULL;
            prev = newNode;
        }
    }
}


int count_odd()
{
    int c = 0;
    NODE *temp = start;

    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
            c++;
        
        temp = temp->next;
    }

    printf("Number of ODD: %d\n", c);
    return c;
}





void delete_odd_ele(int odds)
{
    for (int i = 0; i < odds; i++)
    {
        int c = 0;
        NODE *temp = start;
        NODE *prev = temp;

        while (temp != NULL)
        {
            if (temp->data % 2 != 0)
            {
                if (temp == start)
                {
                    start = start->next;
                    printf("DELETED (b): %d\n", temp->data);
                    prev->next = NULL;
                    free(temp);

                    break;
                }

                else if (temp->next == NULL)
                {
                    prev->next = NULL;
                    printf("DELETED (e): %d\n", temp->data);
                    free(temp);
                    break;
                }
                else
                {
                    prev->next = temp->next;
                    temp->next = NULL;
                    printf("DELETED (m): %d\n", temp->data);
                    free(temp);
                    break;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }
}

// if (temp == start)
// {
//     // delete_at_beg()
//     printf("delete at beg\n");
//     start = start->next;
//     printf("DELETED: %d\n", temp->data);
//     prev->next = NULL;
//     free(temp);
//     temp = start;
//     temp = temp->next;
//     prev = temp;
// }
// else if(temp->next == NULL)
// {
//     // printf("delete at middle\n")
//     printf("delete at end\n");

// }
// else
// {
//     printf("delete at middle\n");
// }
// else
// {
//     temp = temp->next;
// }
// else
// {
//     prev = temp;
//     temp = temp->next;
// }

void print_list()
{
    NODE *temp = start;

    while (temp != NULL)
    {
        printf("%d---> ", temp->data);
        // printf("temp: %p\n", temp);
        // printf("temp->next: %p\n= = = = = = =\n", temp->next);

        temp = temp->next;
    }
    printf("\n");
}

// void traverse(NODE *start)
// {
//     NODE *temp = start;
//     NODE *prev = start;

//     while (temp != NULL)
//     {
//         NODE *p = temp;
//         printf("%d\n", p->data);
//         if (p->data % 2 != 0)
//         {
//             printf("inside if: %d\n", p->data);
//             if (p == start)
//             {
//                 printf("p is start...\n");
//                 start = start->next;
//                 printf("data deleted: %d", p->data);
//                 // free(p);
//             }
//         }
//         //     else if (p->next==NULL)
//         //     {
//         //         prev->next=NULL;
//         //         printf("data deleted: %d", p->data);
//         //         free(p);
//         //     }
//         //     else
//         //     {
//         //         prev->next = p->next;
//         //         printf("data deleted: %d", p->data);
//         //         free(p);

//         //     }
//         // }

//         NODE *prev = temp;
//         temp = temp->next;
//     }
//     printf("\n");
// }
