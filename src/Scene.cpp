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

int getRandomNumber(int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, max - 1);
    return dist(rng);
}

std::vector<Tile>* Scene::getRandomMatchingSourcePattern(Rule rule)
{

    int patternLength = rule.getPatternLength();
    std::vector<std::vector<Tile>> matchingSourceTileSets;

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
                    std::vector<Tile>* singleMatchingSourceTileSet = new std::vector<Tile>();
                    for (int i = 0; i < patternLength; i++)
                    {
                        singleMatchingSourceTileSet->push_back(this->getTile(x+i, y));
                    }
                    matchingSourceTileSets.push_back(*singleMatchingSourceTileSet);
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
                    std::vector<Tile>* singleMatchingSourceTileSet = new std::vector<Tile>();
                    for (int i = 0; i < patternLength; i++)
                    {
                        singleMatchingSourceTileSet->push_back(this->getTile(x - i, y));
                    }
                    matchingSourceTileSets.push_back(*singleMatchingSourceTileSet);
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
                    std::vector<Tile>* singleMatchingSourceTileSet = new std::vector<Tile>();
                    for (int i = 0; i < patternLength; i++)
                    {
                        singleMatchingSourceTileSet->push_back(this->getTile(x, y + i));
                    }
                    matchingSourceTileSets.push_back(*singleMatchingSourceTileSet);
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
                    std::vector<Tile>* singleMatchingSourceTileSet = new std::vector<Tile>();
                    for (int i = 0; i < patternLength; i++)
                    {
                        singleMatchingSourceTileSet->push_back(this->getTile(x, y - i));
                    }
                    matchingSourceTileSets.push_back(*singleMatchingSourceTileSet);
                }
            }
        }
    }

    int matchingSourceTileSetsCount = matchingSourceTileSets.size();
    if (matchingSourceTileSetsCount == 0) return NULL;

    int randomNumber = getRandomNumber(matchingSourceTileSetsCount);

    std::vector<Tile>* pickedMatchingSourceTileSet= new std::vector<Tile>();
    *pickedMatchingSourceTileSet = matchingSourceTileSets[randomNumber];
    return pickedMatchingSourceTileSet;
}

void Scene::updateSourceTiles(std::vector<Tile> matchingSourceTiles, Rule rule)
{
    for (int i = 0; i < matchingSourceTiles.size(); i++)
    {
        Tile currentTile = matchingSourceTiles[i];
        this->setTileColor(currentTile.getX(), currentTile.getY(), rule.getTargetPatternColor(i));
    }
}


void Scene::Update()
{
    // 1. Get all source patterns
    // 2. Pick one randomly  (For now, we pick the first)
    // 3. Update the sourcePattern with the targetPattern
    // else go to next Rule in the RuleSet

    int ruleSetLength = this->ruleSet.size();
    std::vector<Tile>* matchingSourcePattern = NULL;
    bool foundOneMatch = false;
    int pickedRule = -1;

    for (int i=0; i<ruleSetLength; i++)
    {

        matchingSourcePattern = this->getRandomMatchingSourcePattern(ruleSet.getRule(i));

        if (matchingSourcePattern != NULL)
        {
            foundOneMatch = true;
            pickedRule = i;
            break;
        };
    }

    if (foundOneMatch)
    {
        this->updateSourceTiles(*matchingSourcePattern, ruleSet.getRule(pickedRule));
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
