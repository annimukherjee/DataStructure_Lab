#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v = 10;
    int *a;
    a = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        *(a + i) = v;
        v += 10;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", *(a + i));
    }

    printf("SIZEOF(a)/sizeof(int): %lu\n", sizeof(a) / sizeof(a[0]));

    return 0;
}