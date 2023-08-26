#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j;
    int *ptr;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }
    printf("The original array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
    int b[n];
    for (j = n - 1; j >= 0; j--)
    {
        b[j] = *ptr;
        ptr++;
    }
    printf("\nThe reversed array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    return 0;
}