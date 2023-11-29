#include <stdio.h>
#include <stdlib.h>
void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void Selection_ascending(int a[], int n)
{
    int i, j, loc, big;
    for (i = n - 1; i > 0; i--)
    {
        big = a[0];
        loc = 0;
        for (j = 1; j <= i; j++)
        {
            if (a[j] > big)
            {
                big = a[j];
                loc = j;
            }
        }
        a[loc] = a[i];
        a[i] = big;
    }
    printArray(a, n);
}
void Selection_descending(int a[], int n)
{
    int i, j, loc, big;
    for (i = n - 1; i > 0; i--)
    {
        big = a[0];
        loc = 0;
        for (j = 1; j <= i; j++)
        {
            if (a[j] < big)
            {
                big = a[j];
                loc = j;
            }
        }
        a[loc] = a[i];
        a[i] = big;
    }
    printArray(a, n);
}
int main()
{
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The ascending order of the array is: ");
    Selection_ascending(a, n);
    printf("\n");
    printf("The descending order of the array is: ");
    Selection_descending(a, n);
    return 0;
}