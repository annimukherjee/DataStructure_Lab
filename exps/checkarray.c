#include <stdio.h>

void printarray(int a[], int);

int main()
{
    int a[] = {10, 20, 30};
    printarray(a, 3);
    return 0;
}

// a[2] = *(&v)

void printarray(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }

    return;
}