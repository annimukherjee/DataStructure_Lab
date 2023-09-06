// WAP to perform transpose of a given sparse matrix in 3-tuple format.
#include <stdio.h>

int main()
{
    int n, m, i, j, c, d, k, f, g, e, z;

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

    int brr[c][d];
    int trr[d][c];
    e = 1;

    // Initialize the brr matrix with zeros
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < d; j++)
        {
            brr[i][j] = 0;
        }
    }

    // Fill in the brr matrix based on the sparse matrix data
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < d; j++)
        {
            if (e <= k)
            {
                f = arr[e][0];
                g = arr[e][1];
                
                brr[f][g] = arr[e][2];
                e++;
            }
        }
    }

    for (i = 0; i < c; i++)
    {
        for (j = 0; j < d; j++)
        {
            trr[j][i] = brr[i][j];
        }
    }
    int crr[k + 1][3];


    z = 0;
    crr[z][0] = d;
    crr[z][1] = c;
    crr[z][2] = k;
    z++;

    for (i = 0; i < d; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (trr[i][j] != 0)
            {
                crr[z][0] = i;
                crr[z][1] = j;
                crr[z][2] = trr[i][j];
                z++;
            }
        }
    }

    for (i = 0; i < d; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", crr[i][j]);
        }
        printf("\n");
    }

    return 0;
}