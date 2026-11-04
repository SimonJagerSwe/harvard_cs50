#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept single cli arg
    // printf("Cli arg counter: %i\n", argc);
    if (argc != 2)
    {
        printf("Correct usage: ./recover file.type\n");
        return 1;
    }

    // Open memory card
    char *infile = argv[1];
    printf("Infile:\n%s\n", infile);

    // While there's data to read

        // Create JPEGs from data
}
