#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t bufferBlock[512];
size_t bytesRead;
unsigned char signature[3] = {0xff, 0xd8, 0xff};
unsigned char byte4[16] = {0xe0, 0xe1, 0xe2, 0xe3,
    0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
    0xea, 0xeb, 0xec, 0xed, 0xee, 0xef};
int imgCounter = 0;
int block = 0;


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

    // Fill 512 B block
    while ((bytesRead = fread(bufferBlock, 1, sizeof(bufferBlock), input)) > 0)
    {
        if (bufferBlock[0] == signature[0] && 
            bufferBlock[1] == signature[1] && 
            bufferBlock[2] == signature[2])
        {
            for (size_t i = 0; i < sizeof(byte4); i++)
            {
                if (bufferBlock[3] == byte4[i])
                {
                    printf("\n\nBlock is start of image file!\n");
                    imgCounter++;            
                    printf("Number of images found: %i\n", imgCounter);
                }
            }
        }
        printf("0x%02x 0x%02x 0x%02x 0x%02x\n", bufferBlock[0], bufferBlock[1], bufferBlock[2], bufferBlock[3]);
        block++;
        printf("\n");
    }

    // While there's data to read
    // Identify jpeg signature
    
    
        // Create JPEGs from data

    fclose(input);
}
