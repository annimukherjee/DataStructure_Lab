#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *, int, int);

int main()
{
    // int a[] = {40, 30, 50, 10, 5};
    int n;
    printf("Input size of array\n");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("[value?](%d) ", i);
        scanf("%d", a + i);
    }
    int asc;
    printf("Ascending[1] or Descending[0]?\n");
    scanf("%d", &asc);

    for (int i = 0; i < n; i++)
    {
        printf("[%d](%d) ", a[i], i);
    }

    insertion_sort(a, asc, n);

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("[%d](%d) ", a[i], i);
    }
    printf("\n");

    return 0;
}

void insertion_sort(int *a, int asc, int n)
{
    if (asc == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int temp = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > temp)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            int temp = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] < temp)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
    }
}