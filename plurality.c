#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9

typedef struct
{
    char* name;
    int vote;
}
c; 

c candidate[MAX];

int candidate_count;

bool vote(char name[]);

void print_winner (void);

int main (int argc, char *argv[])

{

    if (argc < 2)
    {
        printf("Usage: ./plurality[candidate...]\n");
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
    
    int voter_count, i;
    printf("Number of voters: ");
    scanf("%d", &voter_count);
    
    for (i = 0; i < voter_count; i++)
    {
        char name[10];
        printf("Vote: ");
        scanf("%s", name);
        if (!vote(name))
        {
            printf("Invalid vote\n");
        }
    }
    
    print_winner();
}    



bool vote(char name[])
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