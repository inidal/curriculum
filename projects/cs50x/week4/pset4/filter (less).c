#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            int average = round((blue + green + red) / 3);

            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            // sepiaRed
            if (sepiaRed < 255)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }

            // sepiaGreen
            if (sepiaGreen < 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            // sepiaBlue
            if (sepiaBlue < 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Actual box rows and columns
            int act_row[] = {i - 1, i, i + 1};
            int act_col[] = {j - 1, j, j + 1};

            // Reset variables
            int counter = 0;
            float sred, sgreen, sblue;
            sred = sgreen = sblue = 0;

            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    // Simply put: (0 <= **actual_row** < height) && (0 <= **actual_column** < width)
                    if (act_row[k] >= 0 && act_row[k] < height && act_col[l] >= 0 && act_col[l] < width)
                    {
                        RGBTRIPLE aim = image[act_row[k]][act_col[l]];

                        // Sum operation
                        sred += aim.rgbtRed;
                        sgreen += aim.rgbtGreen;
                        sblue += aim.rgbtBlue;

                        counter++;
                    }
                }
            }
            // Dividing the sum of each color and assigning it to each RGB in tmp
            tmp[i][j].rgbtRed = round(sred / counter);
            tmp[i][j].rgbtGreen = round(sgreen / counter);
            tmp[i][j].rgbtBlue = round(sblue / counter);
        }
    }

    // Finally free.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }
}
