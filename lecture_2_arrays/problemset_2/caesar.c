// ########## Problemset 2 - Caesar ########## //
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Functions
string getPlain();

// Variables
int k;
string plaintext;
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
    printf("Received plaintext: %s\n", plaintext);    
}


// Function to get plaintext
string getPlain()
{
    string input = get_string("plaintext: ");
    return input;
}