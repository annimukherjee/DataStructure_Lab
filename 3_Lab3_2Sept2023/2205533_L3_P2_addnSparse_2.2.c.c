// WAP to perform addition of two given sparse matrix in 3–tuple format.

#include <stdio.h>
int main()
{
    int i, j, a[10][10], b[10][10], sum[10][10];

    printf("Matrix 1:\n");
    printf("Enter the number of rows, columns and the number of values of sparse matrix:\n");
    printf("Total number of Rows: ");
    scanf("%d", &a[0][0]);
    printf("Total number of Columns: ");
    scanf("%d", &a[0][1]);
    printf("Total number of Number of values: ");
    scanf("%d", &a[0][2]);

    printf("Enter row and column number along with the value you want:\n");

    for (i = 1; i <= a[0][2]; i++)
    {
        printf("\nFor %dth value\n", i);
        printf("Enter row for %dth value: ", i);
        scanf("%d", &a[i][0]);
        printf("Enter col for %dth value: ", i);
        scanf("%d", &a[i][1]);
        printf("Enter value for this position: ");
        scanf("%d", &a[i][2]);

        // scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }

    printf("\nInput:\n-------\n");
    printf("%4c", 'R');
    printf("%6c", 'C');
    printf("%6c", 'E');

    printf("\n");

    for (i = 0; i <= a[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%4d  ", a[i][j]);
        }
        printf("\n");
    }

    int matrix[10][10];
    int r, c, nnz;
    r = a[0][0];
    c = a[0][1];
    nnz = a[0][2];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (i = 1; i <= a[0][2]; i++)
    {
        matrix[a[i][0]][a[i][1]] = a[i][2];
    }

    printf("\nThe matrix:\n--------\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n===\nMatrix 2:\n");
    printf("Enter the number of rows, columns and the number of values of sparse matrix:\n");
    printf("Total number of Rows: ");
    scanf("%d", &b[0][0]);
    printf("Total number of Columns: ");
    scanf("%d", &b[0][1]);
    printf("Total number of Number of values: ");
    scanf("%d", &b[0][2]);

    if (b[0][0]!=a[0][0] || b[0][1]!=a[0][1])
    {
        printf("\nERROR\n-------\nAddition not possible as rows!=cols\n");
        return (-1);
    }

    printf("Enter row and column number along with the value you want:\n");

    for (i = 1; i <= b[0][2]; i++)
    {
        printf("\nFor %dth value\n", i);
        printf("Enter row for %dth value: ", i);
        scanf("%d", &b[i][0]);
        printf("Enter col for %dth value", i);
        scanf("%d", &b[i][1]);
        printf("Enter value for this position: ");
        scanf("%d", &b[i][2]);

        // scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }

    
    

    printf("\nInput:\n-------\n");
    printf("%4c", 'R');
    printf("%6c", 'C');
    printf("%6c", 'E');

    printf("\n");

    for (i = 0; i <= b[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%4d  ", b[i][j]);
        }
        printf("\n");
    }


    int matrix1[10][10];
    int r1, c1, nnz1;
    r1 = b[0][0];
    c1 = b[0][1];
    nnz1 = b[0][2];
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            matrix1[i][j] = 0;
        }
    }

    for (i = 1; i <= b[0][2]; i++)
    {
        matrix1[b[i][0]][b[i][1]] = b[i][2];
    }

    printf("\nThe matrix:\n-----\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%6d", matrix1[i][j]);
        }
        printf("\n");
    }

    int size = 0;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            sum[i][j] = matrix[i][j] + matrix1[i][j];
        }
    }

    printf("\nSum Matrix:\n-----\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%6d", sum[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (sum[i][j] != 0)
            {
                size++;
            }
        }
    }

    int sparse[size + 1][3];
    sparse[0][0] = r1;
    sparse[0][1] = c1;
    sparse[0][2] = size;
    int l = 1;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (sum[i][j] != 0)
            {
                sparse[l][0] = i;
                sparse[l][1] = j;
                sparse[l][2] = sum[i][j];
                l++;
            }
        }
    }

    printf("Sum matrix:\nR  C  E\n");
    for (i = 0; i < (size + 1); i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d  ", sparse[i][j]);
        }
        printf("\n");
    }
    return 0;
}