// ########## Problemset 1 - Credit ########## //
#include<cs50.h>
#include<stdio.h>
#include<string.h>

long card;
char cardString[16];

int main(void)
{
    long card = get_long("Number: ");
    printf("Card as long: %ld\n", card);
    sprintf(cardString, "%ld\n", card);
    printf("Card as string: %s", cardString);
}