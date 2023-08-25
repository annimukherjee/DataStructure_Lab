// 1.1. WAP to store one student’s information (i.e. student’s roll no, name gender, marks etc)
// of an educational institute and display all the data, using structure (Access the structure members
// using pointer).
// Input: 120045 Rahul Male 77
// Output: Rollno.-120045, Name-Rahul, Gender-Male, Marks-77

#include <stdio.h>
struct studentStruc
{
    int roll;
    char name[30];
    char gender;
    float marks;
};

typedef struct studentStruc STUD;

int main()
{
    STUD s1, *ptr;

    ptr = &s1;
    char newline;


    printf("\nGive Input:\n\n");
    // INPUTS---------------------------------
    printf("Enter roll: ");
    scanf("%d", &s1.roll);

    printf("Enter name: ");
    scanf("%c%[^\n]", &newline, s1.name);


    printf("Enter gender (M/F): ");
    scanf("%c%c",&newline, &s1.gender);

    printf("Enter marks: ");
    scanf("%f", &s1.marks);

    // OUTPUTS---------------------------------
    printf("\n\nDisplaying data:\n\n");
    printf("Entered roll: %d\n", ptr->roll);
    printf("Entered name: %s\n", ptr->name);
    printf("Entered gender: %c\n", ptr->gender);
    printf("Entered marks: %.2f\n", ptr->marks);

    return 0;
}