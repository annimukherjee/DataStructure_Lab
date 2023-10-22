#include <stdio.h>
#include <stdlib.h>
struct ls
{
    int coeff;
    int exponent;
    struct ls *next;
};
typedef struct ls node;
node *start = NULL;
void create(node *p)
{
    node *temp;
    int n, i, coefficient;
    printf("Enter the maximum value of X:\n ");
    scanf("%d", &n);
    start = (node *)malloc(sizeof(node));
    printf("Enter the coefficient of degree %d:\n", n);
    scanf("%d", &coefficient);
    start->coeff = coefficient;
    start->exponent = n;
    start->next = NULL;
    temp = start;
    for (i = n - 1; i >= 0; i--)
    {
        p = (node *)malloc(sizeof(node));
        printf("Enter the coefficient of degree %d:\n", i);
        scanf("%d", &coefficient);
        p->coeff = coefficient;
        p->exponent = i;
        p->next = NULL;
        temp->next = p;
        temp = temp->next;
    }
}
void printPoly(node *p)
{
    node *temp = start->next;
    node *temp1 = temp->next;
    if (start->coeff != 0)
    {
        if (start->coeff == 1)
        {
            printf("X^%d+ ", start->exponent);
        }
        else
        {
            printf("%dX^%d+ ", start->coeff, start->exponent);
        }
    }
    while (temp1->next != NULL)
    {
        if (temp->coeff != 0)
        {
            if (temp->coeff == 1)
            {
                printf("X^%d+ ", temp->exponent);
            }
            else
            {
                printf("%dX^%d+ ", temp->coeff, temp->exponent);
            }
        }
        temp = temp->next;
        temp1 = temp1->next;
    }
    if (temp->coeff != 0)
    {
        if (temp->coeff == 1)
        {
            printf("X^%d+ ", temp->exponent);
        }
        else
        {
            printf("%dX^%d+ ", temp->coeff, temp->exponent);
        }
    }
    if (temp1->coeff != 0)
    {
        printf("%d\n", temp1->coeff);
    }
}
void Sumation(node *p1, node *p2)
{
    node *ptr1 = p1;
    node *ptr2 = p2;
    node *p3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exponent == ptr2->exponent)
        {
            p3->coeff = ptr1->coeff + ptr2->coeff;
            p3->exponent = p1->exponent;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->exponent > ptr2->exponent)
        {
            p3->coeff = ptr1->coeff;
            p3->exponent = p1->exponent;
            ptr1 = ptr1->next;
        }
        else if (ptr1->exponent < ptr2->exponent)
        {
            p3->coeff = ptr2->coeff;
            p3->exponent = ptr2->exponent;
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        p3->coeff = ptr1->coeff;
        p3->exponent = ptr1->exponent;
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        p3->coeff = ptr2->coeff;
        p3->exponent = ptr2->exponent;
        ptr2 = ptr2->next;
    }
    printf("Added polynomial:\n");
    printPoly(p3);
}
int main()
{
    node *p1;
    node *p2;
    printf("Polynomial 1:\n");
    create(p1);
    printPoly(p1);
    printf("Polynomial 2:\n");
    create(p2);
    printPoly(p2);
    Sumation(p1, p2);
}