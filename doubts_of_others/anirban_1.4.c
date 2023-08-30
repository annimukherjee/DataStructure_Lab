// WAP using dynamic memory allocation to find out the smallest and largest element stored in an array
// of n integers.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p, n, i, max, min;
    printf("Enter the value of n :");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    printf("enter elements :");
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i);
        
        if (*(p + i) > max)
        {
            max = *(p + i);
        }
        if (*(p + i) < min)
        {
            min = *(p + i);
        }
    }
    printf("Largest=%d\nSmallest=%d\n", max, min);
    free(p);
    return 0;
}