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
        printf("\n-----\ni: %d\n", i);
        j = 0;
        k = i;
        printf("j & k in the beginning of for: ");
        printf("j: %d, k: %d\n\n", j, k);

        printf("str[k]: %c\n", str[k]);
        printf("ptrn[j]: %c\n", ptrn[j]);

        printf("is str[k] == ptrn[j] ->%d\n", str[k] == ptrn[j]);
        printf("is j<plen ->%d\n", j < plen);

        while ((str[k] == ptrn[j]) && (j < plen))
        {

            printf("\ninsdie while\n_-__-__\n\n");
            j += 1;
            k += 1;

            printf("j: %d\n", j);
            printf("k: %d\n", k);

            printf("str[k]: %c\n", str[k]);
            printf("ptrn[j]: %c\n", ptrn[j]);
        }

        printf("\nat the end\n*********\nIS J==PLEN ->%d\n", j == plen);

        if (j == plen)
            return i;
    }

    return -1;
}