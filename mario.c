#include<cs50.h>

#include<stdio.h>

int main(void)
{
  int n, height, width, i;
  //n is the value entered by the user.
  //i is initial variable needed to start the pattern by providing a starting value.
  do
  {
     n = get_int("Enter any number between 0 & 8: ");
  }
  while (n > 8 || n <= 0);//This is to limit the acceptable value to be b/w 0 & 8.
  for (i = 1; i <= n; i++)
   {
        for (height = i; height < n; height++)
        {
           printf(" ");
        }
        for (width = 1; width <= i; width++)
        {
           printf("#");
        }
        printf("\n");
   }
  
}  
    