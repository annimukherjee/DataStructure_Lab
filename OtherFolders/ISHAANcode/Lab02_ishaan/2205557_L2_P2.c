#include <stdio.h>
int main()
{

    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int a[size];

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("The original array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }


    printf("\n");
    printf("The new array:\n");
    for (i = 0; i < size; i++)
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