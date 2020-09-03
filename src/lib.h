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

void waitFor(unsigned int secs);
void FreeGrid(Grid* grid);
Grid* CreateGrid(int gridWidth);
char **CopyGrid(char **grid, int gridWidth);
void NewGeneration(char **grid, int gridWidth);
void PopulateCells(char **grid, int gridWidth, int rate);
void PrintGrid(char **grid, int gridWidth);

#endif /* !LIB_H_ */
