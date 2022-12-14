#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <iostream>
#include "RuleSet.h"
#include "Tile.h"

class Scene 
{
    public:
        Scene(int _width, int _height, int _tileSize, RuleSet _ruleSet, const std::vector<Tile>& initialTiles): 
        width(_width), height(_height), tileSize(_tileSize), ruleSet(_ruleSet)
        {
            tiles.resize(_width*_height);

            for (int x = 0; x < _width; x++)
            {
                for (int y = 0; y < _height; y++)
                {
                    this->tiles[x + _width*y] = Tile(x, y, Color::B);
                }
            }

            for (int i = 0; i < initialTiles.size(); i++)
            {
                Tile singleInitialTile = initialTiles[i];
                this->setTileColor(singleInitialTile.getX(), singleInitialTile.getY(), singleInitialTile.getColor());
            }
        };

        virtual void Update();

        int getTileSize();
        int getWidth();
        int getHeight();

        Tile getTile(int x, int y);
        void setTileColor(int x, int y, Color color);

        Tile getTileFromPixel(int px, int py);

        std::vector<Tile>* getRandomMatchingSourcePattern(Rule rule);
        void updateSourceTiles(std::vector<Tile> matchingSourceTiles, Rule rule);
        
    private:
        std::vector<Tile> tiles;
        
        int tileSize;

        int width;
        int height;

        RuleSet ruleSet;
};

#endif