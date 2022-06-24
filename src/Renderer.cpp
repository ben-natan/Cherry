#include <iostream>
#include "Renderer.h"

void Renderer::enterRenderLoop()
{
    bool quit = false;
    SDL_Event event;
    frame = 1;

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
                std::string colorCode = scene->getTileFromPixel(x, y);

                if (!colorCode.compare("R"))
                {
                    SDL_SetRenderDrawColor(renderer, 250, 0, 0, 255);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 250, 255);
                }
                
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }

        SDL_RenderPresent(renderer);
        std::cout << "Frame: " << frame++ << '\r' << std::flush;
    }

    // Maybe move them in the destructor
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
};

void Renderer::Init()
{
    int flags = SDL_WINDOW_SHOWN ;
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        return ;
    }
    if (SDL_CreateWindowAndRenderer(winWidth, winHeight, flags, &window, &renderer)) {
        return;
    }
};

void Renderer::setScene(Scene* _scene)
{
    scene = _scene;
    winWidth = scene->getWidth() * scene->getTileSize();
    winHeight = scene->getHeight() * scene->getTileSize();
};