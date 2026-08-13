#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
string text = get_string("Text: ");
int letters = 0;
int words = 0;
int sentences = 0;
for (int i = 0, n = strlen(text); i < n; i++)
{
    char c = text[i];
    if (isalpha(c))
    {
        letters++;
    }
    else if (c == ' ')
    {
        words++;
    }
    else if (c == '.' || c =='!' || c =='?')
    {
        sentences++;
    }
}
words++;

float L = (letters / (float) words) * 100;
float S = (sentences / (float) words) * 100;
int index = round(0.0588 * L - 0.296 * S - 15.8);

if (index < 1)
{
    printf("Before Grade 1\n");
}
else if (index >= 16)
{
    printf("Grade 16+\n");
}
else
{
    printf("Grade %i\n", index);
}
return 0;
}
