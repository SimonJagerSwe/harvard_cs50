// ########## Problemset 2 - Caesar ########## //
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Functions


// Variables
int k;

// Main function
int main(int argc, string argv[])
{
    k = strtol(argv[1], NULL, 10);
    if (argc != 2 || k <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    printf("K value: %i\n", k);
}