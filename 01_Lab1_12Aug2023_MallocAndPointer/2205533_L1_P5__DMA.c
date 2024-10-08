// 1.5. WAP using pointer, dynamic memory allocation to search an element in an array of n numbers.

// Input: Enter the value of n: 5
// Enter the elements: 10 20 50 35 22
// Enter the element to be search: 50
// Output: 50 exists at index 2


#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the number of elements: ");
    int n, *array;
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));
    
    printf("Enter the elements: ");
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