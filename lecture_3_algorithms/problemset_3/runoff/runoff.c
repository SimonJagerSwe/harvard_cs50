// ########## Problemset 3 - Runoff ########## //
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Iterate over candidate names to check validity of vote cast
    for (int i = 0; i < candidate_count; i++)
    {
        // If the name on the cast vote matches a name in the candidates list,
        // register vote
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    // If vote is invalid, return false
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Iterate over voters
    for (int i = 0; i < voter_count; i++)
    {
        // Iterate over each candidate for every voter
        for (int j = 0; j < candidate_count; j++)
        {
            // If candidate is not yet eliminated,
            // add the vote cast for the candidate
            if (candidates[i].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Find the number of required votes by dividing
    // the total number of votes by two
    int requiredVotes = voter_count / 2;

    // Iterate over candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Check that candidate is not eliminated,
        // if not, check if the candidate has
        // more than half of the votes, in which case print as winner
        if ((candidates[i].eliminated == false) && candidates[i].votes > requiredVotes)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Find lowest amount of votes given to any candidate
    int min;

    // Iterate over candidates again
    for (int i = 0; i < candidate_count; i++)
    {
        // Make sure candidate is not eliminated
        if (candidates[i].eliminated == false)
        {
            // If one or more candidates have 0 votes, set minimum value to 0
            if (i == 0)
            {
                min = candidates[i].votes;
            }

            // If no candidate has 0 votes, see who has the fewest
            // and set that number of votes as minimum value
            if (candidates[i].votes < min)
            {
                min = candidates[i].votes;
            }
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Iterate over candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Make sure candidate is still in the running
        // and that candidate doesn't have the minimum amount of votes
        if ((candidates[i].eliminated == false) && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Iterate...
    for (int i = 0; i < candidate_count; i++)
    {
        // If the candidate is in the running, but has a number of votes
        // corresponding to the lowest amount of votes possible, eliminate candidate
        if ((candidates[i].eliminated == false) && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
