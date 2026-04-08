// ########## Problemset 1 - Credit ########## //
#include<cs50.h>
#include<stdio.h>


// Functions
int getInput(void);


// Variables
int cardNumber[];
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
    //printf("%i\n", card);
}

// User input validation
int getInput(void)
{
    do
    {
        int cardInput = get_long("Number: ");
        printf("Card number: %i\n", cardInput);
        return cardInput;
    }
    while (true);
    // return cardNumber;
}
// Identify card type

// Create lists of every odd/even digit placements

// Apply Luhn's to even placement list

// Combine lists

// Verify list validity