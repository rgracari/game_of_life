#include "lib.h"

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

    int gridWidth = 17;
    char **grid = CreateGrid(gridWidth);

    PopulateCells(grid, gridWidth, 20);

    // PrintGrid(grid, gridWidth);
    // NewGeneration(grid, gridWidth);
    // PrintGrid(grid, gridWidth);

    for (int i = 0; i < 10; i++)
    {
        PrintGrid(grid, gridWidth);
        NewGeneration(grid, gridWidth);
    }

    // while (1)
    // {
    //     PrintGrid(grid, gridWidth);
    //     NewGeneration(grid, gridWidth);
    // }

    FreeGrid(grid, gridWidth);
    return 0;
}
