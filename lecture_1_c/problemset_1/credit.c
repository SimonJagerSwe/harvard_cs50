// ########## Problemset 1 - Credit ########## //
#include<cs50.h>
#include<stdio.h>
#include<string.h>

// Variables
long card[16];
char cardString[16];
int checksum;
char evenNumbers[8] = "";
char oddNumbers[8] = "";
int subtract = 48;


// Functions
long getInput(void);
long evaluateInput(long card);
int implementLuhn(long card);


// Main function
int main(void)
{
    // Get card number
    long card = getInput();

    // Evaluate and card type
    long evalCard = evaluateInput(card);

    // Return card type and proceed if card is valid
    if (evalCard == 1 || evalCard == 2 || evalCard == 3)
        {
        // Apply Luhn's algorithm to evaluate if checksum is valid
        int checksum = implementLuhn(card);
        printf("Checksum : %i\n", checksum);

        // Provided valid checksum, use card evaluation to verify card type
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
    return cardNumber;
}

// Evaluate user input
long evaluateInput(long card)
{
    sprintf(cardString, "%ld\n", card);

    // Check length of number (minus one to account for the \0 implied in the string)
    int length = (strlen(cardString) - 1);

    // Get first two characters of the card number to evaluate 
    char card1 = cardString[0];
    char card2 = cardString[1];

    // Evaluate if card is AmEx
    if (length == 15 && (card1 == '3' && (card2 == '4' || card2 == '7')))
    {
        return 1;
    }

    // Evaluate if card is MasterCard
    else if (length == 16 && (card1 == '5' && (card2 == '1' || card2 == '2' || card2 == '3' || card2 == '4' || card2 == '5')))
    {
        return 2;
    }

    // Evaluate if card is Visa
    else if ((length == 13 || length == 16) && card1 == '4')
    {
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
    int length = (strlen(cardString) -1);
    printf("Card length: %i\n", length);
    
    
    // Check if card number has odd or even number of digits
    int modulo = (length % 2);

    // Card has even number of digits
    if (modulo == 0)
    {
    int evenCardMult = 0;
    int evenCardNoMult = 0;
    int evenCardSum = 0;
    char tenPlus[8];
        // Multiply every other digit, going back from the second-to-last digit
        for (int i = (length - 2); i >= 0; i -= 2)
        {
            int j = ((cardString[i] - subtract) * 2);
            // printf("%i\n", j);
            if (j > 9)
            {
                sprintf(tenPlus, "%i\n", j);
                for (int i = 0; i < 2; i++)
                {
                    int j = (tenPlus[i] - subtract);
                    evenCardMult += j;
                }
            }
            else
            {
                evenCardMult += j;
            }
        }
        printf("Multiplied sum: %i\n\n", evenCardMult);

        // Get digits to not be multiplied
        for (int i = (length - 1); i >= 0; i -= 2)
        {
            // printf("Character: %c\n", cardString[i]);
            int j = (cardString[i] - subtract);
            evenCardNoMult += j;
        }
        printf("Non multiplied sum: %i\n\n", evenCardNoMult);
        evenCardSum = (evenCardMult + evenCardNoMult);
        printf("Sum of both %i\n\n", evenCardSum);
        printf("Even card sum, modulo 10: %i\n", (evenCardSum % 10));
        if ((evenCardSum % 10) == 0)
        {
            return 4;
        }
        else
        {
            return 0;
        }
    }

    // Card has odd number of digits

    else
    {
    int oddCardMult = 0;
    int oddCardNoMult = 0;
    int oddCardSum = 0;
    char tenPlus[8];
        // Multiply every other digit, going back from the second-to-last digit
        for (int i = (length - 2); i >= 0; i -= 2)
        {
            int j = ((cardString[i] - subtract) * 2);
            // printf("%i\n", j);
            if (j > 9)
            {
                sprintf(tenPlus, "%i\n", j);
                for (int i = 0; i < 2; i++)
                {
                    int j = (tenPlus[i] - subtract);
                    oddCardMult += j;
                }
            }
            else
            {
                oddCardMult += j;
            }
        }
        printf("Multiplied sum: %i\n", oddCardMult);

        // Get digits to not be multiplied
        for (int i = (length - 1); i >= 0; i -= 2)
        {
            // printf("Character: %c\n", cardString[i]);
            int j = (cardString[i] - subtract);
            oddCardNoMult += j;
        }
        printf("Non multiplied sum: %i\n\n", oddCardNoMult);
        oddCardSum = (oddCardMult + oddCardNoMult);
        printf("Sum of both %i\n\n", oddCardSum);
        printf("Odd card sum, modulo 10: %i\n", (oddCardSum % 10));
        if ((oddCardSum % 10) == 0)
        {
            return 4;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
