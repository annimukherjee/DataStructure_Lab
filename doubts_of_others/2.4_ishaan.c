#include <stdio.h>

int main()
{
    int m, n, i, j;
    printf("Enter the number of rows and columns(Square Matrix): ");
    scanf("%d %d", &m, &n);
    int a[m][n];


    printf("Enter the elements:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("The  matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }

    int count = 0;
    int row_sum = 0;
    int column_sum = 0;
    int row_avg = 0;
    int column_avg = 0;
    
    // Row Sums-----
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
                count++;

            row_sum = row_sum + a[i][j];
            if (j == n - 1)
            {
                row_avg = row_sum / n;
                printf("Row %d, Sum: %d, Average: %d\n", i + 1, row_sum, row_avg);
                row_sum = 0;
                row_avg = 0;
            }
        }
    }


    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            column_sum = column_sum + a[j][i];

            if (j == n - 1)
            {
                column_avg = column_sum / m;
                printf("Column %d ,Sum: %d, Average: %d\n", i + 1, column_sum, column_avg);
                column_sum = 0;
                column_avg = 0;
            }
        }
    }
    printf("The number of non-zero elements:%d\n", count);
    return 0;
}
