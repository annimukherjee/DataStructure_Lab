#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the number of elements: ");
    int n, *array;
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    int search;
    printf("Enter the element to be searched: ");
    scanf("%d", &search);

    for (int i = 0; i < n; i++)
    {
        if (array[i] == search)
        {
            printf("Element \"%d\" found at index \"%d\" \n", array[i], i);
            break;
        }
    }

    return 0;
}