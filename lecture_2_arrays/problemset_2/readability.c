// ########## Problemset 2 - Readability ########## //
#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Functions
string textInput();
char counter(string text);
float calcLetters(char splitText);
float calcSentences(char splitText);
int colemanLiau(float avgLetters, float avgSentences);

// Variables
string text;
char counted;
int words = 1;
int letters = 0;
char character;
// This aray should be usable for checking punctuation, but I haven't figured that out yet
/*char punctuation[23] = {
    '.', ',', '\'', '?', 
    '!', ':', ';', '\"', 
    '(', ')', '{', '}',
    '[', ']', '&', '/', 
    '\\', '-', '_', '#', 
    '%', '+', '*'     
    };*/    
// float avgLetters;
// float avgSentences;
// int index;

// Main function
int main(void)
{
    text = textInput();
    printf("Text input: %s\n", text);
    counted = counter(text);
    printf("Number of words: %i\nNumber of letters: %i\n", words, letters);
    // avgLetters = calcLetters(splitText);
    // printf("Average number of letters per 100 words: %f\n", avgLetters);
    // avgSentences = calcSentences(splitText);
    // printf("Average number of sentences per 100 words: %f\n", avgSentences);
    // index = colemanLiau(avgLetters, avgSentences);
    // printf("Coleman-Liau index: %i\n", index);

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
            // printf("Whitespace found. Current number of words: %i\n", words);
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
                // printf("Character found: %c\nCurrent number of letters: %i\n", character, letters);
            }
        }    
    }

    // Remove one from the letter count to account for break character
    letters--;
    // printf("Number of words: %i\n", words);
    // printf("Number of letters: %i\n", letters);
    return 0;
}

// Calculate average number of letters per 100 words
float calcLetters(char splitText)
{
    return 0;
}

// Calculate the average number of sentences
float calcSentences(char splitText)
{
    return 0;
}

// Implement the Coleman-Liau index and return a value
int colemanLiau(float avgLetters, float avgSentences)
{
    return 0;
}

// Check value against grade indicator
