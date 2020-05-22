#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[])
{
   if ( argc == 2 || isdigit(*argv[1]))
   {
       int k = atoi(argv[1]), i; 
       string s = get_string("Plaintext: ");
       int n = strlen(s);
       printf("\nCipher: ");
       for (i = 0; i < n; i++)
       {
           if (s[i] >= 'a' || s[i] <= 'z')
           {
               printf ("%c", (((s[i] - 'a') + k) % 26) + 'a');
           }
           else if (s[i] >= 'A' || s[i] <= 'Z')
           {
                printf ("%c", (((s[i] - 'A') + k) % 26) + 'A');
           }
           else
           {
               printf ("%c", s[i]);
           }
       }
       printf("\n");
       return 0;
   }
   else 
   {
       printf ("Usage: ./caesar key");
       return 1;
   }
}