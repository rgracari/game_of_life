#include "lib.h"

SDL_Window* CreateSDLWindow(const char* name)
{
    return SDL_CreateWindow(
        name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        800,
        SDL_WINDOW_SHOWN);
}

SDL_Renderer* CreateSDLRenderer(SDL_Window* window)
{
    return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void ProcessInput(int* isRunning)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            *isRunning = 0;
        }
    }
}

void InitSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return;
    }
}

int main(int argc, char *argv[])
{
    InitSDL();

    SDL_Window *window = CreateSDLWindow("Game of life");
    SDL_Renderer *renderer = CreateSDLRenderer(window);
    int isRunning = 1;

    // game loop
    while (isRunning)
    {
        ProcessInput(&isRunning);
        // Update
        // Render
    }

    // int gridWidth = 17;
    // char **grid = CreateGrid(gridWidth);

    // PopulateCells(grid, gridWidth, 20);
    // for (int i = 0; i < 10; i++)
    // {
    //     PrintGrid(grid, gridWidth);
    //     NewGeneration(grid, gridWidth);
    // }
    // FreeGrid(grid, gridWidth);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
