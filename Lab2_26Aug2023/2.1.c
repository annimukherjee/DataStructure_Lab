// 2.1. WAP to reverse the contents of a dynamic array of n elements.
// Input: Enter the value of n: 5
// Enter the elements: 10 20 35 45 30
// Output: 30 45 35 20 10


#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *array;
    int *revArray;

    array = (int*)malloc(n*sizeof(int));
    revArray=(int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    for (int i = 0; i < n; i++)
        revArray[n-i-1] = array[i];


    printf("The array taken as input is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    
    printf("\n");


    printf("The reversed array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", revArray[i]);
   
    printf("\n");
    
    return 0;
}