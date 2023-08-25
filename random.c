#include<stdio.h>
int main()
{
    int a[][3] = {{1,2,3},{4,5,6},{17,8,9}};
    int *ptr = &a[0][0];

    for (int i = 0; i < 3; i++)
    {   
        for (int j = 0; j < 3; j++)
            printf("%4d",*(ptr++));
        
        printf("\n");
    }
    
    return 0;
}