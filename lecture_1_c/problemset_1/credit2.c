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

    // Print first two characters of the card number for control purposes
    char card1 = cardString[0];
    char card2 = cardString[1];
    printf("%c%c\n", card1, card2);
    

    // Compare lengths to card suppliers
    if (length == 16)
    {
        printf("MasterCard or Visa\n");

        // Check first numbers to see if it is a MasterCard
        if (card1 == '5' && (card2 == '1' || card2 == '2' || card2 == '3' || card2 == '4' || card2 == '5'))
        {
            printf("MasterCard\n");
        }

        // Check first number sto see if it is a Visa card
        else if (card1 == '4')
        {
            printf("Visa\n");
        }

        // If card length is 16 but not a valid number, return invalid
        else
        {
            printf("Invalid\n");
        } 
    }

    else if (length == 15)
    {
        printf("American Express\n");
    }

    else if (length == 13)
    {
        printf("Visa\n");
    }

    // 
    else
    {
        printf("Invalid\n");
    }
    
}