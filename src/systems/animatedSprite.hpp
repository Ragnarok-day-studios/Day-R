#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "animation.hpp"

class AnimatedSprite : public sf::Drawable, public sf::Transformable{
    private:
        Animation* animation_;
        sf::Sprite sprite_;
        sf::Time frameTime_;
        sf::Time deltaTime_;

        size_t frame_;

    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    public:
        void setFrameTime(const sf::Time& time);
        void update(const sf::Time& time);
        void setAnimation(Animation& animation);

        AnimatedSprite();
};