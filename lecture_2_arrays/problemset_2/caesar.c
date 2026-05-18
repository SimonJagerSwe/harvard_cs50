// ########## Problemset 2 - Caesar ########## //
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Functions
string getPlain();
string implementCipher(int k, string plaintext);

// Variables
string argumentError = "Usage: ./caesar key";
int k;
int cipherIndex = 0;
string plaintext;
char cipherImplement[128];

// Main function
int main(int argc, char *argv[])
{    
    // Check cli argument length, exit if not 2
    if (argc != 2)
    {
        printf("%s\n", argumentError);
        return 1;
    }

    // Check if cli argument contains non-numeric characters and terminate if it does
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        int testA = argv[1][i]; 
        if (testA < 48 || testA > 57)
        {
            return 1;
        }
    }

    k = strtol(argv[1], NULL, 10);

    if (k <= 0)
    {
        printf("%s\n", argumentError);
        return 1;
    }

    else if (k >= 27)
    {
        k = k % 26;
    }
    plaintext = getPlain();
    string output = implementCipher(k, plaintext);
    printf("ciphertext: %s\n", output);
    return 0;
}


// Function to get plaintext
string getPlain()
{
    string input = get_string("plaintext: ");
    return input;
}


// Function to create cyphertext
string implementCipher(int key, string input)
{
    // Iterate over each character in plaintext string
    for (int i = 0; i < strlen(input); i++)
    {
        // Convert character to int to check if it matches an ascii number
        int letterInt = input[i];

        // If character is not a letter, add it as is
        if (letterInt >= 32 && letterInt <= 64)
        {
            char punctuation = letterInt;
            cipherImplement[cipherIndex] = punctuation;
            cipherIndex++;
        }
        else if ((letterInt >= 65 && letterInt <= 90) || (letterInt >= 97 && letterInt <= 122))
        {
            // Add k value to letter ascii number
            int newInt = letterInt + key;

            // If the new ascii value wraps around the alphabet, subtract 26  to get correct letter and add it to the ciphertext
            if ((newInt > 90 && newInt <= 97) || newInt > 122)
            {
                int reducedInt = newInt - 26;
                char reducedChar = reducedInt;
                cipherImplement[cipherIndex] = reducedChar;
                cipherIndex++;
            }

            // Add already valid new ascii number to ciphertext
            else
            {
                char newLetter = newInt;
                cipherImplement[cipherIndex] = newLetter;
                cipherIndex++;
            }
        }
    }
    return cipherImplement;
}
