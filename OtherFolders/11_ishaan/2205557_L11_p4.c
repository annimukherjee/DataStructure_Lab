#include <stdio.h>
#include <stdlib.h>

void printArray(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
}

int partition_ascending(int a[], int beg, int end)
{
    int pivotItem, i, j, temp;
    pivotItem = a[end];
    i = beg - 1;
    for (j = beg; j < end; j++)
    {
        if (a[j] <= pivotItem)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[end];
    a[end] = temp;
    return (i + 1);
}

void Quicksort_ascending(int a[], int beg, int end)
{
    int pivot;
    if (beg < end)
    {
        pivot = partition_ascending(a, beg, end);
        Quicksort_ascending(a, beg, pivot - 1);
        Quicksort_ascending(a, pivot + 1, end);
    }
}

int partition_descending(int a[], int beg, int end)
{
    int pivotItem, i, j, temp;
    pivotItem = a[end];
    i = beg - 1;
    for (j = beg; j < end; j++)
    {
        if (a[j] >= pivotItem)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[end];
    a[end] = temp;
    return (i + 1);
}

void Quicksort_descending(int a[], int beg, int end)
{
    int pivot;
    if (beg < end)
    {
        pivot = partition_descending(a, beg, end);
        Quicksort_descending(a, beg, pivot - 1);
        Quicksort_descending(a, pivot + 1, end);
    }
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
    int beg = 0;
    int end = n - 1;

    printf("The ascending order of the array is: ");
    Quicksort_ascending(a, beg, end);
    printArray(a, n);
    printf("\n");

    printf("The descending order of the array is: ");
    Quicksort_descending(a, beg, end);
    printArray(a, n);

    return 0;
}
