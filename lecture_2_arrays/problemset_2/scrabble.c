// ########## Problemset 2 - Scrabble ########## //
#include <stdio.h>
#include <cs50.h>

// Functions
string getInput();
int calculatePoints(string input);

// Variables
string player1;
int score1;
string player2;
int score2;


// Main function
int main(void)
{    
    player1 = getInput();
    printf("Player 1: %s\n", player1);
    player2 = getInput();
    printf("Player 2: %s\n", player2);
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
    int score = 0;
    return score;
}

// Compare points


// Return a result

