// ########## Problemset 2 - Readability ########## //
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Functions
string textInput();
char counter(string text);
int colemanLiau(int letters, int words, int senteces);
string result(int grade);

// Variables
string text;
char counted;
int sentences;
int words = 1;
int letters;
int grade;
char character;
string score;

// Main function
int main(void)
{
    text = textInput();
    printf("Text input: %s\n", text);
    counted = counter(text);
    printf("Number of letters: %i\nNumber of words: %i\nNumber of sentences: %i\n", letters, words, sentences);
    grade = colemanLiau(letters, words, sentences);
    // printf("Grade: %i\n", grade);
    // printf("Coleman-Liau algorithm run\n");
    // if (grade < 1)
    // result(grade);
}

// Read text input
string textInput(void)
{
    string text = get_string("Text: ");
    return text;
}

char counter(string text)
{   
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] < 90) || (text[i] >= 97 && text[i] < 122))
        {
            if (isalpha(text[i]))
            {
                // printf("%c\n", text[i]);
                letters++;
                // printf("Current number of letters: %i\n", letters);
            }
        }

        else if (text[i] == ' ')
        {
            words++;
        }

        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return 0;
}
    // Iterate over the text to identify whitespaces to count words and to count letters
    /*for (int i = 0; i <= strlen(text); i++)
    {
        character = text[i];
        // Count words by counting blank spaces
        if (character == ' ')
        {
            words++;
        }
        else if (character == '.' || character == '!' || character == '?')
        {
            sentences++;
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
}
    */

// Implement the Coleman-Liau index and return a value
int colemanLiau(int letters, int words, int sentences)
{
    printf("Implementing colemanLiau...\n");
    float let = letters / words * 100;
    printf("Letter input: %i\nLetter float: %f\n", letters, let);
    float sent = sentences / words * 100;
    printf("Sentences input: %i\nSentences float: %f\n", sentences, sent);
    int grade = round(0.0588 * let - 0.296 * sent - 15.8);
    printf("Grade: %d\n", grade);
    return 0;
}

// Check value against grade indicator
string result(int grade)
{
    string result;
    if (grade < 1)
    {
        printf("Before grade 1");
    }
    else if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
    return 0;
}