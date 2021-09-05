#include "animatedSprite.hpp"

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    if(animation_ != nullptr){
        states.transform.combine(getTransform());
        target.draw(sprite_, states);
    }
}

void AnimatedSprite::update(const sf::Time& time){
    if(animation_ != nullptr){
        deltaTime_ += time;
        while(deltaTime_ > frameTime_){
            deltaTime_ -= frameTime_;
            frame_++;
            if(frame_ == animation_->frameCount())
                frame_ = 0;
            sprite_.setTexture(animation_->getFrame(frame_));
        }
    }
}

void AnimatedSprite::setAnimation(Animation& animation){
    this->animation_ = &animation;
    deltaTime_ = sf::milliseconds(0);
}

void AnimatedSprite::setFrameTime(const sf::Time& time){
    frameTime_ = time;
}

AnimatedSprite::AnimatedSprite(){
    setFrameTime(sf::milliseconds(100));
    frame_ = 0;
}