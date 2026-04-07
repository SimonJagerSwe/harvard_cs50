//########## Hello ##########//
#include <stdio.h>
/*
int main(void)
{
    printf("hello world\n");
}


#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
*/


int x = 2;
int y = 5;

int main(void)
{
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x == y)
    {
        printf("x is equal to y\n");
    }
    else {
        printf("x is not less than y\n");
    }
}