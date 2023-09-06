#include <stdio.h>

void traverse(int x[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", x[i]);
}

void insert(int x[], int n, int loc, int elem)
{
    int i;
    for (i = n - 1; i > loc; i--)
        x[i] = x[i - 1];

    x[loc] = elem;
    for (i = 0; i < n; i++)
        printf("%d ", x[i]);
}
void delete(int x[], int n, int loc)
{
    int i;
    for (i = loc; i < n; i++)
        x[i] = x[i + 1];
    n = n - 1;
    for (i = 0; i < n; i++)
        printf("%d ", x[i]);
}
void merge(int x[], int n, int y[], int m, int z[], int k)
{
    if (k >= (m + n))
    {
        int i, c = 0;
        for (i = 0; i < n; i++)
        {
            z[c] = x[i];
            c++;
        }
        for (i = 0; i < n; i++)
        {
            z[c] = y[i];
            c++;
        }
        printf("Merged array:\n");
        for (i = 0; i < c; i++)
        {
            printf("%d ", z[i]);
        }
    }
}
int main()
{
    int n, i;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    char ch1 = 'y';
    while (ch1 == 'y')
    {
        printf("\n\n----------\n1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Merge\n");
        printf("5. Exit\n");
        int ch, pos, elem, m;

        printf("Enter choice:\n");
        scanf("%d", &ch);
        printf("Enter the size of the 2nd array:\n");
        scanf("%d", &m);

        int k = m + n;
        int b[m];
        int c[k];
        if (ch == 1)
        {
            printf("Traversal\n");
            traverse(a, n);
        }
        else if (ch == 2)
        {
            printf("Enter the position and the element to be added:\n");
            scanf("%d %d", &pos, &elem);
            insert(a, n, pos - 1, elem);
        }
        else if (ch == 3)
        {
            printf("Enter the location to be deleted:\n");
            scanf("%d", &pos);
            delete (a, n, pos - 1);
        }
        else if (ch == 4)
        {
            printf("Enter the elements of the 2nd array:\n");
            for (i = 0; i < m; i++)
                scanf("%d", &b[i]);

            merge(a, n, b, m, c, k);
        }
        else if (ch == 5)
        {

            ch1 = 'n';
            break;
        }
    }
    return 0;
}