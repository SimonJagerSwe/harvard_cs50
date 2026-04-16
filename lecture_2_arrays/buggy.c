#include <stdio.h>
#include <cs50.h>

// int main(void)
// {
//     printf("hello, world\n");
// }

// int main(void)
// {
//     string name = get_string("What is your name? ");
//     printf("hello, %s!\n", name);
// }

// int main(void)
// {
//     for (int i = 0; i < 3; i++)
// {
//         printf("%i #\n", i);
//     }
// }

void print_column(int height);

int main(void)
{
    int h = get_int("Height: \n");
    print_column(h);
}

void print_column(int height)
{
    for (int i = 0; i < height; i++)
    {
        printf("#\n");
    }
}
