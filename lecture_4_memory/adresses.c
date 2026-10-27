#include <stdio.h>


// Example 1
/*int main(void)
{
    int n = 50;
    printf("%i\n", n);
    printf("%p\n", &n);     // prints the adress of n
}*/


// Example 2
int main(void)
{
    int n = 50;
    int *p = &n;            // Creates a pointer to the adress of n
    printf("%p\n", p);      // prints the pointer variable
}
