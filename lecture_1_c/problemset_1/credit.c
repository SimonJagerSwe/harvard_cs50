// ########## Problemset 1 - Credit ########## //
#include<cs50.h>
#include<stdio.h>
#include<string.h>

// Variables
long card;
char cardString[16];

// Functions
long getInput(void);
long evaluateInput(long card);


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
        printf("AMEX\n");
        return 1;
    }

    // Evaluate if card is MasterCard
    else if (length == 16 && (card1 == '5' && (card2 == '1' || card2 == '2' || card2 == '3' || card2 == '4' || card2 == '5')))
    {
        printf("MasterCard\n");
        return 2;
    }

    // Evaluate if card is Visa
    else if ((length == 13 || length == 16) && card1 == '4')
    {
        printf("Visa\n");
        return 3;
    }

    // If card is invalid, return 0
    else
    {
        return 0;
    }
}


/*
// Functions
string getInput(void);
// int identifyCard(string cardString);


// Variables
string card;
long cardNumber;
string cardString;
// int amexLength = 15;
// int mastercardLength = 16;
// int visaLength[] = {'13', '16'};
// int amexStarts[] = {'34', '37'};
// int mastercardStarts[] = {'51', '52', '53', '54', '55'};
// int visaStart = '4';
int evenPlaces[8];
int oddPlaces[8];

// Main function
int main(void)
{
    string card = getInput();
    printf("Returned card number: %ld\n", card);
}

// User input validation
string getInput(void)
{
    long cardNumber = get_long("Number: ");
    printf("Card number: %ld\n", cardNumber);

    // Convert long to string
    sprintf(cardString, "%ld\n", cardNumber);
    printf("Card string: %s\n", cardString);
    return cardString;
    // return 0;
}

// Identify card type
int identifyCard(string cardString)
{
    printf("Card number: %s\n", cardString);
    printf("Card start: %c\n", cardString[0]);
    printf("Card length is %lu\n", strlen(cardString));
    // Check if card is AmEx
    if (strlen(cardString) == 15)
    {
        printf("AmEx card detected");
    }
    // Check if card is MasterCard/Visa
    else if (strlen(cardString) == 16)
    {
        printf("MasterCard or Visa card detected");
        // Check if card is MasterCard
    }
    // Check if card is Visa
    else if (strlen(cardString) == 13)
    {
        printf("Visa card detected");
    }

    // Invalid card format detected
    else
    {
        printf("INVALID");
    }
    return 0;
}


// Create lists of every odd/even digit placements

// Apply Luhn's to even placement list

// Combine lists

// Verify list validity */