// ########## Problemset 1 - Credit ########## //
#include<cs50.h>
#include<stdio.h>


// Functions
int getInput(void);
int identifyCard(int card);


// Variables
int cardNumber[16];
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
    // printf("Card number: %i\n", card);
    int cardStatus = identifyCard(card);
}

// User input validation
int getInput(void)
{
    int cardInput = get_long("Number: ");  
    return cardInput;
}

// Identify card type
int identifyCard(int card)
{
    printf("Card number: %i\n", card);
    return 0;
}

// Create lists of every odd/even digit placements

// Apply Luhn's to even placement list

// Combine lists

// Verify list validity