#include <random>
#include "Scene.h"
#include <iostream>

void Scene::setTileColor(int x, int y, Color color)
{
    this->tiles.at(x + width*y).setColor(color);
};

Tile Scene::getTile(int x, int y)
{
    return this->tiles[x + width*y];
}

Tile Scene::getTileFromPixel(int px, int py)
{
    int x_tile = px / tileSize;
    int y_tile = py / tileSize;

    return this->getTile(x_tile, y_tile);
};

std::vector<Tile>* Scene::getFirstMatchingSourceTiles(Rule rule)
{

    int patternLength = rule.getPatternLength();

    for (int x = 0; x < this->width; x++)
    {
        for (int y = 0; y < this->height; y++)
        {
            // EAST
            if (patternLength + x < this->width)
            {
                bool match = true;
                for (int i = 0; i < patternLength; i++)
                {
                    Tile currentTile = this->getTile(x + i, y);
                    if (currentTile.getColor() !=  rule.getSourcePatternColor(i))
                    {
                        match = false;
                    }
                }
                if (match)
                {
                    std::vector<Tile>* firstMatchingSourceTiles = new std::vector<Tile>();
                    for (int i = 0; i < patternLength; i++)
                    {
                        firstMatchingSourceTiles->push_back(this->getTile(x+i, y));
                    }
                    return firstMatchingSourceTiles;
                }
            }

            // WEST
            if (x > patternLength)
            {
                bool match = true;
                for (int i = 0; i < patternLength; i++)
                {
                    Tile currentTile = this->getTile(x - i, y);
                    if (currentTile.getColor() !=  rule.getSourcePatternColor(i))
                    {
                        match = false;
                    }
                }
                if (match)
                {
                    std::vector<Tile>* firstMatchingSourceTiles = new std::vector<Tile>();
                    for (int i = 0; i < patternLength; i++)
                    {
                        firstMatchingSourceTiles->push_back(this->getTile(x - i, y));
                    }
                    return firstMatchingSourceTiles;
                }
            }

            // NORTH
            if (patternLength + y < this->height)
            {
                bool match = true;
                for (int i = 0; i < patternLength; i++)
                {
                    Tile currentTile = this->getTile(x, y + i);
                    if (currentTile.getColor() !=  rule.getSourcePatternColor(i))
                    {
                        match = false;
                    }
                }
                if (match)
                {
                    std::vector<Tile>* firstMatchingSourceTiles = new std::vector<Tile>();
                    for (int i = 0; i < patternLength; i++)
                    {
                        firstMatchingSourceTiles->push_back(this->getTile(x, y + i));
                    }
                    return firstMatchingSourceTiles;
                }
            }

            // SOUTH
            if (y > patternLength)
            {
                bool match = true;
                for (int i = 0; i < patternLength; i++)
                {
                    Tile currentTile = this->getTile(x, y - i);
                    if (currentTile.getColor() !=  rule.getSourcePatternColor(i))
                    {
                        match = false;
                    }
                }
                if (match)
                {
                    std::vector<Tile>* firstMatchingSourceTiles = new std::vector<Tile>();
                    for (int i = 0; i < patternLength; i++)
                    {
                        firstMatchingSourceTiles->push_back(this->getTile(x, y - i));
                    }
                    return firstMatchingSourceTiles;
                }
            }
        }
    }

    return NULL;
}

void Scene::updateSourceTiles(std::vector<Tile> matchingSourceTiles, Rule rule)
{
    for (int i = 0; i < matchingSourceTiles.size(); i++)
    {
        Tile currentTile = matchingSourceTiles[i];
        this->setTileColor(currentTile.getX(), currentTile.getY(), rule.getTargetPatternColor(i));
    }
}



// void Scene::Update()
// {
//     for (int x=0; x<width; x++)
//     {
//         for (int y=0; y<height; y++)
//         {
//             std::random_device rd;
//             std::mt19937 rng(rd());
//             std::uniform_int_distribution<int> uni(1,3); // guaranteed unbiased

//             auto random_integer = uni(rng);

//             int color = random_integer;

//             if (color == 1)
//             {
//                 setTile(x, y, "R");
//             }
//             else if (color == 2)
//             {
//                 setTile(x, y, "G");
//             }
//             else {
//                 setTile(x, y, "B");
//             }
//         }
//     }
// };


void Scene::Update()
{
    // 1. Get all source patterns
    // 2. Pick one randomly  (For now, we pick the first)
    // 3. Update the sourcePattern with the targetPattern
    // else go to next Rule in the RuleSet

    int ruleSetLength = this->ruleSet.size();
    std::vector<Tile>* matchingSourceTiles = NULL;
    bool foundOneMatch = false;
    int pickedRule = -1;

    for (int i=0; i<ruleSetLength; i++)
    {

        matchingSourceTiles = this->getFirstMatchingSourceTiles(ruleSet.getRule(i));

        if (matchingSourceTiles != NULL)
        {
            foundOneMatch = true;
            pickedRule = i;
            break;
        };
    }

    if (foundOneMatch)
    {
        this->updateSourceTiles(*matchingSourceTiles, ruleSet.getRule(pickedRule));
    }
}

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
