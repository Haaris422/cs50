#include<cs50.h>

#include<stdio.h>

int main(void)
{
    int n, h, w, i, j;
    //n is the numeric value entered by the user.
    //h is height & w is width.
    //i is the initial variable which is used to give the starting value to the pattern's height(h) & width(w).
    //j is used here to represent the number of # in each row of the 2nd pyramid.
    do
    {
        n = get_int("Enter the desired height of the 2 pyramids (b/w 0 & 8) -> ");
    }
    while (n <= 0 || n > 8);
    //It ensures that the program would be executed only when a no. b/w 0 & 8 is entered and if not it would ask them again until the acceptable value is entered.
    for (i = 1; i <= n; i++)
    {
       for (h = i; h < n; h++) //It manages the no. of rows in both of the pyramids.
        {                     
           printf(" ");       //In this for loop, blank spaces are printed horizontally.
        }
       for (w = 1; w <= i; w++)//It manages the no. of columns in the 1st pyramid(i.e. it prints the #s).
        {                       
           printf("#");
        }
        printf("  ");          //It provides space b/w pyramid 1 &2.
       for (j = 1; j < w; j++) //This loop manages the no. of columns in the 2nd pyramid.
        {                      
           printf("#");       //in every row of pyramid 2, it prints the exact same no. of # as there are in corresponding pyramid 1's row.
        }
       printf("\n");          //It moves the program to the next line.
    }
}