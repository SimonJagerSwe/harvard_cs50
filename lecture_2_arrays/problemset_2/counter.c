#include <cs50.h>
#include <stdio.h>
#include <string.h>

string string1 = "ABCDaFGHIAKlmboPQBSTcvWXYZ";
string string2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// int counter1 = 0;
// int counter2 = counter1 + 1;

int main(void)
{
    for (int i = 0; i < strlen(string1); i++)
    {   
        int charInt = string1[i];
        if (charInt >= 65 && charInt <= 90)
        {
            int charLower = charInt + 32;
            for (int j = i + 1; j < strlen(string1); j++)
            {
                if (string1[j] == string1[i] || string1[j] == (char)charLower)
                {
                    printf("Uppercase duplicate found: %c - %c\n", string1[j], string1[i]);
                }
            }
        }

        else
        {
            int charUpper = charInt - 32;
            for (int j = i + 1; j < strlen(string1); j++)
            {
                if (string1[j] == string1[i] || string1[j] == (char)charUpper)
                {
                    printf("Uppercase duplicate found: %c - %c\n", string1[i], string1[j]);
                }
            }
        }
    }
}
