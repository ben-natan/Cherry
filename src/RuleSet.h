#ifndef RULESET_H
#define RULESET_H

#include "Rule.h"

class RuleSet {
    public:
        RuleSet() = default;
        RuleSet(Rule _rule)
        {
            rules.push_back(_rule);
        };

        int size()
        {
            return rules.size();
        };

        Rule getRule(int i)
        {
            return rules[i];
        }

    private:
        std::vector<Rule> rules;
};

#endif