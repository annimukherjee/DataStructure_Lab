// Add two polynomials and implement a polynomial in Linked List
#include <stdio.h>
#include <stdlib.h>

struct Polynomial
{
    int coeff;
    int exp;
    struct Polynomial *next;
};

typedef struct Polynomial poly;

poly *node;

poly *createPoly(poly *p);
void displayPoly(poly *po);
poly *addPoly(poly *p, poly *q);

int main()
{
    poly *p1 = NULL;
    poly *p2 = NULL;
    p1 = createPoly(p1);
    printf("Poly p1 is created. Displying now...\n");
    printf("add of p1: %p\n", p1);
    displayPoly(p1);
    p2 = createPoly(p2);
    printf("Poly p2 is created. Displying now...\n");
    displayPoly(p2);

    printf("\n\nNOW performing Addition\n\n");
    printf("The added polyomial is: \n");

    displayPoly(addPoly(p1, p2));

    return 0;
}

poly *createPoly(poly *p)
{
    int exp_1;
    printf("Enter the degree (max power) of poly1: ");
    scanf("%d", &exp_1);

    poly *newNode;
    poly *prev;

    for (int i = exp_1; i >= 0; i--)
    {
        printf("i: [%d]\n-----\n", i);
        newNode = (poly *)malloc(sizeof(poly));
        printf("Address of NewNode just after MALLOC: %p\n", newNode);
        printf("Enter coeff of x^%d: ", i);
        scanf("%d", &newNode->coeff);

        newNode->exp = i;
        newNode->next = NULL;

        printf("newNode->coeff: %d\nnewNode->exp: %d\n", newNode->coeff, newNode->exp);

        if (p == NULL)
        {
            printf("Entered if p==NULL\n");
            printf("Address of p: %p\n", p);
            p = newNode;
            printf("Address of p: %p\n", p);
            printf("p->exp: %d\n", p->exp);
            printf("p->coeff: %d\n", p->coeff);
        }
        else
        {
            prev->next = newNode;
            printf("Entered else\n");
        }
        prev = newNode;
        printf("Address of prev: %p\n", prev);
    }

    printf("Address of p in create: %p\n", p);
    return p;
}

void displayPoly(poly *po)
{

    printf("entered display!!\n");
    printf("What is po address: %p\n", po);
    while (po != NULL)
    {
        printf("%dx^%d + ", po->coeff, po->exp);
        po = po->next;
    }
    printf("\n");
}

poly *addPoly(poly *p, poly *q)
{
    poly *added = NULL;

    while (p != NULL && q != NULL)
    {
        poly* prev;
        poly *newNode = (poly *)malloc(sizeof(poly));

        if (p->exp > q->exp)
        {
            newNode->coeff = p->coeff;
            newNode->exp = p->exp;
            p = p->next;
        }

        else if (p->exp < q->exp)
        {
            newNode->coeff = q->coeff;
            newNode->exp = q->exp;
            q = q->next;
        }

        else
        {
            newNode->coeff = p->coeff + q->coeff;
            newNode->exp = p->exp;
            p = p->next;
            q = q->next;
        }

        newNode->next = NULL;

        if (added == NULL)
        {
            added = newNode;
        }
        else
        {
            prev->next = newNode;
        }
        prev = newNode;
    }

    return added;
}


//                 10x^2 + 20x^1 + 30x^0 + 
// 10x^4 + 20x^3 + 30x^2 + 40x^1 + 50x^0 + 

// 10x^4 + 20x^3 + 40x^2 + 60x^1 + 80x^0 + 