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

    // Create files to work on
    FILE *input = fopen(infile, "rb");
    if (input == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    FILE *output = NULL;
    const char fileType[] = ".jpg";
    char fileName[4];
    char fullName[8];

    // Fill 512 B block
    while ((bytesRead = fread(bufferBlock, 1, sizeof(bufferBlock), input)) > 0)
    {
        // Check if first three bytes of a block corresponds to the given signature
        if (bufferBlock[0] == signature[0] &&
            bufferBlock[1] == signature[1] &&
            bufferBlock[2] == signature[2])
        {
            // If so, also check fourth byte to see if it matches the pattern
            for (size_t i = 0; i < sizeof(byte4); i++)
            {
                if (bufferBlock[3] == byte4[i])
                {
                    // If all four first bytes match the pattern, create file name
                    printf("\n\nBlock is start of image file!\n");
                    if (output != NULL)
                    {
                        fclose(output);
                    }
                    snprintf(fileName, sizeof(fileName), "%03i", imgCounter);
                    snprintf(fullName, sizeof(fullName), "%s%s", fileName, fileType);
                    output = fopen(fullName, "wb");
                    imgCounter++;
                    printf("Number of images found: %i\n", imgCounter);
                }
            }
        }
        // Write the output to the file using the file name created above
        if (output != NULL)
        {
            fwrite(bufferBlock, 1, bytesRead, output);
        }
        printf("0x%02x 0x%02x 0x%02x 0x%02x\n", bufferBlock[0], bufferBlock[1], bufferBlock[2], bufferBlock[3]);
        block++;
        printf("\n");
    }
    if (output != NULL)
    {
        fclose(output);
    }
    fclose(input);
}
