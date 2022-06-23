#include <iostream>
#include "Renderer.h"

void Renderer::setPixel(uint32_t x, uint32_t y, uint32_t colour)
{
    pixels[x + y*winHeight] = colour;
}

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

        updateCallback();
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

void Renderer::setUpdateCallback(std::function<void()> _updateCallback)
{
    updateCallback = _updateCallback;
};