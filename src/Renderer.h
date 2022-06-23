#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <SDL.h>

class Renderer 
{
    public:
        Renderer(int height, int width): winHeight(height), winWidth(width) {};

        void Init();
        void setUpdateCallback(std::function<void()> _updateCallback);
        void enterRenderLoop();

        void setPixel(uint32_t x, uint32_t y, uint32_t color);

    private:
        std::vector<uint32_t> pixels;

        uint32_t winHeight;
        uint32_t winWidth;

        SDL_Window* window;
        SDL_Renderer* renderer;

        SDL_Window* createWindow(int height, int width);
        SDL_Renderer* createRendererFromWindow();

        std::function<void()> updateCallback;
};