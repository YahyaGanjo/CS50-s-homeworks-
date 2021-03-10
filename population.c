# include<stdio.h>
# include<cs50.h>

void calculate ( float y, float x);


int main (void)
{
    int x;
    do
    {
    x = get_int("Start size: ");
    }
    while (x <= 9);
    
        int y;
    do
    {
    y = get_int("End size: ");
    }
    while (y <= x);
    
    calculate ( y , x );
}

void calculate ( float y, float x)
{
    float gain = x / 3 ;
    float lose = x / 4 ;
    float GrowthPerYear = gain - lose ; 
    float ActualGrowth = y - x ;
    float Years = ActualGrowth / GrowthPerYear ;
    printf ("Years: %f\n", Years);
}