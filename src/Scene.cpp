#include <random>
#include "Scene.h"

void Scene::setTile(int x, int y, std::string color)
{
    tiles.at(x + width*y) = color;
};

std::string Scene::getTile(int x, int y)
{
    return tiles[x + width*y];
};

std::string Scene::getTileFromPixel(int x, int y)
{
    int x_tile = x / tileSize;
    int y_tile = y / tileSize;

    return getTile(x_tile, y_tile);
};

void Scene::Update()
{
    for (int x=0; x<width; x++)
    {
        for (int y=0; y<height; y++)
        {
            std::random_device rd;
            std::mt19937 rng(rd());
            std::uniform_int_distribution<int> uni(1,2); // guaranteed unbiased

            auto random_integer = uni(rng);

            int color = random_integer;
            setTile(x, y, (color == 1) ? "R" : "B");
        }
    }
};

int Scene::getTileSize()
{
    return tileSize;
};

int Scene::getWidth()
{
    return width;
};

int Scene::getHeight()
{
    return height;
};
