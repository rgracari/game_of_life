#include "lib.h"

void PopulateCells(Grid* grid, int rate)
{
    srand(time(NULL));
    int randomNumber = 0;
    int gridWidth = grid->gridWidth;
    for (int y = 0; y < gridWidth; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            randomNumber = (rand() % 101);
            grid->grid[y][x] = (randomNumber <= rate) ? Populated : Unpopulated;
        }
    }
}

void NewGeneration(Grid* grid)
{
    // ( y  x) ( y x) (y x)
    // ( 1 -1) ( 1 0) ( 1 1)
    // ( 0 -1) ( 0 0) ( 0 1)
    // (-1 -1) (-1 0) (-1 1)

    Postition neighbors[8] = {
        {1, -1},
        {1, 0},
        {1, 1},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 0},
        {-1, 1}};

    Grid* copy = CopyGrid(grid);

    int gridWidth = copy->gridWidth;
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
                    if (copy->grid[yNeighbor][xNeighbor] == Populated)
                    {
                        neighborCount++;
                    }
                }
            }
            if (copy->grid[y][x] == Populated)
            {
                if (neighborCount <= 1)
                {
                    grid->grid[y][x] = Unpopulated;
                }
                else if (neighborCount >= 4)
                {
                    grid->grid[y][x] = Unpopulated;
                }
            }
            else
            {
                if (neighborCount == 3)
                {
                    grid->grid[y][x] = Populated;
                }
            }
        }
    }
    FreeGrid(copy);
}

Grid* CopyGrid(Grid* grid)
{
    int gridWidth = grid->gridWidth;
    Grid* gridCopy = CreateGrid(gridWidth);
    for (int y = 0; y < gridWidth; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            gridCopy->grid[y][x] = grid->grid[y][x];
        }
    }
    return gridCopy;
}

Grid* CreateGrid(int gridWidth)
{
    Grid *gridPtr = (Grid*)malloc(sizeof(Grid));
    gridPtr->gridWidth = gridWidth;

    gridPtr->grid = (char **)malloc(gridWidth * sizeof(char *));
    for (int i = 0; i < gridWidth; i++)
    {
        gridPtr->grid[i] = (char *)malloc(gridWidth * sizeof(char));
    }
    return gridPtr;
}

void FreeGrid(Grid* grid)
{
    if (grid != NULL)
    {
        for (int i = 0; i < grid->gridWidth; i++)
        {
            free(grid->grid[i]);
        }
        free(grid->grid);
        free(grid);
    }
}
