// 2.1. WAP to reverse the contents of a dynamic array of n elements.
// Input: Enter the value of n: 5
// Enter the elements: 10 20 35 45 30
// Output: 30 45 35 20 10


#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d", &n);

    int *array;
    int *revArray;

    array = (int*)malloc(n*sizeof(int));
    revArray=(int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    for (int i = 0; i < n; i++)
        revArray[n-i-1] = array[i];

    for (int i = 0; i < n; i++)
        printf("%d ", revArray[i]);

    return 0;
}


// n=3
// i=0
// 1
// 3-0-1?
// 2


// arr[2] = 10
// arr[1] = 20

// 10 20 30

// 30 20 10