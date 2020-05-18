#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
{
    float change;
    
    do
    {
        change=get_float("Enter the change owed to the customer: ");
    }
    while(change < 0);
    
    int cents = round(change*100);
    int coins = 0;
    
    int c[] = {25, 10, 5, 1};
    int size = 4;
    
    for(int i = 0; i < size; i++)
    {
        coins += cents/c[i];
        cents %= c[i];
    }
    printf("Least no. of coins to be dispensed -> %d\n", coins);
}