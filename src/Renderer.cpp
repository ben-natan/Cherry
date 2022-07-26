#include <iostream>
#include <chrono>
#include "Renderer.h"

void Renderer::enterRenderLoop()
{
    bool quit = false;
    SDL_Event event;
    frameCount = 1;

    int numTicks = SDL_GetTicks();

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
                Color color = scene->getTileFromPixel(x, y).getColor();

                if (color == Color::Red)
                {
                    SDL_SetRenderDrawColor(renderer, 250, 0, 0, 255);
                }
                else if (color == Color::Green)
                {
                    SDL_SetRenderDrawColor(renderer, 0, 250, 0, 255);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 250, 255);
                }
                
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }

        SDL_RenderPresent(renderer);
        std::cout << "Frame: " << frameCount++ << '\r' << std::flush;


        while ((SDL_GetTicks() - numTicks) < 1000 / frameRate)
        {
            SDL_Delay((1000 / frameRate) - (SDL_GetTicks() - numTicks));
        }

        numTicks = SDL_GetTicks();
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