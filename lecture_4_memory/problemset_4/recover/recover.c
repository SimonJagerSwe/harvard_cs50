#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept single cli arg
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
    uint8_t bufferBlock[512];
    size_t bytesRead;
    int block = 0;

    printf("Bytes in file: %lu\n", sizeof(input));

    // Fill 512 B block
    while ((bytesRead = fread(bufferBlock, 1, sizeof(bufferBlock), input)) > 0)
    {
        printf("Block %d has %zu bytes\n", block, bytesRead);
        for (size_t i = 0; i < bytesRead; i++)
        {
            printf("0x%02x ", bufferBlock[i]);
        }
        block++;
        printf("\n");
    }


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
    for (size_t i = 0; i < 3; i++)
    {
        printf("Signature byte #%i: %s\n", i + 1, signature[i]);
    }

    // Create blocks



        // Create JPEGs from data

    fclose(input);
}
