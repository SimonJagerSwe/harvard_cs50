#include<stdio.h>
#include<string.h>

char one = '1';
char two = '2';
int subtract = 48;

int main(void)
{
    printf("%d\n", one);
    printf("%d %d\n", one, two);
    printf("%d\n", (one - subtract));
    printf("%d%d\n", (one - subtract), (two - subtract));
}