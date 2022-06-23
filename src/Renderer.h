#include <stdlib.h>
#include <SDL.h>
#include "Scene.h"

class Renderer 
{
    public:
        Renderer(int height, int width): winHeight(height), winWidth(width) {};

        void Init();

        void setScene(Scene* scene);

        void enterRenderLoop();

    private:
        int winHeight;
        int winWidth;

        SDL_Window* window;
        SDL_Renderer* renderer;

        SDL_Window* createWindow(int height, int width);
        SDL_Renderer* createRendererFromWindow();

        Scene* scene;
};