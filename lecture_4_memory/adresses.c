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
// typedef char *string;       //  This renames char * "string" in cs50.h
/*
int main(void)
{
    char * s = "HI!";
    printf("%s\n", s);
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("%c\n", s[3]);
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%c\n", *(s + 3));
}*/


// Example 7
/*
#include <cs50.h>
int main(void)
{
    int i = 50;
    int j = 50;

    if (i == j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}*/


// Example 8
/*
#include <cs50.h>
int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}*/


// Example 9
#include <cs50.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
    char *s = get_string("s: ");

    char *t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

}