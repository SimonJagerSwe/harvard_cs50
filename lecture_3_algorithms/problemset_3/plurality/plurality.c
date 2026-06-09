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
    // Initialise variables used to temporarily store highest number of votes and leading candidate name
    int top = candidates[0].votes;
    string leader = candidates[0].name;
    string commaSep = ", ";
    

    // Iterate over all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        string nameA = candidates[i].name;
        int votesA = candidates[i].votes;

        printf("Candidate for comparing: %s | Candidate votes: %i\n", nameA, votesA);
        printf("Comparing %s to %s...\n", leader, nameA);
        if (votesA < top)
        {
            printf("%s has fewer votes than %s\n", nameA, leader);
        }

        else if (votesA > top)
        {
            printf("%s has more votes than %s\n", nameA, leader);
            leader = nameA;
            top = votesA;
            printf("New leader: %s | New top votes: %i\n", leader, top);
        }

        else
        {
            printf("Draw, solution pending...\n");
        }

        
        /*if (cVotes < top)
        {
            printf("%s has fewer votes than %s\n", cName, leader);
        }
        else if (cVotes > top)
        {
            leader = cName;
            top = cVotes;
            printf("New election leader: %s | leading number of votes: %i\n", leader, top);
        }
        else
        {
            printf("%s has same number of votes as leader\n", cName);
            printf("Comp result: %i\n", strcmp(leader, cName));
            if (strcmp(leader, cName) != 0)
            {
                printf("%s is different from %s\n", cName, leader);
                string temp = strcat(leader, commaSep);
                printf("ext str: %s\n", temp);
                leader = strcat(temp, cName);
            }
            else
            {
                printf("Self compare, skipping...\n");
            }
        }*/

        // printf("Leader is %s with %i votes\n", leader, top);
        // printf("\n");
    }    
    return;
}
