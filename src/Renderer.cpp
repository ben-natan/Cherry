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

                int r, g, b;
                this->ColorToRGB(color, r, g, b);
                SDL_SetRenderDrawColor(renderer, r, g, b, 255);
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

void Renderer::ColorToRGB(Color color, int& r, int& g, int &b)
{
    switch (color)
    {
        case Color::B:
            r = 0;
            g = 0;
            b = 0;
            break;

        case Color::I:
            r = 29;
            g = 43;
            b = 83;
            break;
        
        case Color::P:
            r = 126;
            g = 37;
            b = 83;
            break;

        case Color::E:
            r = 0;
            g = 135;
            b = 81;
            break;
        
        case Color::N:
            r = 171;
            g = 82;
            b = 54;
            break;

        case Color::D:
            r = 95;
            g = 87;
            b = 79;
            break;
       
        case Color::A:
            r = 194;
            g = 195;
            b = 199;
            break;
        
        case Color::W:
            r = 255;
            g = 241;
            b = 232;
            break;

        case Color::R:
            r = 255;
            g = 0;
            b = 77;
            break;

        case Color::O:
            r = 255;
            g = 163;
            b = 0;
            break;

        case Color::Y:
            r = 255;
            g = 236;
            b = 39;
            break;

        case Color::G:
            r = 0;
            g = 228;
            b = 54;
            break;

        case Color::U:
            r = 41;
            g = 173;
            b = 255;
            break;

        case Color::S:
            r = 131;
            g = 118;
            b = 156;
            break;

        case Color::K:
            r = 255;
            g = 119;
            b = 168;
            break;

        case Color::F:
            r = 255;
            g = 204;
            b = 170;
    }
}