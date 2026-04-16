#include <stdio.h>
#include <cs50.h>

// int main(void)
// {
//     printf("hello, world\n");
// }

int main(void)
{
    string name = get_string("What is your name? ");
    printf("hello, %s!\n", name);
}