#include <stdio.h>

struct Element
{
    int row, col, value;
};

// Sort the elements based on their row and column
void sortElements(struct Element mat[], int nz)
{
    struct Element temp;
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
void read(struct Element mat[], int *m, int *n, int *nz)
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

void transpose(struct Element mat[], struct Element t[], int m, int n, int nz)
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
void display(struct Element matrix[], int nz)
{
    // Sort the elements
    sortElements(matrix, nz);

    printf("Sparse Matrix (row, column, value):\n");
    for (int i = 0; i < nz; i++)
    {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value); // print the elements
    }
}

int main()
{
    struct Element matrix[100], t[100];
    int m, n, nz;

    read(matrix, &m, &n, &nz);
    printf("\nOriginal Sparse Matrix:\n");
    display(matrix, nz);

    transpose(matrix, t, m, n, nz);
    printf("\nTransposed Sparse Matrix:\n");
    display(t, nz);

    return 0;
}