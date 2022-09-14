#pragma once

#include "state/state.hpp"
#include <SFML/Graphics.hpp>
#include "signal/listener.hpp"
#include "objects/gameObject.hpp"

// Here all things are going to be drawn to
class Scene : public State, public sf::Drawable, public Listener<sf::Event> {
public:
    void onNotify(const sf::Event &event) override;

    void update(const sf::Time &time);

    void addObject(GameObject *object);

    Scene(Machine &machine);

    ~Scene();

protected:
    std::vector<GameObject *> objects_;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void refresh();
};