#include "lib.h"

SDL_Window* CreateSDLWindow(const char* name, int width, int height)
{
    return SDL_CreateWindow(
        name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN);
}

SDL_Renderer* CreateSDLRenderer(SDL_Window* window)
{
    return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void ProcessInput(int* isRunning)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                *isRunning = 0;
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_ESCAPE)
                    *isRunning = 0;
                break;
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

void DrawGrid(Grid* grid, SDL_Renderer* renderer, int wWidth)
{
    int gridWidth = grid->gridWidth;
    int gridTile =  wWidth / grid->gridWidth; 

    for (int y = 0; y < gridWidth; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            int color = grid->grid[y][x] == Populated ? 0x00 : 0xFF;
            SDL_Rect rect = {
                gridTile * x,
                gridTile * y,
                gridTile,
                gridTile
            };
            SDL_SetRenderDrawColor(renderer, color, color, color, color);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    const char* NAME = "Game of life";
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 800;

    InitSDL();

    SDL_Window *window = CreateSDLWindow(NAME, WINDOW_WIDTH, WINDOW_HEIGHT);
    SDL_Renderer *renderer = CreateSDLRenderer(window);
    int isRunning = 1;

    Grid* grid = CreateGrid(400);

    PopulateCells(grid, 20);

    // game loop
    while (isRunning)
    {
        ProcessInput(&isRunning);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
        DrawGrid(grid, renderer, WINDOW_WIDTH);
        SDL_RenderPresent(renderer);
        NewGeneration(grid);
    }

    FreeGrid(grid);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
