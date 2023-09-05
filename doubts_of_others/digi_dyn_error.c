#include <stdio.h>
#include <stdlib.h>
void disp(int *ptr4, int p)
{
    printf("\n");
    for (int i = p; i >= 0; i--)
    {
        printf("+%dx^%d", ptr4[i], i);
    }
}


void addi(int *ptr4, int *ptr5, int x, int y)
{
    if (x >= y)
    {
        int *ptr3;
        ptr3 = (int *)malloc((x + 1) * sizeof(int));


        for (int i = x; i >= 0; i--)
            ptr3[i] = ptr4[i];

        for (int j = y; j >= 0; j--)
            ptr3[j] = ptr3[j] + ptr5[j];
        
        
        disp(ptr3, x);
    }


    else if (x < y)
    {
        int *ptr3;

        ptr3 = (int *)malloc(y * sizeof(int));


        for (int i = y; i >= 0; i--)
            ptr3[i] = ptr5[i];

        for (int i = y; i >= 0; i--)
        {
            ptr3[i] = ptr3[i] + ptr4[i];
        }

        disp(ptr3, y);
    }
}

int main()
{
    while (1)
    {
        int n;

        printf("enter the order of the polynomial 1");
        scanf("%d", &n);

        int *ptr1;

        ptr1 = (int *)malloc( (n + 1) * sizeof(int));
        
        for (int i = n; i >= 0; i--)
        {
            printf("enter coeff of x^%d", i);
            scanf("%d", &ptr1[i]);
        }

        int m;
        printf("enter the order of the polynomial 2");
        scanf("%d", &m);
        int *ptr2;
        ptr2 = (int *)malloc((m + 1) * sizeof(int));
        for (int i = m; i >= 0; i--)
        {
            printf("enter coeff of x^%d ", i);
            scanf("%d", &ptr2[i]);
        }




        addi(ptr1, ptr2, n + 1, m + 1);

        int c;

        printf("\ndo you want to continue 1/0?");
        
        scanf("%d", &c);
        if (c == 1)
            continue;
        else
            break;
    }
}