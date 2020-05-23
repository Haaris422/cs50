#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
bool check_key(string a);

int main (int argc, string argv[])
{
  if (argc != 2 || !check_key(argv[1]))
  {
      printf ("Usage: ./caesar key\n");
      return 1;
  }
  else
  {
  int k = atoi(argv[1]);
  string s = get_string("plaintext: ");
  int n = strlen(s);
  printf("ciphertext: ");
  for (int i = 0; i <n; i++)
  {
       if (isalpha(s[i]))
       {
           if (isupper(s[i]))
           {
                printf("%c", (((s[i] - 'A') + k) %26) + 'A');
           }
           else if (islower(s[i]))
           {
                char c = s[i] - 'a';
                printf ("%c", (c + k)%26 + 'a');
           }
       }   
       else
       {
            printf ("%c", s[i]);
       }
  }
  printf("\n");
  return 0;
  }
}


bool check_key(string a)
{
    for (int i = 0, n = strlen(a); i < n; i++)
    
        if(!isdigit(a[i]))
        
            return false;
        
        return true;
    
}