#ifndef LIB_H_
#define LIB_H_

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct SPos
{
    int x;
    int y;
} Postition;

typedef struct SGrid
{
    char **grid;
    int gridWidth;
} Grid;

enum Cell
{
    Populated = '0',
    Unpopulated = '-'
};

void FreeGrid(Grid* grid);
Grid* CreateGrid(int gridWidth);
Grid* CopyGrid(Grid* grid);
void NewGeneration(Grid* grid);
void PopulateCells(Grid* grid, int rate);

#endif /* !LIB_H_ */
