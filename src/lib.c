#include "lib.h"

void PrintIntro()
{
    printf("----------------------------------\n");
    printf("---------- GAME OF LIFE ----------\n");
    printf("----------------------------------\n");
}

void waitFor(unsigned int secs)
{
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime)
    {
    }
}

void PrintGrid(char **grid, int gridWidth)
{
    for (int y = 0; y < gridWidth; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            printf("%c ", grid[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

void PopulateCells(char **grid, int gridWidth, int rate)
{
    srand(time(NULL));
    int randomNumber = 0;
    for (int y = 0; y < gridWidth; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            randomNumber = (rand() % 101);
            grid[y][x] = (randomNumber <= rate) ? '0' : '-';
        }
    }
}

void NewGeneration(char **grid, int gridWidth)
{
    // ( y  x) ( y x) (y x)
    // ( 1 -1) ( 1 0) ( 1 1)
    // ( 0 -1) ( 0 0) ( 0 1)
    // (-1 -1) (-1 0) (-1 1)

    typedef struct SPos
    {
        int x;
        int y;
    } Postition;

    Postition neighbors[8] = {
        {1, -1},
        {1, 0},
        {1, 1},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 0},
        {-1, 1}};

    char **copy = CopyGrid(grid, gridWidth);

    for (int y = 0; y < gridWidth; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            int neighborCount = 0;
            for (int i = 0; i < 8; i++)
            {
                int yNeighbor = y + neighbors[i].y;
                int xNeighbor = x + neighbors[i].x;

                if (yNeighbor >= 0 && yNeighbor < gridWidth &&
                    xNeighbor >= 0 && xNeighbor < gridWidth)
                {
                    if (copy[yNeighbor][xNeighbor] == '0')
                    {
                        neighborCount++;
                    }
                }
            }
            if (copy[y][x] == '0')
            {
                if (neighborCount <= 1)
                {
                    grid[y][x] = '-';
                }
                else if (neighborCount >= 4)
                {
                    grid[y][x] = '-';
                }
            }
            else
            {
                if (neighborCount == 3)
                {
                    grid[y][x] = '0';
                }
            }
        }
    }
    FreeGrid(copy, gridWidth);
}

char **CopyGrid(char **grid, int gridWidth)
{
    char **copy = CreateGrid(gridWidth);
    for (int y = 0; y < gridWidth; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            copy[y][x] = grid[y][x];
        }
    }
    return copy;
}

char **CreateGrid(int gridWidth)
{
    char **grid = (char **)malloc(gridWidth * sizeof(char *));
    for (int i = 0; i < gridWidth; i++)
    {
        grid[i] = (char *)malloc(gridWidth * sizeof(char));
    }
    return grid;
}

void FreeGrid(char **grid, int gridWidth)
{
    for (int i = 0; i < gridWidth; i++)
    {
        free(grid[i]);
    }
    free(grid);
}