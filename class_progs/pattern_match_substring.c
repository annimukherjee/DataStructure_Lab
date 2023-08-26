#include <stdio.h>
#include <string.h>
int patternMatch(char *, char *);
int main()
{
    char str[50];
    char search[30];
    char buff;

    printf("Enter a string:\n");
    scanf("%[^\n]%c", str, &buff);

    printf("Enter the substring to be searched:\n");
    scanf("%[^\n]", search);

    int pos = patternMatch(str, search);
    if (pos == -1)
        printf("\nNot found\n");
    else
        printf("\nPattern found and matched\n");

    return 0;
}

int patternMatch(char *str, char *ptrn)
{
    int i, j, k;

    int slen = strlen(str);
    int plen = strlen(ptrn);

    for (i = 0; i < (slen - plen); i++)
    {
        j = 0;
        k = i;

        while ((str[k] == ptrn[j]) && (j < plen))
        {
            j += 1;
            k += 1;
        }

        if (j == plen)
            return i;
    }

    return -1;
}