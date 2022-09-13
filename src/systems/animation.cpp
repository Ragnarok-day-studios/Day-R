#include "animation.hpp"

const sf::Texture &Animation::getFrame(size_t i) {
    return *frames_[i];
}

size_t Animation::frameCount() const {
    return frames_.size();
}

void Animation::addFrame(const sf::Image &image, const sf::IntRect &frame) {
    sf::Texture *t = new sf::Texture;
    t->loadFromImage(image, frame);
    frames_.push_back(t);
}

Animation::~Animation() {
    for (auto &t: frames_) {
        delete t;
        t = nullptr;
    }
    frames_.clear();
}