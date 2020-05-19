#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    float letters = 0, words = 0, sentences = 0;
    string Text = get_string("Text: "); //This records the user input.
    int i, n = strlen(Text); //This is to create an array from the line of text entered by the user.
    if (isalnum(Text[0])) //This is to set an initial value of 1 word for any line of text we want to evaluate.
    {
        words = 1;
    }
    for (i = 0; i < n; i++)
    {
        if (isalpha(Text[i])) //To calculate the no. of letters.
        {
            letters++;
        }
        if (isspace(Text[i])) //To calculate the no. of words.
        {
            words++;
        }
        if (Text[i] == '!' || Text[i] == '?' || Text[i] == '.') //To calculate the no. of sentences.
        {
            sentences++;
        }
    }
    int j = round(letters);
    int k = round(words);
    int l = round(sentences);
    //i,j & k are used to convert float to int.
    printf("Letters present: %d\n", j);
    printf("Words present: %d\n", k);
    printf("Sentences present: %d\n", l);
    float L = (letters * 100) / words; //Letters per 100 words.
    float S = (sentences * 100) / words; //Sentences per 100 words.
    printf("L = %f\n", L);
    printf("S = %f\n", S);
    float index = 0.0588 * L - 0.296 * S - 15.8; //Coleman-Liau formula. 
    int I = round(index); //Used to convert float into int.
    if (I < 1) //Used to print grade if I<1.
    {
        printf("Before Grade 1\n");
    }
    else //Used to print grade if I is b/w 1 & 16.
    {
        printf("Grade %d\n", I);
    }
    if (I >= 16) //Used to print grade if I is >= 16
    {
        printf("Grade 16+\n");
    }
    
}






