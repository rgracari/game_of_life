#include <SDL.h>

#include "lib.h"

int main(int argc, char *argv[])
{
    int gridWidth = 17;
    char **grid = CreateGrid(gridWidth);

    PopulateCells(grid, gridWidth, 20);
    for (int i = 0; i < 10; i++)
    {
        PrintGrid(grid, gridWidth);
        NewGeneration(grid, gridWidth);
    }
    FreeGrid(grid, gridWidth);
    return 0;
}
