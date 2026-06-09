#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Check each vote to see if the name corresponds to a name given in the argv:s
    for (int i = 0; i < candidate_count; i++)
    {
        // If vote is valid, add one vote to the candidate's tally
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    // If vote is invalid, return false in order for the main function to print "Invalid vote."
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Initialise variable to store highest number of votes
    int maxVotes = 0;

    // Iterate over candidates list to find largest number of votes and store that number in maxVotes variable
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxVotes)
        {
            maxVotes = candidates[i].votes;
        }
    }

    // Iterate over candidates list to find candidates with a vote count matching maxVotes and print their name(s)
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxVotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
