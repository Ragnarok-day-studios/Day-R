#pragma once

#include <SFML/Graphics.hpp>

class Animation{
    private:
        std::vector<sf::Texture*> frames_;

    public:
        const sf::Texture& getFrame(size_t i);
        void addFrame(const sf::Image& image, const sf::IntRect& frame);
        size_t frameCount() const;

        ~Animation();
};