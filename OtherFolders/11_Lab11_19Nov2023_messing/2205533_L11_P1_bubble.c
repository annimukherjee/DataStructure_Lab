#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *, int, int);


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

    bubble_sort(a, asc, n);

    for (int i = 0; i < n; i++)
    {
        printf("[%d](%d) ", a[i], i);
    }
    printf("\n");

    return 0;
}

void bubble_sort(int *arr, int asc, int n)
{
    printf("\n\nBubble sort started\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (asc == 1)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            else if (asc == 0)
            {
                if (arr[i] < arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            else
            {
                printf("Invalid. Enter either 1 or 0 for asc or desc.\nExit\n");
                exit(-1);
            }
        }
    }
    printf("Finished...\n\n");
}
