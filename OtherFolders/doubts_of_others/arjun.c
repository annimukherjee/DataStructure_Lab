#include<stdio.h>
int main()
{
    int m,n;
    printf("Enter order of polynomial 1-");
    scanf("%d",&(n));
    printf("Enter order of polynomial 2-");
    scanf("%d",&(m));


    int a[n],b[m],c[m+n];


    for(int i=n;i>=0;i--)
    {
        scanf("%d",&a[i]);
    }


    printf("\n----------------------------------\n");


    for(int i=m;i>=0;i--)
    {
        scanf("%d",&b[i]);
    }


    for(int i=n;i>=0;i--)
    {
        for(int j=m;j>=0;j--)
        {
            c[i+j]=a[i]*b[j];
        }
    }


     printf("Product polynomial: ");
    for (int i = m + n; i >= 0; i--) {
        if (c[i] != 0) {
            if (i == 0) {
                printf("%d", c[i]);
            } else if (i == 1) {
                printf("%dx", c[i]);
            } else {
                printf("%dx^%d", c[i], i);
            }

            if (i != 0) {
                printf(" + ");
            }
        }
    }

    
}


