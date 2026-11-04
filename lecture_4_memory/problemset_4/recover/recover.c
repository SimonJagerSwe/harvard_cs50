#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept single cli arg
    // printf("Cli arg counter: %i\n", argc);
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open memory card
    char *infile = argv[1];
    printf("Infile:\n%s\n", infile);

    // Create file to work on
    FILE *input = fopen(infile, "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    // Read file
    int slackSpace = 0;
    char *block[512];

    // Fill 512 B block

    // While there's data to read
    // Identify jpeg signature
    char *byte4[16] = {"0xe0", "0xe1", "0xe2", "0xe3",
    "0xe4", "0xe5", "0xe6", "0xe7", "0xe8", "0xe9",
    "0xea", "0xeb", "0xec", "0xed", "0xee", "0xef"};
    for (int i = 0; i < 16; i++)
    {
        printf("Byte: %s\n", byte4[i]);
    }
    char *signature[3] = {"0xff", "0xd8", "0xff"};
    for (int i = 0; i < 3; i++)
    {
        printf("Signature byte #%i: %s\n", i + 1, signature[i]);
    }

    // Create blocks



        // Create JPEGs from data

    fclose(input);
}
