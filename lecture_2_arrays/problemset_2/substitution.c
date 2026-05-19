// ########## Problemset 2 - Substitution ########## //
#include<cs50.h>
#include<stdio.h>


// Functions
int invalidInput();

// Variables


// Main function
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        invalidInput();
    }
}

// Get plaintext


// Apply cipher


// Return ciphertext


// Exit on invalid argument
int invalidInput()
{
    printf("Usage: ./substitution key\n");
    return 1;
}