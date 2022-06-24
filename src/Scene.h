#include <vector>
#include <iostream>

class Scene 
{
    public:
        Scene(int _width, int _height, int _tileSize): width(_width), height(_height), tileSize(_tileSize) 
        {
            tiles.resize(_width*_height);
        };

        virtual void Update();

        std::string getTile(int x, int y);

        std::string getTileFromPixel(int x, int y);

        int getTileSize();
        int getWidth();
        int getHeight();
        
    private:
        std::vector<std::string> tiles;
        void setTile(int x, int y, std::string color);

        int tileSize;

        int width;
        int height;
};
