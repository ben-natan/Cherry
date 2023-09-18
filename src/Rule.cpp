#include "Rule.h"
#include <iostream>

Rule::Rule(std::string _sourcePatternString, std::string _targetPatternString)
{
    std::vector<Color> _sourcePattern;
    std::vector<Color> _targetPattern;

    for(char& c: _sourcePatternString)
    {
        std::string _colorString(1, c);

        if (colorMap.find(_colorString) == colorMap.end()) {
            _sourcePattern.push_back(Color::B);
        } else {
            _sourcePattern.push_back(colorMap[_colorString]);
        }
    }
    for(char& c: _targetPatternString)
    {
        std::string _colorString(1, c);

        if (colorMap.find(_colorString) == colorMap.end()) {
            _targetPattern.push_back(Color::B);
        } else {
            _targetPattern.push_back(colorMap[_colorString]);
        }
    }

    assert (_sourcePattern.size() == _targetPattern.size());
    this->patternLength = _sourcePattern.size();

    this->sourcePattern = _sourcePattern;
    this->targetPattern = _targetPattern;
};