// 3.1. WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include <stdio.h>
struct Element
{
    int row, col, value;
};

typedef struct Element SPARSE_ELE;

void sortElements(SPARSE_ELE mat[], int nz);
void read(SPARSE_ELE mat[], int *m, int *n, int *nz);
void transpose(SPARSE_ELE mat[], SPARSE_ELE t[], int m, int n, int nz);
void display(SPARSE_ELE matrix[], int nz);

int main()
{
    SPARSE_ELE matrix[100], t[100];
    int m, n, nz;

    read(matrix, &m, &n, &nz);
    printf("\nOriginal Sparse Matrix:\n");
    display(matrix, nz);

    transpose(matrix, t, m, n, nz);
    printf("\nTransposed Sparse Matrix:\n");
    display(t, nz);

    return 0;
}

// Sort the elements based on their row and column
void sortElements(SPARSE_ELE mat[], int nz)
{
    SPARSE_ELE temp;
    for (int i = 0; i < nz - 1; i++)
    {
        for (int j = i + 1; j < nz; j++)
        {
            if (mat[i].row > mat[j].row || (mat[i].row == mat[j].row && mat[i].col > mat[j].col))
            {
                temp = mat[i];
                mat[i] = mat[j];
                mat[j] = temp;
            }
        }
    }
}

// Read sparse matrix in 3-tuple format
void read(SPARSE_ELE mat[], int *m, int *n, int *nz)
{
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", m, n);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", nz);

    printf("Enter the elements (row, column, value):\n");
    for (int i = 0; i < *nz; i++)
    {
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].value);
    }
}

void transpose(SPARSE_ELE mat[], SPARSE_ELE t[], int m, int n, int nz)
{
    // Initialize transposeMatrix
    for (int i = 0; i < nz; i++)
    {
        t[i].row = mat[i].col;     // row and col are swapped
        t[i].col = mat[i].row;     // row and col are swapped
        t[i].value = mat[i].value; // value remains same
    }
}

// Display a sparse matrix in 3-tuple format
void display(SPARSE_ELE matrix[], int nz)
{
    // Sort the elements
    sortElements(matrix, nz);

    printf("Sparse Matrix (row, column, value):\n");
    for (int i = 0; i < nz; i++)
    {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value); // print the elements
    }
}
