#include <vector>
#include <iostream>

class Scene 
{
    public:
        Scene(int _width, int _height): width(_width), height(_height) 
        {
            pixels.resize(_width*_height);
        };

        virtual void Update();

        int getPixel(int x, int y);

    private:
        std::vector<int> pixels;
        void setPixel(int x, int y, int color);

        int width;
        int height;
};
