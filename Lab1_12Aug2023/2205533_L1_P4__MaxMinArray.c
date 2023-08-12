// 1.4. WAP using dynamic memory allocation to find out the smallest and largest element stored
// in an array of n integers.
// Input: Enter the value of n: 7
// Enter the elements: 10, 20, 15, 25, 90, 45, 80
// Output: Smallest: 10 and Largest: 90

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *array;

    printf("What is the length of your array");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    int max, min;
    max = array[0];
    min = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];

        if (array[i] < min)
            min = array[i];
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
