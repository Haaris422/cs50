#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int vote;
}
c; 

c candidate[MAX];

int candidate_count;
bool vote(string name);
void print_winner (void);

int main (int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Error");
        return 1;
    }
   
    candidate_count = argc - 1;
    
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %d\n", MAX);
        return 2;
    }
    
    for (int i = 0; i < candidate_count ; i++)
    {
      candidate[i].name = argv[i + 1];
      candidate[i].vote = 0;
    }
    
    int voters = get_int("Number of voters: "), i;
    
    for (i = 0; i < voters; i++)
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
        if (strcmp(candidate[i].name, name) == 0)
        {
            candidate[i].vote++;
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
        if (candidate[i].vote > w )
        {
            w = candidate[i].vote;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidate[i].vote == w)
        {
            printf("%s \n", candidate[i].name);
        }
    }
    return;
}