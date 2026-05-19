// ########## Problemset 2 - Substitution ########## //
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Functions
int invalidInput(int code);

// Variables


// Main function
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        invalidInput(0);
    }
    string argument = argv[1];
    printf("%s\n", argument);
    printf("%i\n", strlen(argument));

    if (strlen(argument) != 26)
    {
        invalidInput(1);
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
        return 1;
    }
    else if (code == 1)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
}