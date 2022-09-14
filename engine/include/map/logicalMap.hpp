#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "logicalField.hpp"

// Logical part of map handling where you can move and where not
class LogicalMap {
private:
    std::vector<LogicalField> map_;

public:
    LogicalField &getField(const unsigned int x, const unsigned int y);

    const LogicalField &getField(const unsigned int x, const unsigned int y) const;

    LogicalField &getField(const sf::Vector2u &position);

    const LogicalField &getField(const sf::Vector2u &position) const;

};