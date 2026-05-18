// ########## Problemset 2 - Caesar ########## //
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions
string getPlain();

// Variables
int k;


// Main function
int main(int argc, string argv[])
{
    // Check argument length
    if (argc == 2)
    {
        printf("Argument taken: %s\n", argv[1]);
        k = strtol(argv[1], NULL, 10);
        printf("K value: %i\n", k);
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }
}

// Function to get plaintext string and k value


// Calculate added k value to letter p[i]


// Create new ciphertext
