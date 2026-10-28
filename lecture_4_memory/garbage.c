#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Example 1
    /*
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }*/


    // Example 2
    int *x;
    int *y;

    x = malloc(sizeof(int));    // Setting up a pointee to allow for dereferencing

    *x = 42;
    *y = 13;        // Dereferencing a pointer without setting up a pointee will cause a segmentation fault

    y = x;

    *y = 13;
}