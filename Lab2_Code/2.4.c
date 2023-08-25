#include <stdio.h>
int main()
{
    int m, n, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int a[m][n];

    printf("Enter the elements:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nThe  matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }


    int count = 0;
    int row_sum=0, column_sum=0, row_avg=0, column_avg = 0;

    int col_counter=0;
    

    printf("\nRows-----------------\n");
    for (i = 0; i < m; i++)
    {
        col_counter++;
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                count++;
            }


            row_sum = row_sum + a[i][j];
            if (j == n - 1)
            {
                row_avg = row_sum / m;

                printf("Row %d...\nSum: %d,\nAverage:%d\n\n", i + 1, row_sum, row_avg);
                row_sum = 0;
                row_avg = 0;
            }

            
        }

        
    }

    printf("\n\nColumns-----------------------\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            column_sum = column_sum + a[j][i];
        }

        printf("Col %d...\nSum: %d,\nAverage: %d\n\n", i+1, column_sum, column_sum/n);
        column_sum = 0;
    }




    printf("The number of non-zero elements:%d\n", count);
    return 0;
}