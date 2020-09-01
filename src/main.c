#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintIntro()
{
    printf("----------------------------------\n");
    printf("---------- GAME OF LIFE ----------\n");
    printf("----------------------------------\n");
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
            grid[y][x] = (randomNumber <= rate) ? '0' : '.';
        }
    }
}

void NewGeneration(int grid, int numberOfCells)
{
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

void ClearGrid(char **grid, int gridWidth)
{
    for (int i = 0; i < gridWidth; i++)
    {
        free(grid[i]);
    }
    free(grid);
}

int main(int argc, char *argv[])
{
    // int gridWidth = 0;

    // PrintIntro();
    // printf("Witch Grid Size do you want ? -> ");
    // scanf("%d", &gridWidth);

    // int numberOfCells = gridWidth * gridWidth;
    // int *grid = (int *)calloc(numberOfCells, sizeof(int));
    // printf("----------------------------------\n");
    // printf("Number of tiles: %d\n", gridWidth * gridWidth);
    // printf("----------------------------------\n");

    int gridWidth = 5;
    char **grid = CreateGrid(gridWidth);

    PopulateCells(grid, gridWidth, 10);

    PrintGrid(grid, gridWidth);

    // NewGeneration(grid, numberOfCells);

    PrintGrid(grid, gridWidth);

    ClearGrid(grid, gridWidth);
    return 0;
}