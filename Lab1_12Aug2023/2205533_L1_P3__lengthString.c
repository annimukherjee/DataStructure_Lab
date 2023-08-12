// 1.3. WAP to calculate the length of a string using a pointer.
// Input: Orange
// Output: The length of String: 6

#include <stdio.h>

int main()
{
    char str[30], *ptr;
    int count = 0;

    printf("Enter the string: ");
    scanf("%s", str);

    ptr = str;

    while (*ptr != '\0')
    {
        count++;
        ptr++;
    }

    printf("Length of the string is: %d\n", count);

    return 0;
}