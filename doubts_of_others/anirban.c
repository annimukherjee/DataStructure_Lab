#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, num, flag = 0, i, pos;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("enter the %d elements of the array :\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    printf("enter the number you want to search :\n");
    scanf("%d", &num);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {

            flag = 1;
            pos = i;
        }
    }
    if (flag == 1)
    {
        printf("The number you have searched was found in position %d\n", pos);
    }
    else
    {
        printf("The number was not found");
    }

    free(arr);

    return 0;
}