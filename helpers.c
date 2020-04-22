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
          sepiaformula(image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed);  
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
    int sepiaRed = round((0.393 * z) + (0.769 * y) + (0.189 * x));
    int sepiaGreen = round((0.349 * z) + (0.686 * y) + (0.168 * x));
    int sepiaBlue = round((0.272 * z) + (0.534 * y) + (0.131 * x));
    z = sepiaRed;
    y = sepiaGreen;
    x = sepiaBlue;
}
