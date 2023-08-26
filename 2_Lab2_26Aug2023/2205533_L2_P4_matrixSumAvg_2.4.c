// 2.4. WAP to create a nXn matrix and perform the following: 
// e. Find the number of non zero elements 
// f. Sum and average of elements row wise 
// g. Sum and average of elements column wise

#include <stdio.h>
int main()
{
    int i, j;
    float m , n;
    printf("Enter the number of rows and columns: ");
    scanf("%f %f", &m, &n);
    int m_ = (int)m;
    int n_ = (int)n;

    int a[m_][n_];

    printf("Enter the elements:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    printf("\nThe  matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3d ", a[i][j]);

        printf("\n");
    }

    int count = 0;
    int row_sum = 0, column_sum = 0;

    int col_counter = 0;

    printf("\nRows-----------------\n");

    for (i = 0; i < m; i++)
    {
        col_counter++;
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
                count++;

            row_sum = row_sum + a[i][j];
        }
        printf("Row %d...\nSum: %d\nAverage: %.2f\n\n", i + 1, row_sum, row_sum / n);
        row_sum=0;
    }


printf("\n\nColumns-----------------------\n");
for (i = 0; i < n; i++)
{
    for (j = 0; j < m; j++)
        column_sum = column_sum + a[j][i];

    printf("Col %d...\nSum: %d\nAverage: %.2f\n\n", i + 1, column_sum, column_sum / m);
    column_sum = 0;
}

printf("The number of non-zero elements: %d\n", count);
return 0;
}
