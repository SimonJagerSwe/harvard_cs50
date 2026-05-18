// ########## Problemset 2 - Caesar ########## //
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Functions
string getPlain();
string implementCipher(int k, string plaintext);

// Variables
int k;
int cipherIndex = 0;
string plaintext;
char cipherImplement[128];
string ciphertext;

// Main function
int main(int argc, string argv[])
{
    k = strtol(argv[1], NULL, 10);
    if (argc != 2 || k <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else if (k >= 27)
    {
        printf("Cycling through alphabet...\n");
        k = k % 26;
    }
    printf("K value: %i\n", k);
    plaintext = getPlain();
    ciphertext = implementCipher(k, plaintext);
    // printf("%c\n", ciphertext);
}


// Function to get plaintext
string getPlain()
{
    string input = get_string("plaintext: ");
    return input;
}


// Function to create cyphertext
string implementCipher(int k, string plaintext)
{
    // Iterate over each character in plaintext string
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Convert character to int to check if it matches an ascii number
        int letterInt = plaintext[i];
        if ((letterInt >= 65 && letterInt <= 90) || (letterInt >= 97 && letterInt <= 122))
        {
            // Add k value to letter ascii number
            int newInt = letterInt + k;
            printf("Old int: %i\nNew int: %i\n",letterInt, newInt);
            
            // If the new ascii value wraps around the alphabet, subtract 26  to get correct letter and add it to the ciphertext
            if ((newInt > 90 && newInt <= 97) || newInt > 122)
            {
                printf("Character out of bounds\n");
                int reducedInt = newInt - 26;
                printf("New int: %i\n", reducedInt);
                char reducedChar = reducedInt;
                printf("New char: %c\n", reducedChar);
                cipherImplement[cipherIndex] = reducedChar;
                cipherIndex++;
            }

            // Add already valid new ascii number to ciphertext
            else
            {
            char newLetter = newInt;
            printf("Character in bounds\n");
            printf("New int: %i\n", (newInt));
            printf("New char: %c\n", newLetter);
            cipherImplement[cipherIndex] = newLetter;
            cipherIndex++;
            }
        }
    }
    // Return ciphertext
    // return cipherImplement;
    return 0;
}
