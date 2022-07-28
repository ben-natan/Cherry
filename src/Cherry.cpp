#include <fstream>
#include <iostream>
#include <rapidxml/rapidxml.hpp>
#include "Renderer.h"
#include "RuleSet.h"

int main()
{
    int height = 100;
    int width = 100;
    int tileSize = 5;

    rapidxml::xml_document<> sceneDescription;
    rapidxml::xml_node<>* rootNode;

    std::ifstream xmlFile("models/WhiteHole.xml");
    std::vector<char> buffer((std::istreambuf_iterator<char>(xmlFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    sceneDescription.parse<0>(&buffer[0]);

    rootNode = sceneDescription.first_node("ruleset");

    rapidxml::xml_node<>* ruleNode = rootNode->first_node("rule");

    std::string sourcePatternString = ruleNode->first_attribute("source")->value();
    std::string targetPatternString = ruleNode->first_attribute("target")->value();

    Rule rule = Rule(sourcePatternString, targetPatternString);

    std::cout << "source: " << rule.getSourcePatternColor(0) 
    << rule.getSourcePatternColor(1) << std::endl;
    std::cout << "target: " << rule.getTargetPatternColor(0) 
    << rule.getTargetPatternColor(1) << std::endl;

    RuleSet ruleSet = RuleSet(rule);

    Renderer renderer = Renderer(20);

    Scene scene = Scene(height, width, tileSize, ruleSet);

    renderer.setScene(&scene);
    renderer.Init();

    renderer.enterRenderLoop();

    return 0;
}