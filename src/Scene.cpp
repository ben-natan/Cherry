#include <random>
#include "Scene.h"

void Scene::setPixel(int x, int y, int color)
{
    pixels.at(x + width*y) = color;
};

int Scene::getPixel(int x, int y)
{
    return pixels[x + width*y];
}

void Scene::Update()
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(1,250); // guaranteed unbiased

    auto random_integer = uni(rng);

    int color = random_integer;

    for (int x=0; x<width; x++)
    {
        for (int y=0; y<height; y++)
        {
            setPixel(x, y, color);
        }
    }

    std::cout << "Updated with color=" << color << std::endl;
}
