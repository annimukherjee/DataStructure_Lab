// #include <stdio.h>
// int main()
// {
//     // int data;

//     for (int i = 0; i <= 10; i++)
//     {
//         int *pointer;
//         printf("%p\n", &pointer);
//     }

//     int *pointer;
//     printf("OUTSIDE LOOP: \n%p\n", &pointer);

//     // printf("%p\n",&data);
//     // data = 6;
//     // printf("%p\n",&data);
//     return 0;
// }

#include <stdio.h>
int main()
{

    int a = 5;
    int **p2 = &a;
    int *p2 = 5;

    return 0;
}