#include <cs50.h>
#include <stdio.h>
#include<ctype.h>
#include <math.h>

int letter = 0;
int word = 0;
int sentence = 0;
double L = 0;
double S = 0;
int quote = 0; //tells the programm to not count thoughts as sentences

void letters(string a);
void index(void);

int main(void)
{
    string text = get_string("Text: ");
    for (int n = 0; text[n] != '\0'; n++)
    {
        text[n] = toupper(text[n]);
    }
    letters(text);
    //printf("letter %i\n  word %i\n  sentence %i\n", letter, word, sentence);
    index();
}

void letters(string a)
{
    for (int n = 0; a[n] != '\0';)
    {
        //printf("%i ", sentence);
        if (a[n] == 34)
        {
            if (quote == 0)
            {
                quote = 1;
            }
            else
            {
                quote = 0;
            }
        }
        if (n == 40)
        {
            printf(" ");
        }
        if (a[n] <= 90 && a[n] >= 65)
        {
            letter++;
        }
        else if (a[n] == ' ')
        {
            word++;
        }
        else if (a[n] == 46 || a[n] == 33 || a[n] == 63 || a[n] == 44)
        {
            if (quote == 0)
            {
                sentence++;
            }
        }
        if (a[n+1] == '\0')
        {
            word++;
        }
        n++;
    }
}

void index(void)
{
    L = (letter * 100.00000 / word);
    //printf(" L %f ", L);
    S = (sentence * 100.00000 / word);
    //printf(" S %f  %i", S, word);
    double index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("  %f  ", index);
    index = round(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",(int) index);
    }
}
