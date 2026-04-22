// ########## Problemset 2 - Scrabble ########## //
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Functions
string getInput();
int calculatePoints(string input);

// Variables
string player1;
int score1;
string player2;
int score2;
char alphabet[26][2] = {
    {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 4},
    {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8}, {'K', 5}, {'L', 1},
    {'M', 3}, {'N', 1}, {'O', 1}, {'P', 3}, {'Q', 10}, {'R', 1},
    {'S', 1}, {'T', 1}, {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8},
    {'Y', 4}, {'Z', 10}};


// Main function
int main(void)
{    
    player1 = getInput();
    // printf("Player 1: %s\n", player1);
    player2 = getInput();
    // printf("Player 2: %s\n", player2);
    score1 = calculatePoints(player1);
    printf("Player 1 score: %i\n", score1);
    score2 = calculatePoints(player2);
    printf("Player 2 score: %i\n", score2);
}

// Get user input x2
string getInput()
{
    string word = get_string("Player 1: ");
    return word;
}

// Calculate points
int calculatePoints(string input)
{
    printf("Player input: %s\n", input);
    int score = 0;
    char letter;
    for (int i = 0; i < strlen(input); i++)
    {
        letter = toupper(input[i]);
        printf("%c\n", letter);
        for (int i = 0; i < sizeof(alphabet); i++)
        {
            if (letter == alphabet[i][0])
            {
                printf("Character found in array: %c\n", letter);
                printf("Character score: %i\n", alphabet[i][1]);
                score += alphabet[i][1];
            }
            else
            {
                printf("");
            }
        }
        printf("\n");
    }
    return score;
}

// Compare points


// Return a result

