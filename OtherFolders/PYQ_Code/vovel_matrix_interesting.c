#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    char buffer;

    printf("enter m and n respectively\n");
    scanf("%d", &m);
    scanf("%d%c", &n, &buffer);

    char *array;
    int total = m * n;

    array = (char *)malloc(total * sizeof(char));
    int x = total * sizeof(char);

    printf("m*n: %d\n", m * n);
    printf("x: %d\n", x);

    char *p = array;
    char *q = array;

    for (int i = 0; i < m * n; i++)
    {
        scanf("%c", array + i);
        printf("scanned at %d, %c\n", i, *(array + i));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", *p);
            p++;
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < total; i++)
    {
        if (q[i] == 'a' || q[i] == 'e' || q[i] == 'i' || q[i] == 'o' || q[i] == 'u')
        {
            for (int j = i + 1; j < total; j++)
            {
                q[j - 1] = q[j];
            }

            total--;
            q[total] = 'x';
        }
    }

    // printf("hi, main printing\n");

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         // printf("%c ", *(q + (m * i) + j));
    //         printf("%d", ((m * i) + j));
    //         // q++;
    //     }
    //     printf("\n");
    // }

    // for (int i = 0; i < m; i++)
    // {

    //     for (int j = 0; j < n; j++)
    //     {

    //         printf("%c ", *(q + (m * i) + j));
    //         // printf("%d", ((m * i) + j));
    //         // q++;
    //     }
    //     printf("\n");
    // }

    for (int i = 1; i <= m * n; i++)
    {

        printf("%c ", *(q + (i - 1)));

        if (i % n == 0)
            printf("\n");
    }
    return 0;
}