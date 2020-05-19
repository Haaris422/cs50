#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    float letters = 0, words = 0, sentences = 0;
    string Text = get_string("Text: ");
    int i, n = strlen(Text);
    if (isalnum(Text[0]))
    {
        words = 1;
    }
    for (i = 0; i < n; i++)
    {
        if (isalpha(Text[i]))
        {
            letters++;
        }
        if (isspace(Text[i]))
        {
            words++;
        }
        if (Text[i] == '!' || Text[i] == '?' || Text[i] == '.')
        {
            sentences++;
        }
    }
    int j = round(letters);
    int k = round(words);
    int l = round(sentences);
    printf("Letters present: %d\n", j);
    printf("Words present: %d\n", k);
    printf("Sentences present: %d\n", l);
    float L = (letters*100)/words;
    float S = (sentences*100)/words;
    printf("%f\n", L);
    printf("%f\n", S);
    float index = 0.0588*L - 0.296*S -15.8;
    int I = round(index);
    printf("%d\n", I);
    if (I < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %d\n", I);
    }
    if (I >= 16)
    {
        printf("Grade 16+\n");
    }
    
}






