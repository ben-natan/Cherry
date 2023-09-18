#ifndef RULE_H
#define RULE_H

#include <vector>
#include <assert.h>
#include <string>
#include "Tile.h"
#include "Color.h"
#include <iostream>

class Rule
{
    public:
        Rule(std::string _sourcePatternString, std::string _targetPatternString);

        int getPatternLength()
        {
            return patternLength;
        }

        int getMaxCount()
        {
            return maxCount;
        }

        void setMaxCount(int maxCount)
        {
            this->maxCount = maxCount;
        }

        int getCurrentCount()
        {
            return currentCount;
        }

        bool isDepleted();

        void useOne()
        {
            if (maxCount == -1)
            {
                return;
            }

            this->currentCount++;
            std::cout << this->currentCount << std::endl;
        }

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

        int maxCount;
        int currentCount;
};

#endif