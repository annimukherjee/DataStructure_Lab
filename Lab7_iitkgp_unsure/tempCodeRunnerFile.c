
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// #define SIZE 50

// char s[SIZE];
// int top = 1;

// void push(char elem);
// char pop();
// int precedence(char elem);

// int main()
// {
//     char infix[50], prfx[50], ch, elem;
//     int i = 0, k = 0;
//     printf("\n\nRead the Infix expression: ");
//     scanf("%[^\n]s", infix);
//     push('#');
//     strrev(infix);
//     while ((ch = infix[i++]) != '\0')
//     {
//         if (ch == ')')
//             push(ch);
//         else if (isalnum(ch))
//             prfx[k++] = ch;
//         else if (ch == '(')
//         {
//             while (s[top] != ')')
//                 prfx[k++] = pop();
//             elem = pop();
//         }
//         else
//         {
//             while (precedence(s[top]) >= precedence(ch))
//                 prfx[k++] = pop();
//             push(ch);
//         }
//     }
    
//     while (s[top] != '#')
//         prfx[k++] = pop();
//     prfx[k] = '\0';
//     strrev(prfx);
//     strrev(infix);
//     printf("\n\n Given infix Expn:%s\n\n Prexfix expn: %s\n", infix, prfx);
//     return 0;
// }

// void push(char elem)
// {
//     s[++top] = elem;
// }

// char pop()
// {
//     return (s[top--]);
// }

// int precedence(char elem)
// {
//     switch (elem)
//     {
//     case '#':
//         return 0;
//     case ')':
//         return 1;
//     case '+':
//     case '-':
//         return 2;
//     case '*':
//     case '/':
//         return 3;
//     }
// }


