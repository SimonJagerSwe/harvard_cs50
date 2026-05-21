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
char ciphertext[128];
int ciphertextIndex = 0;

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

    // Check key for status code, terminate if keyStatus is 1
    keyStatus = keyChecker(keyArg);
    if (keyStatus == 1)
    {
        invalidInput(0);
        return 1;
    }

    // Get plaintext string after confirming key validity
    plaintext = getPlain();

    // Call cipher application
    ciphertext[127] = applyCipher(plaintext);
    printf("ciphertext: %s\n", ciphertext);
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
            char keyChar = keyInt;
            alphabet[alphabetIndex][1] = keyChar;
            alphabetIndex++;
        }

        // If lowercase, turn to uppercase by subtracting 32 from key ASCII value, then add to alphabet array
        else if (keyInt >= 97 && keyInt <= 122)
        {
            int upperCharInt = keyInt - 32;
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

    // Check key for duplicates
    for (int i = 0; i < strlen(keyArg); i++)
    {
        int charInt = keyArg[i];

        // Check lowercase version of provided uppercase character
        if (charInt >= 65 && charInt <= 90)
        {
            int charLower = charInt + 32;
            for (int j = i + 1; j < strlen(keyArg); j++)
            {
                if (keyArg[j] == keyArg[i] || keyArg[j] == (char)charLower)
                {
                    return 1;
                }
            }
        }

        // Check uppercase version of provided lowercase character
        else
        {
            int charUpper = charInt - 32;
            for (int j = i + 1; j < strlen(keyArg); j++)
            {
                if (keyArg[j] == keyArg[i] || keyArg[j] == (char)charUpper)
                {
                    return 1;
                }
            }
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
char applyCipher(string plaintextInput)
{
    for (int i = 0; i < strlen(plaintextInput); i++)
    {
        char plainCharacter = plaintextInput[i];
        int charInt = plaintextInput[i];

        // Check if the character is uppercase
        // in which case, switch it to cipher character
        if (charInt >= 65 && charInt <=90)
        {
            for (int j = 0; j < 26; j++)
            {
                if (plainCharacter == alphabet[j][0])
                {
                    ciphertext[ciphertextIndex] = alphabet[j][1];
                    ciphertextIndex++;
                }
            }
        }

        // Check if character is lowercase
        // in which case convert to upper, find equavalent in alphabet array
        // find uppercase cipher character and make lowercase
        else if (charInt >= 97 && charInt <= 122)
        {
            char upperChar = charInt - 32;
            for (int k = 0; k < 26; k++)
            {
                if (upperChar == alphabet[k][0])
                {
                    char lowerChar = (alphabet[k][1]) + 32;
                    ciphertext[ciphertextIndex] = lowerChar;
                    ciphertextIndex++;
                }
            }
        }

        // If character is not alphabetical, place in ciphertext as is
        else
        {
            ciphertext[ciphertextIndex] = plainCharacter;
            ciphertextIndex++;
        }
    }
    return ciphertext[127];
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
