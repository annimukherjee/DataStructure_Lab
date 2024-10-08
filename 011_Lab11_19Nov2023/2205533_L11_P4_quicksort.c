#include <stdio.h>
#include <stdlib.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int partition(int a[], int beg, int end, int ascending)
{
    int pivotItem = a[end];
    int i = beg - 1;

    for (int j = beg; j < end; j++)
    {
        if (ascending)
        {
            if (a[j] <= pivotItem)
            {
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        else
        {
            if (a[j] >= pivotItem)
            {
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[end];
    a[end] = temp;

    return (i + 1);
}

void Quicksort(int a[], int beg, int end, int ascending)
{
    if (beg < end)
    {
        int pivot = partition(a, beg, end, ascending);
        Quicksort(a, beg, pivot - 1, ascending);
        Quicksort(a, pivot + 1, end, ascending);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int beg = 0;
    int end = n - 1;

    printf("The ascending order of the array is: ");
    Quicksort(a, beg, end, 1);
    printArray(a, n);

    printf("The descending order of the array is: ");
    Quicksort(a, beg, end, 0);
    printArray(a, n);
    printf("\n");
    return 0;
}