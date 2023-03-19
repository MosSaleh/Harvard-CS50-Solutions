#include <cs50.h>
#include <stdio.h>

// program to recreate mario blocks using hashtags
int main(void)

{
    int n;
    do
    {
        n = get_int("Height: ");
    } while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        // make spaces for first blocks

        for (int c = 0; c < n - (i + 1); c++)
        {
            printf(" ");
        }

        // print first set of blocks

        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("  ");

        // print second set of blocks

        for (int z = 0; z < i + 1; z++)
        {
            printf("#");
        }

        printf("\n");
    }
}
