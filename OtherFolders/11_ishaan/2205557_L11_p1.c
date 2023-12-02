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


void Bubble_ascending(int a[], int n)
{
    int i, j, temp = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printArray(a, n);
}


void Bubble_descending(int a[], int n)
{
    int i, j, temp = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
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
    Bubble_ascending(a, n);
    printf("\n");
    printf("The descending order of the array is: ");
    Bubble_descending(a, n);
}