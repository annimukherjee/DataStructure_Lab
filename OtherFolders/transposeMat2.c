#include <stdio.h>

int main()
{
    int n, i, j, c, d, k, z;

    printf("Enter row size: ");
    scanf("%d", &n);
    int arr[n][3]; // declare the array with known size

    printf("Enter the elements of sparse matrix in 3-tuple format:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    c = arr[0][0];
    d = arr[0][1];
    k = arr[0][2];

    int crr[k + 1][3];

    // Set the dimensions of the transposed matrix
    crr[0][0] = d;
    crr[0][1] = c;
    crr[0][2] = k;

    z = 1; // Counter for filling the transposed matrix in 3-tuple format

    // Directly fill the transposed matrix in 3-tuple format
    for (i = 1; i <= k; i++)
    {
        crr[z][0] = arr[i][1];  // Swap the row and column indices
        crr[z][1] = arr[i][0];
        crr[z][2] = arr[i][2];  // Value remains the same
        z++;
    }

    // Display the transposed sparse matrix in 3-tuple format
    for (i = 0; i < z; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", crr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
