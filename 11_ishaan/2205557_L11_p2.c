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
void Insertion_ascending(int a[], int n)
{
    int i, j, temp = 0;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printArray(a, n);
}
void Insertion_descending(int a[], int n)
{
    int i, j, temp = 0;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
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
    Insertion_ascending(a, n);
    printf("\n");
    printf("The descending order of the array is: ");
    Insertion_descending(a, n);
    return 0;
}