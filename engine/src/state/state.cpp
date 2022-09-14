#include "state/state.hpp"

State::State(Machine &machine) : fsm_(machine) {
    setActive(false);
}

State::~State() {

}

bool State::getActive() {
    return active_;
}

void State::setActive(bool isActive) {
    active_ = isActive;
}