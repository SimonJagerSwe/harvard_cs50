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
int words = 1;  // Initialise as 1 in order to account for lack of whitespace after the final sentence
int letters;
int grade;
char character;
string score;

// Main function
int main(void)
{
    text = textInput();
    counted = counter(text);
    grade = colemanLiau(letters, words, sentences);
    score = result(grade);
}

// Read text input
string textInput(void)
{
    string text = get_string("Text: ");
    return text;
}

char counter(string text)
{   
    // Iterate over the text to count letters
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] < 90) || (text[i] >= 97 && text[i] < 122))
        {
            if (isalpha(text[i]))
            {
                letters++;
            }
        }

        // Iterate over text to count whitespaces to count words
        else if (text[i] == ' ')
        {
            words++;
        }

        // Iterate over the text to count periods, exlamation marks and question marks to count sentences
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return 0;
}

// Implement the Coleman-Liau index and return a value
int colemanLiau(int letters, int words, int sentences)
{
    float let = (float) letters / (float) words * 100;
    float sent = (float) sentences / (float) words * 100;
    int grade = round(0.0588 * let - 0.296 * sent - 15.8);
    return grade;
}

// Check value against grade indicator
string result(int grade)
{
    string result;
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Before Grade 1\n");
    }
    return 0;
}
