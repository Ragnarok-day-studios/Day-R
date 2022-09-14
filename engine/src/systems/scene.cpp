#include "../../include/systems/scene.hpp"
#include <objects/gameObject.hpp>
#include "../../../game/include/gameEvent.hpp"
#include "../../include/systems/systemsManager.hpp"

void Scene::onNotify(const sf::Event& event) {
    if (getActive()) {
        
    }
}

Scene::Scene(Machine& machine) : State(machine) {
    SystemsManager::get().getInputHandler().addListener(this);
}

Scene::~Scene() {
    SystemsManager::get().getInputHandler().removeListener(this);
    for (auto& o : objects_) {
        delete o;
    }
}

void Scene::addObject(GameObject* object) {
    objects_.push_back(object);
}

void Scene::update(const sf::Time& time) {
    for (auto o : objects_) {
        if (o->isExisting() && o->isActive()) {
            o->update(time);
        }
    }
    refresh();
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto o : objects_) {
        if (o->isVisible() && o->isExisting()) {
            target.draw(*o, states);
        }
    }
}

void Scene::refresh() {
    for (auto o : objects_) {
        if (!o->isExisting()) {
            std::swap(o, objects_.back());
            delete objects_.back();
            objects_.pop_back();
        }
    }
}