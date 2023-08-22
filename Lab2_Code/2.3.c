// 2.3. WAP a menu driven program to create an array and perform the following operations:
// a. Traverse elements
// b. Insert an element
// c. Delete an element
// d. Merging elements of two arrays
// Input: Enter the value of n: 5
// Enter the elements: 10 20 35 45 30 1. Traverse
// 2. Insert
// 3. Delete
// 4. Merge
// 5. Exit
// Enter choice: 1
// Output: 10 20 35 45 30

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *array;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", (array+i));
    }

    printf("1. Traverse\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(array+i));
    }
    
    



    return 0;
}