#include <stdio.h>


// Example 1
/*int main(void)
{
    int n = 50;
    printf("%i\n", n);
    printf("%p\n", &n);     // prints the adress of n
}*/


// Example 2
/*int main(void)
{
    int n = 50;
    int *p = &n;            // Creates a pointer to the adress of n
    printf("%p\n", p);      // prints the pointer variable
}*/


// Example 3
/*
int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);      // As above
    printf("%i\n", p);      // Not sure what the point is tbh
    printf("%i\n", *p);     // Prints the contents of the adress
}*/


// Example 4
/*
#include <cs50.h>
int main(void)
{
    string s = "HI!";       // Cheat function from cs50.h
    printf("%s\n", s);
}*/


// Example 5
/*
#include <cs50.h>
int main(void)
{
    string s = "HI!";       // Cheat function from cs50.h, to be replaced with char * s
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}*/


// Example 6
int main(void)
{
    char * s = "HI!";
    printf("");
}
