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
    printf("\n\nPoly p1 is created. Displying now...\n");
    displayPoly(p1);
    printf("\n--------\n");

    p2 = createPoly(p2);
    printf("\nPoly p2 is created. Displying now...\n");
    displayPoly(p2);

    printf("\n\n----------\nNow performing Addition\n\n");
    printf("The added polyomial is --> ");

    displayPoly(addPoly(p1, p2));

    return 0;
}

poly *createPoly(poly *p)
{
    int exp_1;
    printf("Enter the degree (max power) of the poly you're trying to create: ");
    scanf("%d", &exp_1);

    poly *newNode;
    poly *prev;

    for (int i = exp_1; i >= 0; i--)
    {
        newNode = (poly *)malloc(sizeof(poly));
        printf("Enter coeff of x^%d: ", i);
        scanf("%d", &newNode->coeff);

        newNode->exp = i;
        newNode->next = NULL;

        if (p == NULL)
            p = newNode;
        else
            prev->next = newNode;

        prev = newNode;
    }

    return p;
}

void displayPoly(poly *p)
{

    while (p->next != NULL)
    {
        if (p->coeff != 0)
            printf("%dx^%d + ", p->coeff, p->exp);
        p = p->next;
    }
    if (p->coeff != 0)
        printf("%dx^%d", p->coeff, p->exp);
    printf("\n");
}

poly *addPoly(poly *p, poly *q)
{
    poly *result_poly = NULL;

    while (p != NULL && q != NULL)
    {
        poly *prev;
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

        if (result_poly == NULL)
            result_poly = newNode;
        else
            prev->next = newNode;

        prev = newNode;
    }

    return result_poly;
}

//                 10x^2 + 20x^1 + 30x^0 +
// 10x^4 + 20x^3 + 30x^2 + 40x^1 + 50x^0 +

// 10x^4 + 20x^3 + 40x^2 + 60x^1 + 80x^0 +