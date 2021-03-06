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
    int red;
    int green;
    int blue;
    int result;
    RGBTRIPLE pixel;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            pixel = image[i][j];
            red = pixel.rgbtRed;
            green = pixel.rgbtGreen;
            blue = pixel.rgbtBlue;

            result = floor(//Red
                (0.393 * red) + (0.769 * green) + (0.189 * blue)
            ); 

            image[i][j].rgbtRed = result > 255 ? 255:result;
            
            result = floor(//Green
                (0.349 * red) + (0.686 * green) + (0.168 * blue)
            );

            image[i][j].rgbtGreen = result > 255 ? 255:result;
            
            result = floor(//Blue
                (0.272 * red) + (0.534 * green) + (0.131 * blue)
            );

            image[i][j].rgbtBlue = result > 255 ? 255:result;
            
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
            row[index - 1] = image[i][j];
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
    RGBTRIPLE totalimage[height][width];
    int average;
    RGBTRIPLE pixel;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixel = image[i][j];
            if (i == 0) //top
            {
                if (j == 0) //left
                {
                    average = ( //Red
                    image[i][j + 1].rgbtRed + 
                    image[i + 1][j].rgbtRed + 
                    image[i + 1][j + 1].rgbtRed + 
                    pixel.rgbtRed)/4;
                    totalimage[i][j].rgbtRed = average;

                    average = ( //Green
                    image[i][j + 1].rgbtGreen + 
                    image[i + 1][j].rgbtGreen + 
                    image[i + 1][j + 1].rgbtGreen + 
                    pixel.rgbtGreen)/4;
                    totalimage[i][j].rgbtGreen = average;

                    average = ( //Blue
                    image[i][j + 1].rgbtBlue + 
                    image[i + 1][j].rgbtBlue + 
                    image[i + 1][j + 1].rgbtBlue + 
                    pixel.rgbtBlue)/4;
                    totalimage[i][j].rgbtBlue = average;
                }
                else if(j == width - 1)//right
                {
                    average = ( //Red
                    image[i][j - 1].rgbtRed + 
                    image[i + 1][j].rgbtRed + 
                    image[i + 1][j - 1].rgbtRed + 
                    pixel.rgbtRed)/4;
                    totalimage[i][j].rgbtRed = average;

                    average = ( //Green
                    image[i][j - 1].rgbtGreen + 
                    image[i + 1][j].rgbtGreen + 
                    image[i + 1][j - 1].rgbtGreen + 
                    pixel.rgbtGreen)/4;
                    totalimage[i][j].rgbtGreen = average;

                    average = ( //Blue
                    image[i][j - 1].rgbtBlue + 
                    image[i + 1][j].rgbtBlue + 
                    image[i + 1][j - 1].rgbtBlue + 
                    pixel.rgbtBlue)/4;
                    totalimage[i][j].rgbtBlue = average;
                }
                else //between
                {
                    average = ( // Red
                    image[i][j - 1].rgbtRed + 
                    image[i + 1][j - 1].rgbtRed + 
                    image[i + 1][j].rgbtRed + 
                    image[i + 1][j + 1].rgbtRed + 
                    image[i][j + 1].rgbtRed + 
                    pixel.rgbtRed)/6;
                    totalimage[i][j].rgbtRed = average;

                    average = ( // Green
                    image[i][j - 1].rgbtGreen + 
                    image[i + 1][j - 1].rgbtGreen + 
                    image[i + 1][j].rgbtGreen + 
                    image[i + 1][j + 1].rgbtGreen + 
                    image[i][j + 1].rgbtGreen + 
                    pixel.rgbtGreen)/6;
                    totalimage[i][j].rgbtGreen = average;

                    average = ( // Blue
                    image[i][j - 1].rgbtBlue + 
                    image[i + 1][j - 1].rgbtBlue + 
                    image[i + 1][j].rgbtBlue + 
                    image[i + 1][j + 1].rgbtBlue + 
                    image[i][j + 1].rgbtBlue + 
                    pixel.rgbtBlue)/6;
                    totalimage[i][j].rgbtBlue = average;
                }
                
            }
            else if (i == height -1) //bottom
            {
                if (j == 0) //left
                {
                    average = ( //Red
                    image[i][j + 1].rgbtRed + 
                    image[i - 1][j].rgbtRed + 
                    image[i - 1][j + 1].rgbtRed + 
                    pixel.rgbtRed)/4;
                    totalimage[i][j].rgbtRed = average;

                    average = ( //Green
                    image[i][j + 1].rgbtGreen + 
                    image[i - 1][j].rgbtGreen + 
                    image[i - 1][j + 1].rgbtGreen + 
                    pixel.rgbtGreen)/4;
                    totalimage[i][j].rgbtGreen = average;

                    average = ( //Blue
                    image[i][j + 1].rgbtBlue + 
                    image[i - 1][j].rgbtBlue + 
                    image[i - 1][j + 1].rgbtBlue + 
                    pixel.rgbtBlue)/4;
                    totalimage[i][j].rgbtBlue = average;
                }
                else if(j == width - 1) //right
                {
                    average = ( //Red
                    image[i][j - 1].rgbtRed + 
                    image[i - 1][j].rgbtRed + 
                    image[i - 1][j - 1].rgbtRed + 
                    pixel.rgbtRed)/4;
                    totalimage[i][j].rgbtRed = average;

                    average = ( //Green
                    image[i][j - 1].rgbtGreen + 
                    image[i - 1][j].rgbtGreen + 
                    image[i - 1][j - 1].rgbtGreen + 
                    pixel.rgbtGreen)/4;
                    totalimage[i][j].rgbtGreen = average;

                    average = ( //Blue
                    image[i][j - 1].rgbtBlue + 
                    image[i - 1][j].rgbtBlue + 
                    image[i - 1][j - 1].rgbtBlue + 
                    pixel.rgbtBlue)/4;
                    totalimage[i][j].rgbtBlue = average;
                }
                else //between
                {
                    average = ( //Red
                    image[i][j - 1].rgbtRed + 
                    image[i - 1][j - 1].rgbtRed + 
                    image[i - 1][j].rgbtRed + 
                    image[i - 1][j + 1].rgbtRed + 
                    image[i][j + 1].rgbtRed + 
                    pixel.rgbtRed)/6;
                    totalimage[i][j].rgbtRed = average;

                    average = ( //Green
                    image[i][j - 1].rgbtGreen + 
                    image[i - 1][j - 1].rgbtGreen + 
                    image[i - 1][j].rgbtGreen + 
                    image[i - 1][j + 1].rgbtGreen + 
                    image[i][j + 1].rgbtGreen + 
                    pixel.rgbtGreen)/6;
                    totalimage[i][j].rgbtGreen = average;

                    average = ( //Blue
                    image[i][j - 1].rgbtBlue + 
                    image[i - 1][j - 1].rgbtBlue + 
                    image[i - 1][j].rgbtBlue + 
                    image[i - 1][j + 1].rgbtBlue + 
                    image[i][j + 1].rgbtBlue + 
                    pixel.rgbtBlue)/6;
                    totalimage[i][j].rgbtBlue = average;
                }
            }
            else //between
            {
                if (j == 0) //left
                {
                    average = ( //Red
                    image[i - 1][j].rgbtRed + 
                    image[i - 1][j + 1].rgbtRed + 
                    image[i][j + 1].rgbtRed + 
                    image[i + 1][j + 1].rgbtRed + 
                    image[i + 1][j].rgbtRed + 
                    pixel.rgbtRed)/6;
                    totalimage[i][j].rgbtRed = average;

                    average = ( //Green
                    image[i - 1][j].rgbtGreen + 
                    image[i - 1][j + 1].rgbtGreen + 
                    image[i][j + 1].rgbtGreen + 
                    image[i + 1][j + 1].rgbtGreen + 
                    image[i + 1][j].rgbtGreen + 
                    pixel.rgbtGreen)/6;
                    totalimage[i][j].rgbtGreen = average;

                    average = ( //Blue
                    image[i - 1][j].rgbtBlue + 
                    image[i - 1][j + 1].rgbtBlue + 
                    image[i][j + 1].rgbtBlue + 
                    image[i + 1][j + 1].rgbtBlue + 
                    image[i + 1][j].rgbtBlue + 
                    pixel.rgbtBlue)/6;
                    totalimage[i][j].rgbtBlue = average;
                }
                else if(j == width - 1) //right
                {
                    average = ( //Red
                    image[i - 1][j].rgbtRed + 
                    image[i - 1][j - 1].rgbtRed + 
                    image[i][j - 1].rgbtRed + 
                    image[i + 1][j -1].rgbtRed + 
                    image[i + 1][j].rgbtRed + 
                    pixel.rgbtRed)/6;
                    totalimage[i][j].rgbtRed = average;

                    average = ( //Green
                    image[i - 1][j].rgbtGreen + 
                    image[i - 1][j - 1].rgbtGreen + 
                    image[i][j - 1].rgbtGreen + 
                    image[i + 1][j -1].rgbtGreen + 
                    image[i + 1][j].rgbtGreen + 
                    pixel.rgbtGreen)/6;
                    totalimage[i][j].rgbtGreen = average;

                    average = ( //Blue
                    image[i - 1][j].rgbtBlue + 
                    image[i - 1][j - 1].rgbtBlue + 
                    image[i][j - 1].rgbtBlue + 
                    image[i + 1][j -1].rgbtBlue + 
                    image[i + 1][j].rgbtBlue + 
                    pixel.rgbtBlue)/6;
                    totalimage[i][j].rgbtBlue = average;
                }
                else //between
                {
                    average = ( //Red
                    image[i - 1][j].rgbtRed + 
                    image[i - 1][j + 1].rgbtRed + 
                    image[i][j + 1].rgbtRed + 
                    image[i + 1][j + 1].rgbtRed + 
                    image[i + 1][j].rgbtRed + 
                    image[i + 1][j - 1].rgbtRed + 
                    image[i][j - 1].rgbtRed + 
                    image[i - 1][j - 1].rgbtRed + 
                    pixel.rgbtRed)/9;
                    totalimage[i][j].rgbtRed = average;

                    average = ( //Green
                    image[i - 1][j].rgbtGreen + 
                    image[i - 1][j + 1].rgbtGreen + 
                    image[i][j + 1].rgbtGreen + 
                    image[i + 1][j + 1].rgbtGreen + 
                    image[i + 1][j].rgbtGreen + 
                    image[i + 1][j - 1].rgbtGreen + 
                    image[i][j - 1].rgbtGreen + 
                    image[i - 1][j - 1].rgbtGreen + 
                    pixel.rgbtGreen)/9;
                    totalimage[i][j].rgbtGreen = average;

                    average = ( //Blue
                    image[i - 1][j].rgbtBlue + 
                    image[i - 1][j + 1].rgbtBlue + 
                    image[i][j + 1].rgbtBlue + 
                    image[i + 1][j + 1].rgbtBlue + 
                    image[i + 1][j].rgbtBlue + 
                    image[i + 1][j - 1].rgbtBlue + 
                    image[i][j - 1].rgbtBlue + 
                    image[i - 1][j - 1].rgbtBlue + 
                    pixel.rgbtBlue)/9;
                    totalimage[i][j].rgbtBlue = average;
                }
                
            }
            
        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int z = 0; z < width; z++)
        {
            image[x][z] = totalimage[x][z];
        }
    }
    return;
}
