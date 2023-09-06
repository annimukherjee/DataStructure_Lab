#include <stdio.h>
#include <stdlib.h>

void addMatrix(int[][3], int[][3], int[][3]);
char findRel(int, int);

int main()
{
    int i, j, matrix1[10][3], matrix2[10][3], matrix3[10][3];
    printf("Enter no. of rows, columns and non-zero elements for Matrix:");

    scanf("%d%d%d", &matrix1[0][0], &matrix1[0][1], &matrix1[0][2]);

    printf("Enter the row#, column# and value: \n");

    for (i = 1; i <= matrix1[0][2]; i++)
        scanf("%d%d%d", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
    printf("\nSparse matrix 1: \n");

    for (i = 0; i <= matrix1[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%4d", matrix1[i][j]);
        printf("\n");
    }

    printf("Enter no. of rows, columns and non-zero elements for Matrix2:");

    scanf("%d%d%d", &matrix2[0][0], &matrix2[0][1], &matrix2[0][2]);

    printf("Enter the row#, column# and value: \n");

    for (i = 1; i <= matrix2[0][2]; i++)
        scanf("%d%d%d", &matrix2[i][0], &matrix2[i][1], &matrix2[i][2]);

    printf("\nSparse matrix 2: \n");
    for (i = 0; i <= matrix2[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%4d", matrix2[i][j]);
        printf("\n");
    }

    addMatrix(matrix1, matrix2, matrix3);

    printf("\nSum of Sparse matrix 1 and 2: \n");

    for (i = 0; i <= matrix3[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%4d", matrix3[i][j]);
        printf("\n");
    }
    return 0;
}

char findRel(int a, int b)
{
    if (a < b)
        return ('<');
    else if (a > b)
        return ('>');
    else
        return ('=');
}

void addMatrix(int mat1[][3], int mat2[][3], int mat3[][3])
{
    int i, j, k, m, n;
    if (mat1[0][0] != mat2[0][0] || mat1[0][1] != mat2[0][1])
    {
        printf("Invalid Addition. Order mismatch... \n");
        return;
    }
    mat3[0][0] = mat1[0][0];
    mat3[0][1] = mat1[0][1];
    m = mat1[0][2];
    n = mat2[0][2];

    i = 1;
    j = 1;
    k = 0;

    while (i <= m && j <= n)
    {
        k++;
        switch (findRel(mat1[i][0], mat2[j][0]))
        {
        case '=':

            switch (findRel(mat1[i][1], mat2[j][1]))
            {
            case '=':
                mat3[k][0] = mat1[i][0];
                mat3[k][1] = mat1[i][1];
                mat3[k][2] = mat1[i][2] + mat2[j][2];
                i++;
                j++;
                break;
            case '<':
                mat3[k][0] = mat1[i][0];
                mat3[k][1] = mat1[i][1];
                mat3[k][2] = mat1[i][2];
                i++;
                break;
            case '>':
                mat3[k][0] = mat2[j][0];
                mat3[k][1] = mat2[j][1];
                mat3[k][2] = mat2[j][2];
                j++;
                break;
            }
            break;

        case '<':
            mat3[k][0] = mat1[i][0];
            mat3[k][1] = mat1[i][1];
            mat3[k][2] = mat1[i][2];
            i++;
            break;
        case '>':
            mat3[k][0] = mat2[j][0];
            mat3[k][1] = mat2[j][1];
            mat3[k][2] = mat2[j][2];
            j++;
            break;
        }
    }
    while (i <= m)
    {
        k++;
        mat3[k][0] = mat1[i][0];
        mat3[k][1] = mat1[i][1];
        mat3[k][2] = mat1[i][2];
        i++;
    }
    while (j <= n)
    {
        k++;
        mat3[k][0] = mat2[j][0];
        mat3[k][1] = mat2[j][1];
        mat3[k][2] = mat2[j][2];
        j++;
    }
    mat3[0][2] = k;
}