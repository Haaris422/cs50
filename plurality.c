#include <stdio.h>
#include <string.h>
#include <cs50.h>

#define MAX 9 //Sets max limit as 9.

typedef struct
{
    string name;
    int votes;
}
candidate; //Makes a structure to contain 2 values (name & votes).

candidate candidates[MAX]; //Array

int candidate_count; //Counts no. of elements.

bool vote(string name); //Counts votes.
void print_winner(void); //Prints winner.

int main(int argc, string argv[])

{
    if (argc < 2)
    {
        printf("Usage: plurality[candidate...]\n");
        return 1;
    } //If no command line argument is entered.
   
    candidate_count = argc - 1;
    
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %d\n", MAX);
        return 2;
    } //If invalid amount of clas have been entered.


    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    } //Copys the cls to the candidates array's name category & sets its votes category to 0. 
    
    int voter_count = get_int("Number of voters: "), i;
    
    for (i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        } //tallys the votes & checks if the input was valid or invalid.
    }
    
    print_winner();
}    



bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0) //Compares the 'Vote' entered by the user to the names present in candidates[].
        {
            candidates[i].votes++;
            return true; //If yes, then it increases their 'votes' by 1.
        }
    }
    return false;
}

void print_winner(void)
{
    int w = 0; //'w' stands for Winner.  
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > w)
        {
            w = candidates[i].votes; //Checks if any candidates votes have increased more than w and then sets the current max votes as w's value.
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == w)
        {
            printf("%s\n", candidates[i].name); //Prints the candidate(s) with 'w' amount of votes.
        }
    }
    return;
}