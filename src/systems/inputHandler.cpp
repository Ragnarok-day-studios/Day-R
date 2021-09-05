#include "inputHandler.hpp"

void InputHandler::handleEvents() {
	sf::Event event;
	while (window_->pollEvent(event)) {
		notify(event);
	}
	Signal::handleEvents();
}

void InputHandler::init() {

}

void InputHandler::registerWindow(sf::Window* window) {
	window_ = window;
}