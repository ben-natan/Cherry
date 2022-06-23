#include "Renderer.h"
#include <iostream>

int main()
{
    int height = 640;
    int width = 640;

    Renderer renderer = Renderer(height, width);
    Scene* scene = new Scene(height, width);

    renderer.Init();
    renderer.setScene(scene);

    renderer.enterRenderLoop();

    return 0;
}