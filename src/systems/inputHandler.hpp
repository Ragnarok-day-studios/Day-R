#pragma once

#include <signal/signal.hpp>
#include <SFML/Window.hpp>

class InputHandler : public Signal<sf::Event> {
private:
	sf::Window* window_;

public:
	void init();
	void registerWindow(sf::Window* window);
	void handleEvents();
};