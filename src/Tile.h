#ifndef TILE_H
#define TILE_H

#include "Color.h"

class Tile
{
    public:
        Tile() = default;
        Tile(int _x, int _y, Color _color): x(_x), y(_y), color(_color) {};
        Tile(int _x, int _y, std::string _colorString): x(_x), y(_y) {
            if (colorMap.find(_colorString) == colorMap.end()) {
                this->color = Color::B;
            } else {
                this->color = colorMap[_colorString];
            }
        }

        void setColor(Color _color)
        {
            this->color = _color;
        };

        Color getColor()
        {
            return this->color;
        };

        int getX()
        {
            return this->x;
        };

        int getY()
        {
            return this->y;
        };

    private:
        int x;
        int y;
        Color color;
};

#endif
