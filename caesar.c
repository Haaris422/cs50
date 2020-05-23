#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
bool check_key(string a);//To check if the input key is valid.

int main(int argc, string argv[])
{
    if (argc != 2 || !check_key(argv[1])) //If input is invalid, ends the program.
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int k = atoi(argv[1]); //To change string to int.
        string s = get_string("plaintext: "); //To ask for text that is to be encrypted.
        int n = strlen(s); //Length of the user entered text (which is an array).
        printf("ciphertext: ");
        for (int i = 0; i < n; i++) //To check each element of the entered string for alphanumeric values.
        {
            if (isalpha(s[i])) //If the element is an alphabet it is executed.
            {
                if (isupper(s[i])) //If it is uppercase.
                {
                    printf("%c", (((s[i] - 'A') + k) % 26) + 'A'); //Rotates the alphabet while preserving its case.
                }
                else if (islower(s[i])) //If it is in lowercase.
                {
                    printf("%c", (((s[i] - 'a') + k) % 26) + 'a'); //Rotates the alphabet while preserving its case.
                }
            }   
            else //If its a numeric/other value (eg -> 1,2,12,;,,,. etc).
            {
                printf("%c", s[i]); //Prints it as it is.
            }
        }
        printf("\n");
        return 0; //Returns true. 
    }
}


bool check_key(string a) //This whole loop checks if each character of argv[1] is an alphabet or not and if its not fully numeric(eg 20x), it ends the program.
{
    for (int i = 0, n = strlen(a); i < n; i++)
    
        if (!isdigit(a[i]))
        
        {
            return false;
        }
    return true;
    
}