#include <cs50.h>

#include <stdio.h>

int main (void)

{
    long n;
    do
    {
        n = get_long ("Number :");
    }
    while (n <= 0);
    if (n > 0)
    {
        int x = (n % 100 / 10) * 2;
        int c = (n % 10000 / 1000) * 2;
        int v = (n % 1000000 / 100000) * 2;
        int b = (n % 100000000 / 10000000) * 2;
        int m = (n % 10000000000 / 1000000000) * 2;
        int a = (n % 1000000000000 / 100000000000) * 2;
        int s = (n % 100000000000000 / 10000000000000) * 2;
        int d = (n % 10000000000000000 / 1000000000000000) * 2;
        int xx = (x / 10) + (x % 10);
        int cc = (c / 10) + (c % 10);
        int vv = (v / 10) + (v % 10);
        int bb = (b / 10) + (b % 10);
        int mm = (m / 10) + (m % 10);
        int aa = (a / 10) + (a % 10);
        int ss = (s / 10) + (s % 10);
        int dd = (d / 10) + (d % 10);
        int f = xx + cc + vv + bb + mm + aa + ss + dd;
        int g = n % 10;
        int h = n % 1000 / 100;
        int j = n % 100000 / 10000;
        int k = n % 10000000 / 1000000;
        int l = n % 1000000000 / 100000000;
        int q = n % 100000000000 / 10000000000;
        int w = n % 10000000000000 / 1000000000000;
        int e = n % 1000000000000000 / 100000000000000;
        int r = f + g + h + j + k + l + q + w + e;
        if ( r % 10 == 0)
        {
            if ((n > 4000000000000 && n < 4999999999999) || (n > 4000000000000000 && n < 4999999999999999))
            {
                printf ("VISA\n");
            }
            if (n > 5100000000000000 && n < 5599999999999999)
            {
                printf ("MASTERCARD\n");
            }
            if ((n > 340000000000000 && n < 349999999999999) || (n > 370000000000000 && n < 379999999999999))
            {
                printf ("AMEX\n");
            }    
        }
        else
        {
            printf ("INVALID\n");
        }
    }
}
