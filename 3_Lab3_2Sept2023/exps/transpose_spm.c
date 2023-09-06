#include <stdio.h>
#include <stdlib.h>

// Function to transpose a sparse matrix in 3-tuple format
void transposeSparseMatrix(int *sparseMatrix, int *result, int rows, int cols, int nonZeroElements) {
    int count = 0;

    result[0] = cols;
    result[1] = rows;
    result[2] = nonZeroElements;

    if (nonZeroElements > 0) {
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < nonZeroElements; j++) {
                if (sparseMatrix[j * 3 + 1] == i) {
                    result[(count + 1) * 3] = sparseMatrix[j * 3 + 1];
                    result[(count + 1) * 3 + 1] = sparseMatrix[j * 3];
                    result[(count + 1) * 3 + 2] = sparseMatrix[j * 3 + 2];
                    count++;
                }
            }
        }
    }
}

int main() {
    int rows, cols, nonZeroElements;

    // Input the dimensions and the number of non-zero elements
    printf("Enter the number of rows, columns and non-zero elements: ");
    scanf("%d %d %d", &rows, &cols, &nonZeroElements);

    int *sparseMatrix = (int *)malloc((nonZeroElements + 1) * 3 * sizeof(int));
    int *result = (int *)malloc((nonZeroElements + 1) * 3 * sizeof(int));

    // Input the sparse matrix
    printf("Enter the sparse matrix in 3-tuple format:\n");
    for (int i = 0; i < (nonZeroElements + 1); i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &sparseMatrix[i * 3 + j]);
        }
    }

    // Perform the transpose
    transposeSparseMatrix(sparseMatrix, result, rows, cols, nonZeroElements);

    // Display the transposed matrix
    printf("The transposed matrix in 3-tuple format is:\n");
    for (int i = 0; i < (nonZeroElements + 1); i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i * 3 + j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(sparseMatrix);
    free(result);

    return 0;
}
