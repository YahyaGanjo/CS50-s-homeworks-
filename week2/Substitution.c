#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])

{
    if(argc == 1)
    {
        printf("usage : ./substitution KEY\n");
        return 1;
    }
    if(argc == 2)
    {
        string y = argv[1];
        if (strlen(y) != 26)
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        else
        {
            int a = 0;
            for (int i = 0 ; i < 26 ; i++)
            {
                if ((y[i] > 64 && y[i] < 91) || (y[i] > 96 && y[i] < 123))
                {
                   a = a + 1;
                }
            }
            if (a < 26)
            {
                printf("Key must only contain alphabetic charecters.\n");
                return 1;
            }
            int b = 0;
            for (int i = 0 ; i < 26 ; i++)
            {
                for (int j = 0 ; j < 26 ; j++)
                {
                    if (y[i] == y[j] || (y[i] == y[j] - 32) || (y[i] == y[j] + 32))
                    {
                        b = b + 1;
                    }
                }
            }
            if (a == 26 && b > 26)
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
            if (a == 26 && b == 26)
            {
                string plain = get_string("plaintext: ");
                printf("ciphertext: ");
                for (int i = 0 ; i < strlen(plain) ; i++)
                {
                    int t = plain[i] - 65;
                    int u = plain[i] - 97;
                    if ((plain[i] > 64) && (plain[i] < 91))
                    {
                        if ((y[t] > 64) && (y[t] < 91))
                        {
                            printf("%c", y[t]);
                        }
                        else
                        {
                            printf("%c", toupper(y[t]));
                        }
                    }
                    else if ((plain[i] > 96) && (plain[i] < 123))
                    {
                        if ((y[u] > 96) && (y[u] < 123))
                        {
                            printf("%c", y[u]);
                        }
                        else
                        {
                            printf("%c", tolower(y[u]));
                        }
                    }
                    else
                    {
                        printf("%c", plain[i]);
                    }
                }
                printf("\n");
                return 0;
            }
        }
    }
}
