#include<stdio.h>

void print(char*);
int main()
{
    char a[4] = {'h','i','!', '\0'};
    print(a);
    return 0;
}


void print(char* v)
{
        for (int i = 0; i <=3; i++)
    {
        // printf("%d ", i);
        printf("%s\n",v);
    }
    
}