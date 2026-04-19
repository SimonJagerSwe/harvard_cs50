// ########## Problemset 1 - Credit ########## //
#include<cs50.h>
#include<stdio.h>
#include<string.h>


// Functions
int getInput(void);
int identifyCard(string cardString);


// Variables
int cardNumber[16];
char cardString[16];
int amexLength = 15;
int mastercardLength = 16;
int visaLength[] = {13, 16};
int amexStarts[] = {34, 37};
int mastercardStarts[] = {51, 52, 53, 54, 55};
int visaStart = 4;
int evenPlaces[8];
int oddPlaces[8];

// Main function
int main(void) 
{
    int card = getInput();
    sprintf(cardString, "%d\n", card);
    int cardStatus = identifyCard(cardString);
}

// User input validation
int getInput(void)
{
    int cardInput = get_long("Number: ");  
    return cardInput;
}

// Identify card type
int identifyCard(string cardString)
{
    printf("Card number: %s\n", cardString);
    return 0;
}

// Create lists of every odd/even digit placements

// Apply Luhn's to even placement list

// Combine lists

// Verify list validity