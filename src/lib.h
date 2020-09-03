#ifndef LIB_H_
#define LIB_H_

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void waitFor(unsigned int secs);
void FreeGrid(char **grid, int gridWidth);
char **CreateGrid(int gridWidth);
char **CopyGrid(char **grid, int gridWidth);
void NewGeneration(char **grid, int gridWidth);
void PopulateCells(char **grid, int gridWidth, int rate);
void PrintGrid(char **grid, int gridWidth);
void PrintIntro();

#endif /* !LIB_H_ */
