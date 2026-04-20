// ########## Problemset 1 - Credit ########## //
#include<cs50.h>
#include<stdio.h>
#include<string.h>

long card[16];
string cardString[16];

int main(void)
{
    long card = get_long("Number: ");
    printf("Card as long: %ld\n", card);
}