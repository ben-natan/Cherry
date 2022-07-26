#ifndef RULE_H
#define RULE_H

#include <vector>
#include <assert.h>
#include "Tile.h"

class Rule
{
    public:
        Rule(std::vector<Color> _sourcePattern, std::vector<Color> _targetPattern): 
        sourcePattern(_sourcePattern), targetPattern(_targetPattern)
        {
            assert (_sourcePattern.size() == _targetPattern.size());
            patternLength = _sourcePattern.size();
        };

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