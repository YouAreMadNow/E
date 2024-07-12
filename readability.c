#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    //get input
    string text = get_string("Text: ");

    //count letters, words, sentences
    int letters = 0;
    int sentences = 0;
    int words = 1;
    for (int n = 0; text[n] != '\0'; n++)
    {
        char c = toupper(text[n]);
        if (c >= 'A' && c <= 'Z') {
            letters++;
        }
        if (c == ' ') {
            words++;
        }
        if (c == '.' || c == '!' || c == '?') {
            sentences++;
        }
    }

    //calculate Grade
    double L = (letters * 100.0 / words);
    double S = (sentences * 100.0 / words);
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade < 1) {
        printf("Before Grade 1\n");
    }
    else if (grade > 16) {
        printf("Grade 16+\n");
    }
    else {
        printf("Grade %i\n", grade);
    }
}