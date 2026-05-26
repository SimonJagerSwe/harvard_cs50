// ########## SEARCH ########## //
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Example 1
/*
int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found %i\n", n);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
*/

// Example 2        This will not work, needs strcmp from string.h
/*
int main(void)
{
    string strings[] = {"Battleship", "Boot", "Cannon", "Iron", "Thimble", "Top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strings[i] == s)
        {
            printf("Found %s\n", strings[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
*/

// Example 3
int main(void)
{
    string strings[] = {"Battleship", "Boot", "Cannon", "Iron", "Thimble", "Top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found %s\n", s);
            return 0;
        }
    }
    printf("%s not found\n", s);
    return 1;
}
