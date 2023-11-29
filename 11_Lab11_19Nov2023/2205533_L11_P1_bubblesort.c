#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

}

void bubbleSort(int a[], int n, int order)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (order == 1 && a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else if (order == -1 && a[i] < a[j])
            {
                int temp = a[i];
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
        scanf("%d", &a[i]);

    printf("The ascending order of the array is: ");
    bubbleSort(a, n, 1);
    printf("\n");
    printf("The descending order of the array is: ");
    bubbleSort(a, n, -1);
    printf("\n");
}