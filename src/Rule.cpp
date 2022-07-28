#include "Rule.h"
#include <iostream>

Rule::Rule(std::string _sourcePatternString, std::string _targetPatternString)
{
    std::vector<Color> _sourcePattern;
    std::vector<Color> _targetPattern;

    for(char& c: _sourcePatternString)
    {
        char* pChar = (char*)malloc(sizeof(char));
        *pChar = c;
        Color _color = Color::_from_string(pChar);
        _sourcePattern.push_back(_color);
    }
    for(char& c: _targetPatternString)
    {
        char* pChar = (char*)malloc(sizeof(char));
        *pChar = c;
        Color _color = Color::_from_string(pChar);
        _targetPattern.push_back(_color);
    }

    assert (_sourcePattern.size() == _targetPattern.size());
    this->patternLength = _sourcePattern.size();

    this->sourcePattern = _sourcePattern;
    this->targetPattern = _targetPattern;
};