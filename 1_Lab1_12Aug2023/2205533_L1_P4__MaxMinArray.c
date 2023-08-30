// 1.4. WAP using dynamic memory allocation to find out the smallest and largest element stored
// in an array of n integers.
// Input: Enter the value of n: 7
// Enter the elements: 10, 20, 15, 25, 90, 45, 80
// Output: Smallest: 10 and Largest: 90

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *array;

    printf("Length of array: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    // // Can't I just do
    // int arrayAssgn[n];

    // // instead of malloc?

    // Using malloc:
    //     • Memory Allocation: Allocates memory on the heap.
    //     • Lifetime: Memory persists until explicitly freed, allowing for more control.
    //     • Error Handling: You can handle errors if memory allocation fails.
    //     • Portability: Supports older C standards.

    // Using a Variable-Length Array (VLA):
    //     • Syntax: Defined as int arrayAssgn[n];, where 'n' is a variable.
    //     • Memory Allocation: Allocates memory on the stack.
    //     • Lifetime: Memory is automatically freed when the function exits.
    //     • Ease of Use: Simpler syntax and no need to explicitly free memory.
    //     • Standard Compliance: Supported in C99 but optional in later standards, so it might not be
    //     portable across all compilers and platforms.

    // Summary:
    //     • Yes, you can use a variable-length array instead of malloc if your compiler supports C99
    //     or later and you don't need the features associated with dynamic memory allocation.
    //     • If portability and compatibility are concerns, sticking with 'malloc' would be the safer
    //     option.
    //     • If you choose to use a VLA, you would replace the 'malloc' line with int
    //     arrayAssgn[n]; and change all references from 'array' to 'arrayAssgn'

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &(*(array+i)));

    int max, min;
    max = array[0];
    min = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];

        if (array[i] < min)
            min = array[i];
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
