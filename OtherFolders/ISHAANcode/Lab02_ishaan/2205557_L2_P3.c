#include <stdio.h>
#include<stdlib.h>

void traverse(int x[], int n);
void insert(int x[], int n, int loc, int elem);
void delete(int x[], int n, int loc);
void merge(int x[], int n, int* y, int m, int* z, int k);

int main()
{
    int n, i;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int a[n];


    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("1. Traverse\n");
    printf("2. Insert\n");
    printf("3. Delete\n");
    printf("4. Merge\n");
    printf("5. Exit\n");
    
    int ch=0;
    printf("Enter choice:\n");
    scanf("%d", &ch);

    int pos=0;
    int elem=0;
    int k=0;
    int m=0;


    switch (ch)
    {
    case 1:
        traverse(a, n);
        break;

    case 2:
        printf("Enter the position and the element to be added:\n");
        scanf("%d %d", &pos, &elem);
        insert(a, n, pos - 1, elem);
        break;

    case 3:
        printf("Enter the location to be deleted:\n");
        scanf("%d", &pos);
        delete (a, n, pos - 1);
        break;

    case 4:
        printf("Enter the size of the 2nd array:\n");
        scanf("%d", &m);

        k = m + n;
        printf("The size of merged array: %d\n",k);
        
        int *b, *c;

        b = (int *)malloc(m * sizeof(int));
        c = (int *)malloc(k * sizeof(int));

        printf("Enter the elements of the 2nd array:\n");
        for (i = 0; i < m; i++)
        {
            scanf("%d", b+i);
        }

        merge(a, n, b, m, c, k);
        break;
    
    case 5:
        break;
    
    default:
        printf("\nInvalid Choice!\n");
    }
    return 0;
}


void traverse(int x[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
}

void insert(int x[], int n, int loc, int elem)
{
    int i;
    for (i = n - 1; i > loc; i--)
    {
        x[i] = x[i - 1];
    }
    x[loc] = elem;
    for (i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
}

void delete(int x[], int n, int loc)
{
    int i;
    for (i = loc; i < n; i++)
    {
        x[i] = x[i + 1];
    }
    n = n - 1;
    for (i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
}

void merge(int x[], int n, int* y, int m, int* z, int k)
{
    int i;
    int c = 0;

    for (i = 0; i < n; i++)
    {
        *(z+c) = x[i];
        c++;
    }

    // printf("c is after 1st loop: %d",c);

    for (i = 0; i < m; i++)
    {
        *(z+c) = *(y+i);
        c++;
    }

    // printf("c is after 2nd loop: %d",c);
    // printf("k is: %d",k);

    printf("Merged array:\n");
    for (i = 0; i < c; i++)
    {
        printf("%d ", *(z+i));
    }

    printf("\n");
}

