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
char punctuation[] = {
    '.', ',', '\'', '?', 
    '!', ':', ';', '\"', 
    '(', ')', '{', '}',
    '[', ']', '&', '/', 
    '\\', '-', '_', '#', 
    '%', '+', '*'     
    };
// float avgLetters;
// float avgSentences;
// int index;

// Main function
int main(void)
{
    text = textInput();
    printf("Text input: %s\n", text);
    counted = counter(text);
    printf("Number of words: %i\n", words);
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

// Count words by counting blank spaces
char counter(string text)
{
    printf("Splitting text...\n");
    printf("Text to split:\n%s\n", text);
    for (int i = 0; i < strlen(text); i++)
    {
        printf("%c\n", text[i]);
        if (text[i] == ' ')
        {
            words++;
        }
        
    }
    printf("Number of words: %i\n", words);
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
