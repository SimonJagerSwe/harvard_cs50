#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    // Accept single cli arg
    char *filters = "";
    char raw = getopt(argc, argv, filters);
    printf("%d", argv);

    // Open memory card

    // While there's data to read

        // Create JPEGs from data
}