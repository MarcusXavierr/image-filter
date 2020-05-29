#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
     int average;
    RGBTRIPLE pixel;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            pixel = image[i][j];
            average = floor((pixel.rgbtBlue + pixel.rgbtRed + pixel.rgbtGreen)/3);
            pixel.rgbtBlue = average;
            pixel.rgbtRed = average;
            pixel.rgbtGreen = average;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
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
