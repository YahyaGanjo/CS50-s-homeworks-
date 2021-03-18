//CS50 Problem Set 2 (march 2021): Readability
//Author: YahyaGanjo

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include<ctype.h>

int main(void)
{
    string text = get_string("Text: ");
    int letters = 0 ; int words = 1 ; int sentences = 0 ;
    
//count letters, words, sentences
    
    for (int n = 0; n < strlen(text); n++)
    {
        
        if (((text[n] > 64) && (text[n] < 91)) || ((text[n] > 96) && (text[n] < 123)))
        {
            letters++;
        }
        
        if (text[n] == ' ')
        {
            words++;
        }
        
        if ( (text[n] == '.') || (text[n] == '!') || (text[n] == '?') )
        {
            sentences++;
        }
    }
    
    float AveLetters = (( letters * 100 ) / words);
    float AveSentences = ((sentences * 100 ) / words);
    
    int grade = round ( 0.0588 * AveLetters - 0.296 * AveSentences - 15.8 );
    
//    print the grade level
    
    if (grade < 1) 
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}