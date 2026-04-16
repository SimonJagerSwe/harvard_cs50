#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: \n");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If s[i] is lowercase
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }

        // If not lowercase
        else
        {
            printf("%c", s[i]);
        }        
    }
    printf("\n");
}
