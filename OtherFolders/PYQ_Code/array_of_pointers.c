#include <stdio.h>
int main()
{
    char *ptr[3];
    ptr[0] = "Adam";
    ptr[1] = "Chris";
    ptr[2] = "Deniel";

    printf("%s %s %s", ptr[0], ptr[1], ptr[2]);
    return 0;
}