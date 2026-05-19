// ########## Problemset 2 - Substitution ########## //
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


// Functions
int invalidInput(int code);

// Variables
char alphabet[26][2] = {
    {'A', }, {'B', }, {'C', }, {'D', },
    {'E', }, {'F', }, {'G', }, {'H', },
    {'I', }, {'J', }, {'K', }, {'L', },
    {'M', }, {'N', }, {'O', }, {'P', },
    {'Q', }, {'R', }, {'S', }, {'T', },
    {'U', }, {'V', }, {'W', }, 
    {'X', }, {'Y', }, {'Z', }
};
int alphabetIndex = 0;
int keyIndex = 1;

// Main function
int main(int argc, char *argv[])
{
    // Check number of arguments, if not 2, exit program
    if (argc != 2)
    {
        invalidInput(0);
        return 1;
    }

    // Convert key to string
    string keyArg = argv[1];
    printf("%s\n", keyArg);
    printf("%i\n", strlen(keyArg));

    // Check length of key
    if (strlen(keyArg) != 26)
    {
        invalidInput(1);
        return 1;
    }

    // Check if letters are lower or uppercase, if lower, convert to upper by subtracting 32 from character's ascii value
    for (int i = 0; i < strlen(keyArg); i++)
    {
        int keyInt = keyArg[i];
        if (keyInt >= 65 && keyInt <= 90)
        {
            printf("Character #%i: %c\nUppercase character, adding to alphabet array\n", keyIndex, keyInt);
            keyIndex++;
        }
        else if (keyInt >= 97 && keyInt <= 122)
        {
            printf("Character #%i: %c\nLowercase character detected, turning to uppercase...\n", keyIndex, keyInt);
            int upperCharInt = keyInt - 32;
            printf("Upper character: %c, adding to alphabet array\n", upperCharInt);
            keyIndex++;
        }
    }
}

// Get plaintext


// Apply cipher


// Return ciphertext


// Exit on invalid argument
int invalidInput(int code)
{
    if (code == 0)
    {
        printf("Usage: ./substitution key\n");
    }
    else if (code == 1)
    {
        printf("Key must contain 26 characters\n");
    }
}
