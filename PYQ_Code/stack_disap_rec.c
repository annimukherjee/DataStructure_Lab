#include <stdio.h>
#include <stdlib.h>

int s[3] = {10, 20, 30};

int pop(int s[], int pop_top)
{
    // printf("INSIDE POP\n---\n");
    // printf("pop_top: %d\n", pop_top);

    int x = s[pop_top];
    printf("X in POP: %d\n", x);
    pop_top--;
    return x;
}

void disp_recurr(int s[], int top)
{
    // printf("inside disp_recurr\ntop reveived: %d\n", top);

    if (top == -1)
    {
        exit(0);
    }
    else
    {
        int x = pop(s, top);
        top--;
        printf("%d\n", x);

        disp_recurr(s, top);
    }
}

int main()
{
    int top = 2;
    disp_recurr(s, top);

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%d ", s[i]);
    // }

    return 0;
}
