#pragma once

#include <SFML/Graphics.hpp>

// Base class for all interactable objects in game
class GameObject : public sf::Drawable, public sf::Transformable {
protected:
    bool active_;
    bool visible_;
    bool exists_;

    enum Direction {
        Up,
        Down,
        Left,
        Right,
        UpRight,
        UpLeft,
        DownRight,
        DownLeft,
        None
    };

public:
    bool isVisible() const;

    bool isActive() const;

    bool isExisting() const;

    virtual void update(const sf::Time &time) = 0;

    GameObject();

    virtual ~GameObject() = default;
};

extern int dx[9];
extern int dy[9];