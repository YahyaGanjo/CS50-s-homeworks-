#include "helpers.h"
#include <math.h>

void sepiaformula (int x, int y, int z);

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
            int x = image[i][j].rgbtBlue;
            int y = image[i][j].rgbtGreen;
            int z = image[i][j].rgbtRed;
            sepiaformula(x, y, z);
            image[i][j].rgbtBlue = x;
            image[i][j].rgbtGreen = y;
            image[i][j].rgbtRed = z;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

void sepiaformula (int x, int y, int z)
{
    int red = round((0.393 * z) + (0.769 * y) + (0.189 * x));
    int green = round((0.349 * z) + (0.686 * y) + (0.168 * x));
    int blue = round((0.272 * z) + (0.534 * y) + (0.131 * x));
    if (red > 255)
    {
        z = 255;
    }
    if (green > 255)
    {
        y = 255;
    }
    if (blue > 255)
    {
        x = 255;
    }
    z = red;
    y = green;
    x = blue;
}
