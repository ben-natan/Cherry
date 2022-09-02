#ifndef RULE_H
#define RULE_H

#include <vector>
#include <assert.h>
#include <string>
#include "Tile.h"

class Rule
{
    public:
        Rule(std::string _sourcePatternString, std::string _targetPatternString);

        int getPatternLength()
        {
            return patternLength;
        };

        Color getSourcePatternColor(int i) 
        {
            return sourcePattern[i];
        }

        Color getTargetPatternColor(int i) 
        {
            return targetPattern[i];
        }

    private:
        std::vector<Color> sourcePattern;
        std::vector<Color> targetPattern;

        int patternLength;
};

#endif