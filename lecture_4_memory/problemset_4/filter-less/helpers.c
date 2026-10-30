#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = (int) round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
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
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            int originalRed = image[i][j].rgbtRed;
            int sepiaGreen = (int) round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[i][j].rgbtGreen = sepiaGreen;

            int sepiaBlue = (int) round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;

            int sepiaRed = (int) round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
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
