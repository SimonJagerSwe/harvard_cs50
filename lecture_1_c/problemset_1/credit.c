// ########## Problemset 1 - Credit ########## //
#include<cs50.h>
#include<stdio.h>
#include<string.h>


// Functions
int getInput(void);
int identifyCard(string cardString);


// Variables
long cardNumber[];
char cardString[16];
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
    long card = getInput();
    printf("Returned card number: %ld\n", card);
    // sprintf(cardString, "%ld\n", card);
    // printf("Card string: %s\n", cardString);
    // int cardType = identifyCard(cardString);
}

// User input validation
int getInput(void)
{
    long cardInput = get_long("Number: ");
    printf("Card number: %ld\n", cardInput);
    sprintf(cardString, "%ld\n", cardInput);
    printf("Card string: %s\n", cardString);
    return cardString;
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

// Verify list validity