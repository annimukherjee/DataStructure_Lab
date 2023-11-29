#include <stdio.h>
#include <stdlib.h>

void printArray(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", *(a + i));

    printf("\n");
}

void merge(int a[], int beg, int mid, int end, int order)
{
    int b[50], l, r, i;
    l = beg;
    r = mid + 1;
    i = beg;

    while (l <= mid && r <= end)
    {
        if ((order == 1 && a[l] < a[r]) || (order == -1 && a[l] > a[r]))
            b[i++] = a[l++];
        else
            b[i++] = a[r++];
    }

    while (l <= mid)
        b[i++] = a[l++];

    while (r <= end)
        b[i++] = a[r++];

    for (i = beg; i <= end; i++)
        a[i] = b[i];
}

void merge_sort(int a[], int beg, int end, int order)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        merge_sort(a, beg, mid, order);
        merge_sort(a, mid + 1, end, order);
        merge(a, beg, mid, end, order);
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
        scanf("%d", &a[i]);

    merge_sort(a, 0, n - 1, 1); // Sort in ascending order
    printf("The ascending order of the array is: ");
    printArray(a, n);

    merge_sort(a, 0, n - 1, -1); // Sort in descending order
    printf("The descending order of the array is: ");
    printArray(a, n);
    printf("\n");
    return 0;
}
