#include <iostream>
#include "Renderer.h"

SDL_Window* Renderer::createWindow(int height, int width)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Initialization failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    SDL_Window* window = SDL_CreateWindow(
        "Cherry",
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        width,
        height, 
        SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    return window;
}

SDL_Renderer* Renderer::createRendererFromWindow()
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    return renderer;
};

void Renderer::enterRenderLoop()
{
    bool quit = false;
    SDL_Event event;

    while (!quit) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);

        scene->Update();

        for (int y=0; y<winHeight; y++)
        {
            for (int x=0; x<winWidth; x++)
            {
                int color = scene->getPixel(x,y);
                SDL_SetRenderDrawColor(renderer, color, color, color, 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }

        SDL_RenderPresent(renderer);
    }

    // Maybe move them in the destructor
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
};

void Renderer::Init()
{
    createWindow(winHeight, winWidth);
    createRendererFromWindow();
}

void Renderer::setScene(Scene* _scene)
{
    scene = _scene;
}