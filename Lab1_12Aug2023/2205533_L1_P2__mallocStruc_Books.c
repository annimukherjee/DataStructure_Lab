// 1.2. WAP to store n book’s data (title, author, publication, price etc.) using structures with dynamic memory allocation. Display all the books information of a particular author.

// Input: Number of Books: 4
// Book1: C, Balagurswamy, TMH. 220
// Book 2: Database Systems, Silberschatz Korth, McGraw Hill, 750
// Book3:Computer Architecture, Zaky Hammacher, TMH. 320
// Book4: Compiler Design, Aho Ullman Shetty, Pearson, 430

// Particular Author: Balaguruswamy
// Output: C, Balagurswamy, TMH. 220

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    char title[10];
    char author[30];
    char publication[30];
    float price;
};

typedef struct book BOOK;

int main()
{
    BOOK *ptr;
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);

    ptr = (BOOK *)malloc(n * sizeof(BOOK));

    for (int i = 0; i < n; i++)
    {
        char c;
        printf("Enter the title: ");
        scanf("%s%c", ptr[i].title, &c);

        printf("Enter the author: ");
        scanf("%s%c", ptr[i].author, &c);

        printf("Enter the publication: ");
        scanf("%s%c", ptr[i].publication, &c);

        printf("Enter the price: ");
        scanf("%f", &ptr[i].price);
    }

    char particular_author[30];
    printf("Enter the particular author name: ");
    scanf("%s", particular_author);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(ptr[i].author, particular_author) == 0)
        {
            printf("\n\nDisplaying data of %s\n--\n", particular_author);

            printf("Title: %s\n", ptr[i].title);
            printf("Author: %s\n", ptr[i].author);
            printf("Publication: %s\n", ptr[i].publication);
            printf("Price: %f\n", ptr[i].price);
        }
    }
    return 0;
}