// WAP to represent the polynomial of single variable using 1-D array and perform the addition of two 
// polynomial equations.

#include <stdio.h>
#include <stdlib.h>

struct polynomial
{
    int coeff[30];
    int exp;
};

typedef struct polynomial POLY;


// FUNCTION DECLARATIONS
void createpoly(POLY *);
void disp(POLY);
void addpoly(POLY, POLY, POLY *);
void init(POLY *);

int main()
{
    POLY p1, p2, p3;
    printf("1st polynomial\n");
    createpoly(&p1);
    disp(p1);

    printf("\nThe second polynomial:\n");
    createpoly(&p2);
    disp(p2);

    // ADDITION
    addpoly(p1, p2, &p3);

    // Display the sum
    printf("\nSum:\n");
    disp(p3);
    printf("\n");
    return 0;
}


void init(POLY *p)
{
    int i;
    for (i = 0; i < 30; i++)
    {
        p->coeff[i] = 0;
    }
    p->exp = 0;
}


void createpoly(POLY *p)
{
    init(p);
    
    int i;

    printf("Enter exponent:\n");
    scanf("%d", &p->exp);
    
    if (p->exp >= 30)
    {
        printf("Invalid case\n");
        exit(-1);
    }

    printf("Enter the elements:\n");
    for (i = 0; i <= p->exp; i++)
    {
        scanf("%d", &p->coeff[i]);
    }
}


void disp(POLY p)
{
    int i;
    if (p.coeff[0] != 0)
    {
        printf("%d +", p.coeff[0]);
    }
    for (i = 1; i <= p.exp - 1; i++)
    {
        if (p.coeff[i] == 1)
        {
            printf("x^%d + ", i);
        }
        else if (p.coeff[i] != 0)
        {
            printf(" %dx^%d +", p.coeff[i], i);
        }
    }
    if (p.coeff[p.exp - 1] != 0)
    {
        if (p.coeff[i] == 1)
            printf("x^%d ", i);
        else
            printf("%dx^%d ", p.coeff[i], i);
    }
}

void addpoly(POLY p1, POLY p2, POLY *p3)
{
    init(p3);
    int i;
    if (p1.exp > p2.exp)
    {
        p3->exp = p1.exp;
    }
    else
    {
        p3->exp = p2.exp;
    }
    for (i = 0; i <= p3->exp; i++)
    {
        p3->coeff[i] = p1.coeff[i] + p2.coeff[i];
    }
}
