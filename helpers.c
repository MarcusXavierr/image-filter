#include "helpers.h"
#include <math.h>
#include <stdio.h>
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
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE row[width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0, index = width; j < width; j++,index--)
        {
            row[index] = image[i][j];
        }
        for(int k = 0; k < width; k++)
        {
            image[i][k] = row[k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
