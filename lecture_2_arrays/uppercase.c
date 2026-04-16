#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// int main(void)
// {
//     string s = get_string("Before: ");
//     printf("After: \n");
//     for (int i = 0, n = strlen(s); i < n; i++)
//     {
//         // If s[i] is lowercase
//         if (s[i] >= 'a' && s[i] <= 'z')
//         {
//             printf("%c", s[i] - 32);
//         }
// 
//         // If not lowercase
//         else
//         {
//             printf("%c", s[i]);
//         }        
//     }
//     printf("\n");
// }

int main(void)
{
    string s = get_string("Before: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // if (islower(s[i]))
        // {
        //     printf("%c", toupper(s[i]));
        // }
        // else
        // {
        //    printf("%c", s[i]);
        //}
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
