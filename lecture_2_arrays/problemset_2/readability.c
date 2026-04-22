// ########## Problemset 2 - Readability ########## //
#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Functions
string textInput();
char splitter(string text);
float calcLetters(char splitText);
float calcSentences(char splitText);
int colemanLiau(float avgLetters, float avgSentences);

// Variables
string text;
char splitText;
float avgLetters;
float avgSentences;
int index;

// Main function
int main(void)
{
    text = textInput();
    printf("Text input: %s\n", text);
    splitText = splitter(text);
    printf("Split text: %c\n", splitText);
    avgLetters = calcLetters(splitText);
    printf("Average number of letters per 100 words: %f\n", avgLetters);
    avgSentences = calcSentences(splitText);
    printf("Average number of sentences per 100 words: %f\n", avgSentences);
    index = colemanLiau(avgLetters, avgSentences);
    printf("Coleman-Liau index: %i\n", index);

}

// Read text input
string textInput(void)
{

}

// Split text into segments of 100 words
char splitter(string text)
{

}

// Calculate average number of letters per 100 words
float calcLetters(char splitText)
{

}

// Calculate the average number of sentences
float calcSentences(char splitText)
{

}

// Implement the Coleman-Liau index and return a value
int colemanLiau(float avgLetters, float avgSentences)
{
    
}

// Check value against grade indicator
