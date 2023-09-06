// 3.2. WAP to perform addition of two given sparse matrix in 3–tuple format.


#include <stdio.h>
#include <stdlib.h>

void addSparseMatrices(int[][3], int[][3], int[][3]);
char findRelation(int, int);

int main()
{

    int row, col, sparseMatrix1[10][3], sparseMatrix2[10][3], resultMatrix[10][3];

    // Input first sparse matrix
    printf("Enter no. of rows, columns and non-zero elements for Matrix1: ");
    scanf("%d%d%d", &sparseMatrix1[0][0], &sparseMatrix1[0][1], &sparseMatrix1[0][2]);
    printf("Enter the row#, column# and value: \n");
    for (row = 1; row <= sparseMatrix1[0][2]; row++)
        scanf("%d%d%d", &sparseMatrix1[row][0], &sparseMatrix1[row][1], &sparseMatrix1[row][2]);

    // Display first sparse matrix
    printf("\nSparse matrix 1: \n");
    for (row = 0; row <= sparseMatrix1[0][2]; row++)
    {
        for (col = 0; col < 3; col++)
            printf("%4d", sparseMatrix1[row][col]);
        printf("\n");
    }

    // Input second sparse matrix
    printf("Enter no. of rows, columns and non-zero elements for Matrix2: ");
    scanf("%d%d%d", &sparseMatrix2[0][0], &sparseMatrix2[0][1], &sparseMatrix2[0][2]);
    printf("Enter the row#, column# and value: \n");
    for (row = 1; row <= sparseMatrix2[0][2]; row++)
        scanf("%d%d%d", &sparseMatrix2[row][0], &sparseMatrix2[row][1], &sparseMatrix2[row][2]);

    // Display second sparse matrix
    printf("\nSparse matrix 2: \n");
    for (row = 0; row <= sparseMatrix2[0][2]; row++)
    {
        for (col = 0; col < 3; col++)
            printf("%4d", sparseMatrix2[row][col]);
        printf("\n");
    }

    // Add sparse matrices
    addSparseMatrices(sparseMatrix1, sparseMatrix2, resultMatrix);

    // Display the sum of the sparse matrices
    printf("\nSum of Sparse matrix 1 and 2: \n");
    for (row = 0; row <= resultMatrix[0][2]; row++)
    {
        for (col = 0; col < 3; col++)
            printf("%4d", resultMatrix[row][col]);
        printf("\n");
    }
    return 0;
}

// Function to compare two integers and return a relation
char findRelation(int a, int b)
{
    if (a < b)
        return '<';
    else if (a > b)
        return '>';
    else
        return '=';
}

// Function to add two sparse matrices
void addSparseMatrices(int mat1[][3], int mat2[][3], int sumMat[][3])
{
    // Validate if addition is possible
    if (mat1[0][0] != mat2[0][0] || mat1[0][1] != mat2[0][1])
    {
        printf("Invalid Addition. Order mismatch... \n");
        return;
    }

    sumMat[0][0] = mat1[0][0];
    sumMat[0][1] = mat1[0][1];
    int count1 = mat1[0][2];
    int count2 = mat2[0][2];
    int i = 1, j = 1, k = 0;

    while (i <= count1 && j <= count2)
    {
        k++;
        switch (findRelation(mat1[i][0], mat2[j][0]))
        {
        case '=':
            switch (findRelation(mat1[i][1], mat2[j][1]))
            {
            case '=':
                sumMat[k][0] = mat1[i][0];
                sumMat[k][1] = mat1[i][1];
                sumMat[k][2] = mat1[i][2] + mat2[j][2];
                i++;
                j++;
                break;
            case '<':
                sumMat[k][0] = mat1[i][0];
                sumMat[k][1] = mat1[i][1];
                sumMat[k][2] = mat1[i][2];
                i++;
                break;
            case '>':
                sumMat[k][0] = mat2[j][0];
                sumMat[k][1] = mat2[j][1];
                sumMat[k][2] = mat2[j][2];
                j++;
                break;
            }
            break;

        case '<':
            sumMat[k][0] = mat1[i][0];
            sumMat[k][1] = mat1[i][1];
            sumMat[k][2] = mat1[i][2];
            i++;
            break;
        case '>':
            sumMat[k][0] = mat2[j][0];
            sumMat[k][1] = mat2[j][1];
            sumMat[k][2] = mat2[j][2];
            j++;
            break;
        }
    }

    while (i <= count1)
    {
        k++;
        sumMat[k][0] = mat1[i][0];
        sumMat[k][1] = mat1[i][1];
        sumMat[k][2] = mat1[i][2];
        i++;
    }
    while (j <= count2)
    {
        k++;
        sumMat[k][0] = mat2[j][0];
        sumMat[k][1] = mat2[j][1];
        sumMat[k][2] = mat2[j][2];
        j++;
    }

    sumMat[0][2] = k;
}
