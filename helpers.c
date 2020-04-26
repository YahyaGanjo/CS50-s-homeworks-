#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int n = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            int k = round(n / 3.00);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = k;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int green = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int blue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            if (red > 255)
            {
                image[i][j].rgbtRed = 255;
            }else
            {
                image[i][j].rgbtRed = red;
            }
            if (green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }else
            {
               image[i][j].rgbtGreen = green; 
            }
            if (blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }else
            {
                image[i][j].rgbtBlue = blue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int n = width - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= n / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][n - j];
            image[i][n - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = 0;
           float n = 0.00;
           int red = 0;
           int green = 0;
           int blue = 0;
           for (int x = i - 1; x < i + 2; x++)
           {
               for (int y = j - 1; y < j + 2; y++)
               {
                   if ((x >= 0 && x < height) && (y >= 0 && y < width))
                   {
                       n += 1.00;
                       red += image[x][y].rgbtRed;
                       green += image[x][y].rgbtGreen;
                       blue += image[x][y].rgbtBlue;
                   }
               }
           }
           image[i][j].rgbtRed = round(red / n);
           image[i][j].rgbtGreen = round(green / n);
           image[i][j].rgbtBlue = round(blue / n);
        }
    }
    return;
}

