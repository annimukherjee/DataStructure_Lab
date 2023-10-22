
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50
char s[SIZE];
int top = -1;

void push(char elem);
char pop();
int precedence(char elem);
void strrev(char *str);

int main()
{
    char infx[50], prfx[50], ch, elem;

    int i = 0, k = 0;

    printf("\n\nRead the Infix Expression ? ");
    scanf("%s", infx);

    push('#');

    strrev(infx);

    while ((ch = infx[i++]) != '\0')
    {
        if (ch == ')')
            push(ch);
        else if (isalnum(ch)) //  if ch is an alphanumeric character, add it to prfx.
            prfx[k++] = ch;
        else if (ch == '(') // if ch is '(', pop elements from stack until ')' is encountered.
        {
            while (s[top] != ')')
                prfx[k++] = pop();
            elem = pop();
        }
        else
        {
            while (precedence(ch) < precedence(s[top])) // pop elements from stack while their precedence is greater than or equal to the precedence of ch, then push ch onto the stack.
                prfx[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        prfx[k++] = pop();

    prfx[k] = '\0';

    strrev(prfx);
    strrev(infx);

    printf("In\nGiven Infix Expn: %s \nPrefix Expn: %s\n", infx, prfx);
    return 0;
}

void push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return (s[top--]);
}

int precedence(char elem)
{
    switch (elem)
    {
    case '#':
        return 0;
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}

void strrev(char *str)
{
    int len = strlen(str);
    int i;
    char temp;
    for (i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
