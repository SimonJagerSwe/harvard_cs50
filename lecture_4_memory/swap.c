#include <stdio.h>

void swap(int *a, int *b);


// Example 1 - will fail
/*
int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    printf("x taken by swap: %i, y taken by swap: %i\n", a, b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("x after swapping: %i, y after swapping: %i\n", a, b);       // proves that function swaps values
}*/


// Example 2
int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}