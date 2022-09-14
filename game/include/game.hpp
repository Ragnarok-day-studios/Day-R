#pragma once

#include <SFML/Graphics.hpp>
#include "gameEvent.hpp"
#include "signal/listener.hpp"
#include "state/machine.hpp"
#include "systems/scene.hpp"

//main game class where everything comes to life
class Game : public Listener<GameEvent>, public Listener<sf::Event> {
private:
    bool active_;

    Machine sceneMachine_;

    sf::RenderWindow window_;

public:
    Game();

    ~Game();

    Scene *getScene();

    Scene *newGame();

    void run();

    void onNotify(const GameEvent &event) override;

    void onNotify(const sf::Event &event) override;
};