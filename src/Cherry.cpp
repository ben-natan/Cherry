#include "Renderer.h"
#include <iostream>
#include "RuleSet.h"

int main()
{
    int height = 12;
    int width = 12;
    int tileSize = 30;

    Renderer renderer = Renderer(3);

    // Should be defined elsewhere
    std::vector<Color> sourcePattern = {Color::Red, Color::Blue};
    std::vector<Color> targetPattern = {Color::Blue, Color::Blue};
    Rule rule = Rule(sourcePattern, targetPattern);
    RuleSet ruleSet = RuleSet(rule);

    Scene* scene = new Scene(height, width, tileSize, ruleSet);

    renderer.setScene(scene);
    renderer.Init();

    renderer.enterRenderLoop();

    return 0;
}