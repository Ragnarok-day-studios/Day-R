#pragma once

#include <signal/signal.hpp>

struct GameEvent{
    GameEvent();
    enum Type{

    };

    Type type;
};

extern Signal<GameEvent> gameEventSender;