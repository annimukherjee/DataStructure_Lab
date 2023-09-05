// WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include <stdio.h>
int main()
{
    int i, j, a[10][3];
    printf("Enter the number of rows, columns and the number of values of sparse matrix:\n");
    scanf("%d %d %d", &a[0][0], &a[0][1], &a[0][2]);
    printf("Enter row and column number along with the value you want:\n");

    for (i = 1; i <= a[0][2]; i++)
    {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }

    printf("Input:\nR  C  E\n");
    for (i = 0; i <= a[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d  ", a[i][j]);
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

    // for (i = 1; i <= a[0][0]; i++)


    for (i = 1; i <= a[0][2]; i++)
    {
        matrix[a[i][0]][a[i][1]] = a[i][2];
    }

    printf("The matrix:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    int transpose[10][10];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("The transpose:\n");
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%4d", transpose[i][j]);
        }
        printf("\n");
    }
    int smat[10][10];
    smat[0][0] = a[0][1];
    smat[0][1] = a[0][0];
    smat[0][2] = a[0][2];
    int k = 1;
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            if (transpose[i][j] != 0)
            {
                smat[k][0] = i;
                smat[k][1] = j;
                smat[k][2] = transpose[i][j];
                k++;
            }
        }
    }
    printf("Output\nR  C  E\n");
    for (i = 0; i <= smat[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d  ", smat[i][j]);
        }
        printf("\n");
    }
    return 0;
}