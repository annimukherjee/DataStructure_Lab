#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void insertionSort(int a[], int n, int order)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = a[i];

        while (j >= 0 && ((order == 1 && a[j] > temp) || (order == -1 && a[j] < temp)))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
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

    printf("The ascending order of the array is: ");
    insertionSort(a, n, 1);
    printArray(a, n);

    printf("\nThe descending order of the array is: ");
    insertionSort(a, n, -1);
    printArray(a, n);
    printf("\n");
    return 0;
}