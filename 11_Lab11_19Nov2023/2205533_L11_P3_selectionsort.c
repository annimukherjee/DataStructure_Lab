#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int a[], int n, int order)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (order == 1 && a[j] < a[min_idx])
            {
                min_idx = j;
            }
            else if (order == -1 && a[j] > a[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&a[min_idx], &a[i]);
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
        scanf("%d", &a[i]);

    printf("The ascending order of the array is: ");
    selectionSort(a, n, 1);
    printf("\n");
    printf("The descending order of the array is: ");
    selectionSort(a, n, -1);
    printf("\n");
}