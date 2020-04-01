#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("height :");
    }
    while (n <1 || n > 8);
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j <= i ; j++)
        {
            for (int x = 1 ; x < n - i && x > j ; x++)
            {
                printf(" ");
            }
            
            printf("#");
        }
        printf("\n");
    }

}    
