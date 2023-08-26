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
    {
        printf("\nNot found\n");
    }
    else
    {
        printf("\nPattern found and matched\n");
    }
    return 0;
}

int patternMatch(char *s, char *p)
{
    int i, j, k;
    int len1 = strlen(s);
    int len2 = strlen(p);

    for (i = 0; i < (len1 - len2); i++)
    {
        j = 0;
        k = i;
        while ((s[k] == p[j]) && (j < len2))
        {
            j++;
            k++;
        }

        if (j == len2)
        {
            return i;
        }
    }
    return -1;
}