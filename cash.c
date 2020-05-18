#include<stdio.h>

#include<cs50.h>

#include<math.h> //math.h is used to allow the use of round() in this program.

int main(void)
{
    float change; //Here float is used as we will be dealing with decimals. 
    
    do
    {
        change = get_float("Enter the change owed to the customer: ");
    }
    while (change < 0); //This prevents the user from entering a negative value.
    
    int cents = round(change * 100); //It rounds our float value into an int value.
    int coins = 0; //This is the variable used to display the no. of coins required.
    
    int c[] = {25, 10, 5, 1}; //An array is used here to simplify the syntax(4 while loops could also be used but they would be a little too hard to manage.).
    int size = 4;
    
    for (int i = 0; i < size; i++) //This loop devides the input value by each value in the array and then finds the mod of that value till it becomes 0.
    {
        coins += cents / c[i];
        cents %= c[i];
    }
    printf("Least no. of coins to be dispensed -> %d\n", coins); //It prints the final result.
}