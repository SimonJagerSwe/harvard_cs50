// ########## Problemset 2 - Substitution ########## //
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


// Functions
int invalidInput(int code);
int keyChecker(string keyArg);
string getPlain();
char applyCipher(string plaintext);

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
int keyStatus;
int keyIndex = 1;
string plaintext;
char ciphertext;

// ########## Main function ########## //
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
    // printf("%i\n", strlen(keyArg));

    // Check key for status code, terminate if keyStatus is 1
    keyStatus = keyChecker(keyArg);
    // printf("Key status: %i\n", keyStatus);
    if (keyStatus == 1)
    {
        invalidInput(0);
        return 1;
    }

    // Iterate over alphabet array to print test confirmation
    for (int i = 0; i < 26; i++)
    {
        printf("Original char: %c | Subsituted char: %c\n", alphabet[i][0], alphabet[i][1]);
    }

    // Get plaintext string after confirming key validity
    plaintext = getPlain();
    printf("Received plaintext: %s\n", plaintext);
    
    // Call cipher application
    ciphertext = applyCipher(plaintext);
    printf("Ciphertext: \n");
    return 0;
}

// Check key validity
int keyChecker(string keyArg)
{    
    // Check length of key
    if (strlen(keyArg) != 26)
    {
        return 1;
    }

    // Check string character case is upper, lower or invalid
    for (int i = 0; i < strlen(keyArg); i++)
    {
        int keyInt = keyArg[i];

        // If uppercase, add to alphabet array
        if (keyInt >= 65 && keyInt <= 90)
        {
            // printf("Character #%i: %c\nUppercase character, adding to alphabet array\n", keyIndex, keyInt);
            // keyIndex++;
            char keyChar = keyInt;
            alphabet[alphabetIndex][1] = keyChar;
            alphabetIndex++;
        }

        // If lowercase, turn to uppercase by subtracting 32 from key ASCII value, then add to alphabet array
        else if (keyInt >= 97 && keyInt <= 122)
        {
            // printf("Character #%i: %c\nLowercase character detected, turning to uppercase...\n", keyIndex, keyInt);
            int upperCharInt = keyInt - 32;
            // printf("Upper character: %c, adding to alphabet array\n", upperCharInt);
            // keyIndex++;
            char upperChar = upperCharInt;
            alphabet[alphabetIndex][1] = upperChar;
            alphabetIndex++;
        }

        // Terminate if invalid character is present
        else
        {
            return 1;
        }        
    }
    return 0;
}

// Get plaintext
string getPlain()
{
    string plain = get_string("plaintext: ");
    return plain;
}

// Apply cipher
char applyCipher(string plaintext)
{
    printf("%s\n", plaintext);
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char character = plaintext[i];
        int charInt = plaintext[i];
        printf("Character: %c | Character int: %i\n", character, charInt);
        if (charInt >= 65 && charInt <=90)
        {
            printf("Uppercase character detected: %c\n", character);

        }
    }
    return 0;
}


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
    return 0;
}
