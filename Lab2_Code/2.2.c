// 2.2. WAP that takes an array as input and removes any duplicate elements, keeping only 
// the first occurrence of each element.
// Input: Enter the array elements: 1 2 2 3 3 4 4 5
// Output: Array with distinct elements: 1 2 3 4 5

#include<stdio.h>
int main()
{

    int a [8];

    for (int i = 0; i < 8; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < 8; i++)
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