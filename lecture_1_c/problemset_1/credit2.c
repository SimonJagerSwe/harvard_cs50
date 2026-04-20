// ########## Problemset 1 - Credit ########## //
#include<cs50.h>
#include<stdio.h>
#include<string.h>

// Variables
long card;
char cardString[16];

// Main function
int main(void)
{
    // Get card number
    long card = get_long("Number: ");
    printf("Card as long: %ld\n", card);

    // Convert card number to string for slicing
    sprintf(cardString, "%ld\n", card);
    printf("Card as string: %s\n", cardString);

    // Check length of number (minus one to account for the \0 implied in the string)
    int length = (strlen(cardString) - 1);
    printf("Card number lengt: %i\n", length);

    // Compare lengths to card suppliers
    if (length == 16)
    {
        printf("MasterCard or Visa\n");
    }

    else if (length == 15)
    {
        printf("American Express\n");
    }

    else if (length == 13)
    {
        printf("Visa\n");
    }
    
}