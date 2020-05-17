#include<cs50.h>

#include<stdio.h>

int main (void)
{
    int n,h,w,i,j;
    //h is height & w is width.
    
    do
    {
        n=get_int("Enter any no. b/w 0 & 8 -> ");
    }
    while(n<=0 || n>8);
    
    for(i=1;i<=n;i++)
    {
       for(h=i;h<n;h++)
       {
           printf(" ");
       }
       for(w=1;w<=i;w++)
       {
           printf("#");
       }
       printf("  ");
       for(j=1;j<w;j++)
       {
        printf("#");   
       }
       printf("\n");
    }
}