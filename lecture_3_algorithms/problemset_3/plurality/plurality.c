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
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int top = 0;
    string leader;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        printf("Candidate: %s | Compare: %s\n", candidates[i].name, candidates[i + 1].name);
        /*printf("Counting votes for %s | Votes: %i\n\n", candidates[i].name, candidates[i].votes); // printf("Candidate: %s | Votes: %i | Max votes: %i | Current leader: %s\n", candidates[i].name, candidates[i].votes, max, leader);
        if (candidates[i].votes > candidates[i + 1].votes)
        {
            leader = candidates[i].name;
            top = candidates[i].votes;            
        }
        else
        {
            leader = candidates[i + 1].name;
            top = candidates[i + 1].votes;
        }        
        printf("Leader: %s | Votes: %i\n\n", leader, top);

        for (int j = i + 1; j < candidate_count; j++)
        {
            printf("Candidate to compare: %s | Votes: %i\n", candidates[j].name, candidates[j].votes);
            if (candidates[i].votes > candidates[j].votes)
            {
                printf("%s has more votes than %s\n", candidates[i].name, candidates[j].name);
                leader = candidates[i].name;
                top = candidates[i].votes;
                printf("Current leader: %s | Current max votes: %i\n", leader, top);
            }
            else
            {
                leader = candidates[j].name;
                top = candidates[j].votes;
                printf("Current leader: %s | Current max votes: %i\n", leader, top);
            }
            printf("\n\n");
        }
        if (candidates[i].votes > top)
        {
            printf("%s has more votes than %s\n", candidates[i].name, leader);
            leader = candidates[i].name;
            top = candidates[i].votes; 
            printf("Current leader: %s | Current max votes: %i\n", leader, top);           
        }
        else
        {
            printf("Current leader: %s | Current max votes: %i\n", leader, top);
        }
        printf("Winner is %s\n\n", leader);*/
    }
    // printf("%s\n", leader);
    return;
}
