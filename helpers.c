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
    if (width % 2 == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < (width / 2); j++)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width - j];
                image[i][width - j] = temp;
            }
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

