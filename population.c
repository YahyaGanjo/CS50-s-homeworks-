# include<stdio.h>
# include<cs50.h>

void calculate ( int y, int x);


int main (void)
{
    int x;
    do
    {
    x = get_int("Start size: ");
    }
    while (x < 9);
    
        int y;
    do
    {
    y = get_int("End size: ");
    }
    while (y < x);
    
    calculate ( y , x );
}

void calculate ( int y, int x)
{
    int Years = 0;
    if ( x != y )
    {
            do
        {
            int gain = x / 3 ;
            int lose = x / 4 ;
            x = x + gain - lose ;
            Years ++;
        }
            while ( x < y );
    }
    printf ("Years: %i\n", Years);
}