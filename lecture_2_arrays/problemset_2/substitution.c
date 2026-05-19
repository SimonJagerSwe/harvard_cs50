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

    for (int i = 0; i < strlen(keyArg); i++)
    {
        int keyChar = keyArg[i];
        printf("%i\n", keyChar);
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
