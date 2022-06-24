#include "Renderer.h"
#include <iostream>

int main()
{
    int height = 12;
    int width = 12;
    int tileSize = 30;

    Renderer renderer = Renderer(3);
    Scene* scene = new Scene(height, width, 30);

    renderer.setScene(scene);
    renderer.Init();

    renderer.enterRenderLoop();

    return 0;
}