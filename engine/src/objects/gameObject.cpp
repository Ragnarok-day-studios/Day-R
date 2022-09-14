#include "../../include/objects/gameObject.hpp"

bool GameObject::isActive() const {
    return active_;
}

bool GameObject::isExisting() const {
    return exists_;
}

bool GameObject::isVisible() const {
    return visible_;
}

GameObject::GameObject() {
    visible_ = active_ = exists_ = true;
}

int dx[9] = {0, 0, -1, 1, 1, -1, 1, -1, 0};
int dy[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};