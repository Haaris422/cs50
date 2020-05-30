#include <stdio.h>
#include <string.h>
#include <cs50.h>

#define MAX 9

typedef struct
{
    string name;
    int vote;
}
candidate; 

candidate candidates[MAX];

int candidate_count;

bool vote(string name);

void print_winner (void);

int main (int argc, string argv[])

{

    candidate_count = argc - 1;
    
    for (int i = 0; i < candidate_count ; i++)
    {
      candidates[i].name = argv[i + 1];
      candidates[i].vote = 0;
    }
    
    int voter_count = get_int("Number of voters: "), i;
    
    for (i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        if (!vote(name))
        {
            printf("Invalid vote\n");
        }
    }
    
    print_winner();
}    



bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].vote++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int w = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].vote > w )
        {
            w = candidates[i].vote;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].vote == w)
        {
            printf("%s \n", candidates[i].name);
        }
    }
    return;
}