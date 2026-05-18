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
string plaintext;
// char cipherImplement[];
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
    printf("Executing cipher on \"%s\"...\n", plaintext);
    for (int i = 0; i < strlen(plaintext); i++)
    {
        int letterInt = plaintext[i];
        // printf("Char: %c\nInt: %i\n", letter, letterInt);
        if ((letterInt >= 65 && letterInt <= 90) || (letterInt >= 97 && letterInt <= 122))
        {
            int newInt = letterInt + k;
            if (newInt > 90 && newInt < 97)
            {
                printf("Uppercase character out of bounds\n");
            }
            else if (newInt > 122)
            {
                printf("Lowercase character out of bounds\n");
            }
            char newLetter = newInt;            
            printf("New int: %i\n", (newInt));
            printf("New char: %c\n", newLetter);
        }
    }
    // printf("\n");
    return 0;
}