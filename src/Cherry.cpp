#include "Renderer.h"
#include <iostream>

void testCallback()
{
    int i = 0;
    while (i<10000) {
        i++;
    }
    std::cout << "One render loop" << std::endl;
}

int main()
{
    Renderer renderer = Renderer(640, 640);

    renderer.Init();
    renderer.setUpdateCallback(testCallback);

    renderer.enterRenderLoop();

    return 0;
}