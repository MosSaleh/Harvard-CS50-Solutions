#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // TODO: Prompt for start size

    int startsize;
    do
    {
        startsize = get_int("What is the starting size of the population? ");
    } while (startsize < 9);

    // TODO: Prompt for end size

    int endsize;
    do
    {
        endsize = get_int("What is the desired endsize? ");
    } while (endsize < startsize);

    // TODO: Calculate number of years until we reach threshold
    float size = startsize;
    int years = 0;

    do
    {
        years++;
        size = size + (size / 3);
        size = size - (size / 4);
    } while (size < endsize);
    // TODO: Print number of years

    printf("Total years = %i", years);
}
