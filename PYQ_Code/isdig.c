#include <stdio.h>
#include <ctype.h>

int main()
{
    char c = '7';
    int x = isdigit(c);
    printf("%d\n", x);
    return 0;
}