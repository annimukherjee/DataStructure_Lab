// 3.3. WAP to represent the polynomial of single variable using 1-D array and perform the addition of two polynomial equations.

#include <stdio.h>
#include <stdlib.h>

struct Polynomial
{
    int coefficients[30]; // Coefficients of the polynomial
    int highestExponent;  // Highest exponent in the polynomial
};

typedef struct Polynomial Polynomial;

void initialisePolynomial(Polynomial *);
void createPolynomial(Polynomial *);
void displayPolynomial(Polynomial);
void addPolynomials(Polynomial, Polynomial, Polynomial *);

int main()
{
    Polynomial poly1, poly2, sumPoly;

    printf("1st polynomial\n");
    createPolynomial(&poly1);
    displayPolynomial(poly1);

    printf("\nThe second polynomial:\n");
    createPolynomial(&poly2);
    displayPolynomial(poly2);

    addPolynomials(poly1, poly2, &sumPoly);

    printf("\nSum:\n");
    displayPolynomial(sumPoly);
    printf("\n");
    return 0;
}

void initialisePolynomial(Polynomial *poly)
{
    int i;
    for (i = 0; i < 30; i++)
        poly->coefficients[i] = 0;

    poly->highestExponent = 0;
}

void createPolynomial(Polynomial *poly)
{
    // Initialise the polynomial
    initialisePolynomial(poly);
    int i;

    printf("Enter the highest exponent:\n");
    scanf("%d", &poly->highestExponent);

    if (poly->highestExponent >= 30)
    {
        printf("Invalid case\n");
        exit(-1);
    }

    printf("Enter the coefficients:\n");
    for (i = 0; i <= poly->highestExponent; i++)
        scanf("%d", &poly->coefficients[i]);
}

void displayPolynomial(Polynomial poly)
{
    int i;
    if (poly.coefficients[0] != 0)
        printf("%d + ", poly.coefficients[0]);
    for (i = 1; i <= poly.highestExponent - 1; i++)
    {
        if (poly.coefficients[i] == 1)
            printf("x^%d + ", i);
        else if (poly.coefficients[i] != 0)
            printf(" %dx^%d + ", poly.coefficients[i], i);
    }
    if (poly.coefficients[poly.highestExponent] != 0)
        printf("%dx^%d ", poly.coefficients[i], i);
}

// Function to add two polynomials
void addPolynomials(Polynomial poly1, Polynomial poly2, Polynomial *sumPoly)
{
    // Initialise the sum polynomial
    initialisePolynomial(sumPoly);

    int i;

    // Determine the highest exponent in the sum polynomial
    if (poly1.highestExponent > poly2.highestExponent)
        sumPoly->highestExponent = poly1.highestExponent;
    else
        sumPoly->highestExponent = poly2.highestExponent;

    // Perform the addition
    for (i = 0; i <= sumPoly->highestExponent; i++)
        sumPoly->coefficients[i] = poly1.coefficients[i] + poly2.coefficients[i];
}
