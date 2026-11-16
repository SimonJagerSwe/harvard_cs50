#include <stdio.h>
#include <stdlib.h>

int isJpegStart(const unsigned char block[], size_t bytesRead)
{
    return bytesRead >= 4 &&
    block[0] == 0xff &&
    block[1] == 0xd8 &&
    block[2] == 0xff &&
    (block[3] & 0x0f) == 0xe0;
}

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
    unsigned char bufferBlock[512];
    size_t bytesRead;
    int block = 0;

    // Fill 512 B block
    /*for (; (bytesRead = fread(bufferBlock, 1, sizeof bufferBlock, input)) > 0; block++)
    {
        printf("Block %d has %zu bytes\n", block, bytesRead);

        for (size_t i = 0; i < bytesRead; i++)
        {
            printf("0x%02x ", bufferBlock[i]);
        }
        if (isJpegStart(bufferBlock, bytesRead))
        {
            printf("Jpeg signature at block %d: %02X %02X %02X %02X\n",
            block,
            bufferBlock[0],
            bufferBlock[1],
            bufferBlock[2],
            bufferBlock[3]);
            printf("\n");
        }
    }



    // Check for sequential 0x00 bits
    for (int i = 0; i < sizeof bufferBlock; i++)
    {
        if (bufferBlock[i] == "0x00" && bufferBlock[i - 1] == "0x00")
        printf("Slackspace detected, moving on to next block");
        break;
    }*/


    // While there's data to read
    // Identify jpeg signature
    char *byte4[16] = {"0xe0", "0xe1", "0xe2", "0xe3",
    "0xe4", "0xe5", "0xe6", "0xe7", "0xe8", "0xe9",
    "0xea", "0xeb", "0xec", "0xed", "0xee", "0xef"};
    // for (int i = 0; i < 16; i++)
    // {
    //     printf("Byte: %s\n", byte4[i]);
    // }
    char *signature[3] = {"0xff", "0xd8", "0xff"};
    for (int i = 0; i < 3; i++)
    {
        printf("Signature byte #%i: %s\n", i + 1, signature[i]);
    }

    // Create blocks



        // Create JPEGs from data

    fclose(input);
}
