// 2.2. WAP that takes an array as input and removes any duplicate elements, keeping only 
// the first occurrence of each element.
// Input: Enter the array elements: 1 2 2 3 3 4 4 5
// Output: Array with distinct elements: 1 2 3 4 5

#include<stdio.h>
int main()
{

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int a[size];
    // int a[3] = {10,44,89};


    printf("Enter the elements: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &a[i]);
    // size = 3;

    
    printf("\nThe original array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);


    printf("\n\nThe array without duplicates\n");
    for (int i = 0; i < size; i++)
    {
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}


