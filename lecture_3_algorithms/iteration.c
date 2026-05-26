// ########## ITERATION ########## //
#include <cs50.h>
#include <stdio.h>

// Example 1
/*
void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
*/


// Example 2
void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
{
    draw(n -1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

