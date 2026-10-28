#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
// Example 1
/*
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    for (int i = 0; i <= strlen(s); i++)
    {
        t[i] = s[i];
    }
    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
*/


// Example 2
char *s = get_string("s: ");
if (s == NULL)
{
    return 1;
}
char *t = get_string("t: ");
if (t == NULL)
{
    return 1;
}

strcpy(t, s);
if (strlen(s) > 0)
{
    t[0] = toupper(t[0]);
}

printf("s: %s\n", s);
printf("t: %s\n", t);
}
