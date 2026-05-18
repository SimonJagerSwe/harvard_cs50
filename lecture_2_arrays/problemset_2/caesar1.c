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
string wrongInput = "Usage: ./caesar key\n";


// Main function
int main(int argc, string argv[])
{
    // Check argument length
    if (argc == 2)
    {
        printf("Argument taken: %s\n", argv[1]);
        k = strtol(argv[1], NULL, 10);
        printf("K value: %i\n", k);

        // Quit if k value is negative or 0
        if (k <= 0)
        {
            printf("%s", wrongInput);
            return 1;
        }
        else if (k >= 27)
        {
            int reducedK = k % 26; 
            printf("Reduced value: %i\n", reducedK);
        }
    }

    // Quit gracefully if input is invalid
    else
    {
        printf("%s", wrongInput);
        return 1;
    }
    plaintext = getPlain();
    printf("Plaintext: %s\n", plaintext);
}

// Function to get plaintext string and k value
string getPlain()
{
    plaintext = get_string("plaintext: ");
    return plaintext;
}

// Calculate added k value to letter p[i]


// Create new ciphertext
