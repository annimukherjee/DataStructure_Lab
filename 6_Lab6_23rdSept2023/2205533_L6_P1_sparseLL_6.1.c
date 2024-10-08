//  Write a program to represent the given sparse matrix using header single linked list and display it. 

#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int row, col, val;
    struct matrix *next;
};

typedef struct matrix NODE;

// Func Declarations.
NODE *input();
void display_sparse(NODE *);

int main()
{
    NODE *spMat1 = input();
    printf("\n\n----------\nDisplaying\n----------\n");
    display_sparse(spMat1);

    return 0;
}

/* Function to take inputs and store them in a linked list */
NODE *input()
{

    NODE *Liststart, *curr, *prev = NULL;
    NODE *matStart = NULL;
    NODE *header;

    int ro, co;
    printf("\nEnter the number of rows and columns:\n");
    scanf("%d %d", &ro, &co);
    header = (NODE *)malloc(sizeof(NODE));

    header->next = NULL;
    header->row = ro;
    header->col = co;

    Liststart = header;
    prev = header;

    int total_ints_in_mat = ro * co;
    int *a = (int *)malloc(total_ints_in_mat * sizeof(int));

    int i = 0, j = 0, c = 0;

    printf("Input the elements for the array\n");
    for (i = 0; i < ro; ++i)
    {
        for (j = 0; j < co; ++j)
        {

            scanf("%d", ((a + i * co) + j));
            if (*((a + i * co) + j) != 0)
                c++;
        }
    }
    header->val = c;
    int counter = 0;

    for (int i = 0; i < ro; i++)
    {
        for (int j = 0; j < co; j++)
        {
            if (*((a + i * co) + j) != 0)
            {
                counter++;
                curr = (NODE *)malloc(sizeof(NODE));
                if (counter == 1)
                {
                    matStart = curr;
                    header->next = curr;
                    prev = curr;
                }

                curr->row = i;
                curr->col = j;
                curr->val = *((a + i * co) + j);

                curr->next = NULL;
                prev->next = curr;
                prev = curr;
            }
        }
    }
    return Liststart;
}

void display_sparse(NODE *sMat)
{
    while (sMat != NULL)
    {
        printf("%d %d %d \n", sMat->row, sMat->col, sMat->val);
        sMat = sMat->next;
    }
}
