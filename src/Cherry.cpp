#include <fstream>
#include <iostream>
#include <rapidxml/rapidxml.hpp>
#include "Renderer.h"
#include "RuleSet.h"

int main(int argc, char* argv[])
{
    int height, width, tileSize;

    rapidxml::xml_document<> sceneDescription;
    rapidxml::xml_node<>* rootNode;
    rapidxml::xml_node<>* ruleSetNode;
    rapidxml::xml_node<>* initialSceneNode;

    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl
        << "Usage: ./Cherry MODELNAME" << std::endl
        << "   Ex: ./Cherry Tiles" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filePath(std::string("models/") + std::string(argv[1]) + std::string(".xml"));
    std::ifstream xmlFile(filePath);
    std::vector<char> buffer((std::istreambuf_iterator<char>(xmlFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    sceneDescription.parse<0>(&buffer[0]);

    rootNode = sceneDescription.first_node("Cherry");
    height = atoi(rootNode->first_attribute("height")->value());
    width = atoi(rootNode->first_attribute("width")->value());
    tileSize = atoi(rootNode->first_attribute("tileSize")->value());

    ruleSetNode = rootNode->first_node("ruleset");
    std::vector<Rule> rules;
    for (rapidxml::xml_node<>* rule = ruleSetNode->first_node("rule"); rule; rule = rule->next_sibling())
    {
        std::string sourcePatternString = rule->first_attribute("source")->value();
        std::string targetPatternString = rule->first_attribute("target")->value();
        Rule ruleObject(sourcePatternString, targetPatternString);
        rules.push_back(ruleObject);
    }

    RuleSet ruleSet = RuleSet(rules);

    Renderer renderer = Renderer(20);

    initialSceneNode = rootNode->first_node("initial");
    std::vector<Tile> initialTiles;
    for (rapidxml::xml_node<>* tile = initialSceneNode->first_node("tile"); tile; tile = tile->next_sibling())
    {
        int x, y;
        Color color;
        x = atoi(tile->first_attribute("x")->value());
        y = atoi(tile->first_attribute("y")->value());
        color = Color::_from_string(tile->first_attribute("color")->value());
        initialTiles.push_back(Tile(x, y, color));
    }

    Scene scene = Scene(height, width, tileSize, ruleSet, initialTiles);

    renderer.setScene(&scene);
    renderer.Init();

    renderer.enterRenderLoop();

    return 0;
}