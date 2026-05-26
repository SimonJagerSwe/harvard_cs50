// ########## PHONEBOOK ########## //
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Example 1
int main(void)
{
    string names[] = {"Kelly", "David", "John"};
    string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("%s not found\n", name);
    return 1;
}
