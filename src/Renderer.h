#include <stdlib.h>
#include <SDL.h>
#include "Scene.h"

class Renderer 
{
    public:
        Renderer(int _frameRate): frameRate(_frameRate) {};

        void Init();

        void setScene(Scene* scene);

        void enterRenderLoop();

    private:
        int winHeight;
        int winWidth;
        int frameCount;

        int frameRate;

        SDL_Window* window;
        SDL_Renderer* renderer;

        Scene* scene;
};