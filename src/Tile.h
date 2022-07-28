#ifndef TILE_H
#define TILE_H

#define BETTER_ENUMS_DEFAULT_CONSTRUCTOR(Enum) \
  public:                                      \
    Enum() = default;
#include <enum.h>

BETTER_ENUM(Color, char, B = 1, I, P, E, N, D, A, W, R, O, Y, G, U, S, K, F);

class Tile
{
    public:
        Tile() = default;
        Tile(int _x, int _y, Color _color): x(_x), y(_y), color(_color) {};

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
