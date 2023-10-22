#include <stdio.h>

int main()
{
    int a[9] = {8, 7, 6, 5, 4, 3, 2, 1, 0};

    for (int i = 0; i < 9; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    for (int i = 0; i < 9; i += 2)
    {
        for (int j = i + 2; j < 9; j += 2)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\n-------\nhi\n-----\n");

    for (int i = 0; i < 9; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}