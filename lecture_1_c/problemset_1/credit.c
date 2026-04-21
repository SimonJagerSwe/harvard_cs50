// ########## Problemset 1 - Credit ########## //
#include<cs50.h>
#include<stdio.h>
#include<string.h>

// Variables
long card[16];
char cardString[16];
char evenNumbers[8] = "";
char oddNumbers[8] = "";
int evenLength[8];
int oddLength[8];


// Functions
long getInput(void);
long evaluateInput(long card);
int implementLuhn(long card);


// Main function
int main(void)
{
    // Get card number
    long card = getInput();
    printf("Returned card number: %ld\n", card);

    // Evaluate and card type
    long evalCard = evaluateInput(card);
    printf("Card status after evaluation: %ld\n", evalCard);

    // Return card type and proceed if card is valid
    if (evalCard == 1 || evalCard == 2 || evalCard == 3)
        {
        if (evalCard == 1)
        {
            printf("AMEX\n");
        }

        else if (evalCard == 2)
        {
            printf("MASTERCARD\n");
        }

        else if (evalCard == 3)
        {
            printf("VISA\n");
        }
        implementLuhn(card);
    }

    // If card is invalid, print INVALID and terminate program
    else
    {
        printf("INVALID\n");
    }
}

// Get user input
long getInput(void)
{
    long cardNumber = get_long("Number: ");
    // printf("Card number: %ld\n", cardNumber);
    return cardNumber;
}

// Evaluate user input
long evaluateInput(long card)
{
    printf("Card number for evaluation as long: %ld\n", card);
    // Convert card number (long) to a string for sliceability
    sprintf(cardString, "%ld\n", card);
    printf("Card as string: %s\n", cardString);

    // Check length of number (minus one to account for the \0 implied in the string)
    int length = (strlen(cardString) - 1);
    printf("Card number lengt: %i\n", length);

    // Get first two characters of the card number to evaluate 
    char card1 = cardString[0];
    char card2 = cardString[1];

    // Evaluate if card is AmEx
    if (length == 15 && (card1 == '3' && (card2 == '4' || card2 == '7')))
    {
        // printf("AMEX\n");
        return 1;
    }

    // Evaluate if card is MasterCard
    else if (length == 16 && (card1 == '5' && (card2 == '1' || card2 == '2' || card2 == '3' || card2 == '4' || card2 == '5')))
    {
        // printf("MasterCard\n");
        return 2;
    }

    // Evaluate if card is Visa
    else if ((length == 13 || length == 16) && card1 == '4')
    {
        // printf("Visa\n");
        return 3;
    }

    // If card is invalid, return 0
    else
    {
        return 0;
    }
}

// Take verified card number and implement Luhn's algorithm 
int implementLuhn(long card)
{
    // Check length of card number
    sprintf(cardString, "%ld\n", card);
    printf("Card as string: %s\n", cardString);
    int length = (strlen(cardString) -1);
    printf("Card length: %i\n", length);
    
    
    // Check if card number has odd or even number of digits
    int modulo = (length % 2);
    printf("Modulo: %i\n", modulo);

    // Card has even number of digits
    if (modulo == 0)
    {
        for (int i = (length); i >= 0; i -= 2)
        {
            printf("%c\n", cardString[i]);
        }
    }

    // Card has odd number of digits, start Luhns on index 0
    else
    {
        for (int i = (length); i >= 0; i -= 2)
        {
            printf("%c\n", cardString[i]);
        }
    }
    return 0;
}
