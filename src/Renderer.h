#include <stdlib.h>
#include <SDL.h>
#include "Scene.h"

class Renderer 
{
    public:
        Renderer() = default;

        void Init();

        void setScene(Scene* scene);

        void enterRenderLoop();

    private:
        int winHeight;
        int winWidth;
        int frame;

        SDL_Window* window;
        SDL_Renderer* renderer;

        Scene* scene;
};