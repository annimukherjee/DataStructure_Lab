// 2.3. WAP a menu driven program to create an array and perform the following operations:
// a. Traverse elements
// b. Insert an element
// c. Delete an element
// d. Merging elements of two arrays
// Input: Enter the value of n: 5
// Enter the elements: 10 20 35 45 30 

// 1. Traverse
// 2. Insert
// 3. Delete
// 4. Merge
// 5. Exit
// Enter choice: 1
// Output: 10 20 35 45 30

#include <stdio.h>
#include<stdlib.h>

void traverse(int arr[], int n);
void insert(int arr[], int n, int loc, int elem);
void delete(int arr[], int n, int loc);
void merge(int arr[], int n, int* y, int m, int* z, int k);

int main()
{
    int n, i;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int a[n];


    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    printf("\n1. Traverse\n");
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

        printf("\n----\nInsertion at an index\n");
        printf("Enter the position and the element to be added (0 indexed):\n");
        scanf("%d %d", &pos, &elem);
        insert(a, n, pos, elem);
        break;

    case 3:
        printf("Enter the location to be deleted (0 indexed):\n");
        scanf("%d", &pos);
        delete (a, n, pos);
        break;

    case 4:
        printf("Enter the size of the 2nd array:\n");
        scanf("%d", &m);

        k = m + n;
        printf("\nThe size of merged array: %d\n",k);
        
        int *b, *c;

        b = (int *)malloc(m * sizeof(int));
        c = (int *)malloc(k * sizeof(int));

        printf("\nEnter the elements of the 2nd array: ");
        for (i = 0; i < m; i++)
            scanf("%d", b+i);

        merge(a, n, b, m, c, k);

        free(b);
        free(c);
        break;
    
    case 5:
        printf("\nExiting...\n");
        break;
    
    default:
        printf("\nInvalid Choice...\n\nExiting...\n");
    }

    return 0;
}


void traverse(int arr[], int n)
{
    printf("\n-------\nTraversal: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    
}

void insert(int arr[], int n, int loc, int elem)
{


    int i;
    for (i = n - 1; i > loc; i--)
        arr[i] = arr[i - 1];

    arr[loc] = elem;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

void delete(int arr[], int n, int loc)
{
    int i;
    for (i = loc; i < n; i++)
        arr[i] = arr[i + 1];

    n = n - 1;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    
}

void merge(int arr[], int n, int* y, int m, int* z, int k)
{
    int i;
    int c = 0;

    for (i = 0; i < n; i++)
    {
        *(z+c) = arr[i];
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

    printf("\nMerged array:\n");
    for (i = 0; i < c; i++)
    {
        printf("%d ", *(z+i));
    }

    printf("\n");
}

