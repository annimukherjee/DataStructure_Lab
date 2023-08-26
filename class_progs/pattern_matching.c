#include <stdio.h>
#include <string.h>
int pattern_searching(char *s, char *p);
int main()
{
    char str[50];
    char search[30];
    printf("Enter a string:\n");
    // gets(str);
    char buff;
    scanf("%[^\n]%c", str, &buff);

    printf("Enter the substring to be searched:\n");
    scanf("%[^\n]", search);

    int pos = pattern_searching(str, search);
    printf("pos: %d\n", pos);
    
    if (pos!=-1)
        printf("\nThe given substring is present at position %d of the given string.\n\n", pos + 1);
    
    else
        printf("NOT FOUND\n");

    return 0;
}


int pattern_searching(char *s, char *p)
{
    int len1 = strlen(s);
    int len2 = strlen(p);
    int i, j, k;

    for (i = 0; i < (len1 - len2); i++)
    {
        j = 0, k = i;
        while ((s[k] == p[j]) && (j < len2))
        {
            j++;
            k++;
        }
    }
    if (j == len2)
    {
        return i;
    }
    else
    {
        return -1;
    }
}



// #include <stdio.h>
// #include <string.h>
// int pattern_searching(char *s, char *p);
// int main()
// {
//     char str[50];
//     char search[30];
//     printf("Enter a string:\n");
//     gets(str);
//     printf("Enter the substring to be searched:\n");
//     gets(search);
//     int pos = pattern_searching(str, search);
//     if (pos != 1)
//     {
//         printf("\nMatched\n", pos + 1);
//     }
//     else
//     {
//         printf("\nNot matched\n");
//     }
//     return 0;
// }
// int pattern_searching(char *s, char *p)
// {
//     int len1 = strlen(s);
//     int len2 = strlen(p);
//     int i, j, k;
//     for (i = 0; i < (len1 - len2); i++)
//     {
//         j = 0, k = i;
//         while ((s[k] == p[j]) && (j < len2))
//         {
//             j++;
//             k++;
//         }
//     }
//     if (j == len2)
//     {
//         return i;
//     }
//     else
//     {
//         return -1;
//     }
// }