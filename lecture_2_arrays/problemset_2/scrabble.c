// ########## Problemset 2 - Scrabble ########## //
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Functions
string getInput(int playerNumber);
int calculatePoints(string input);
int compareScores(int score1, int score2);

// Variables
int playerNumber = 1;
string player1;
int score1;
string player2;
int score2;
int result;
char alphabet[26][2] = {
    {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 4},
    {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8}, {'K', 5}, {'L', 1},
    {'M', 3}, {'N', 1}, {'O', 1}, {'P', 3}, {'Q', 10}, {'R', 1},
    {'S', 1}, {'T', 1}, {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8},
    {'Y', 4}, {'Z', 10}};


// Main function
int main(void)
{    
    // Get input from both players
    player1 = getInput(playerNumber);
    playerNumber += 1;
    player2 = getInput(playerNumber);

    // Calculate score for each player by traversing alphabet array
    score1 = calculatePoints(player1);
    score2 = calculatePoints(player2);

    // Compare the scores
    result = compareScores(score1, score2);

    // Return result
    if (result == 0)
    {
        printf("Player 1 wins!\n");
    }
    else if (result == 1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Get user input
string getInput(int playerNumber)
{
    string word = get_string("Player %i: ", playerNumber);
    return word;
}

// Calculate points
int calculatePoints(string input)
{
    int score = 0;
    char letter;

    // Iterate over characters in word provided by user
    for (int i = 0; i < strlen(input); i++)
    {
        // Uppercase all characters to keep alphabet array to 26 sub-arrays instead of 52
        letter = toupper(input[i]);

        // Iterate over characters in alphabet array
        for (int i = 0; i < sizeof(alphabet); i++)
        {
            // Match character in word to character in array
            if (letter == alphabet[i][0])
            {
                // Add the score (int) associated with the characters in the array
                score += alphabet[i][1];
            }
            else {}
        }
    }
    return score;
}

// Compare points and return a result
int compareScores(int score1, int score2)
{
    if (score1 > score2)
    {
        return 0;
    }
    else if (score1 < score2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
