#pragma once

#include <signal/signal.hpp>

// Custom event model
struct GameEvent{
    GameEvent();
    enum Type{

    };

    Type type;
};

extern Signal<GameEvent> gameEventSender;