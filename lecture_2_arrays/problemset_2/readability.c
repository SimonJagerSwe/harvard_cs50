// ########## Problemset 2 - Readability ########## //
#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Functions
string textInput();
char counter(string text);
int colemanLiau(int words, int letters);

// Variables
string text;
char counted;
int words = 1;
int letters = 0;
int grade;
char character;

// Main function
int main(void)
{
    text = textInput();
    printf("Text input: %s\n", text);
    counted = counter(text);
    printf("Number of words: %i\nNumber of letters: %i\n", words, letters);
    grade = colemanLiau(words, letters);
    printf("Coleman-Liau algorithm run\n");
}

// Read text input
string textInput(void)
{
    string text = get_string("Text: ");
    return text;
}

char counter(string text)
{   
    // printf("Text to count:\n%s\n", text);
    // Iterate over the text to identify whitespaces to count words and to count letters
    for (int i = 0; i <= strlen(text); i++)
    {
        character = text[i];
        // Count words by counting blank spaces
        if (character == ' ')
        {
            words++;
        }
        else
        {            
            if (
                character != '.' &&
                character != ',' &&
                character != '!' &&
                character != '?' &&
                character != ':' &&
                character != ';' &&
                character != '"' &&
                character != '&' &&
                character != '%' &&
                character != '\'' &&
                character != '\\' &&
                character != '/' &&
                character != '+' &&
                character != '-' &&
                character != '*' &&
                character != '_' &&
                character != '(' &&
                character != ')' &&
                character != '{' &&
                character != '}' &&
                character != '[' &&
                character != ']' &&
                character != '`')
            {
                letters++;
            }
        }    
    }

    // Remove one from the letter count to account for break character
    letters--;
    return 0;
}

// Implement the Coleman-Liau index and return a value
int colemanLiau(int words, int letters)
{
    printf("Implementing colemanLiau...\n");
    return 0;
}

// Check value against grade indicator
