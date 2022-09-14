#pragma once

#include "state.hpp"

// Custom event model specially for state machine
struct StateEvent{
    enum Type{
        Add,
        Remove,
        Replace,
        Clear
    };

    Type type;

    struct AddEvent{
        State* state;
    };

    struct RemoveEvent{
        unsigned int count;
    };

    struct ReplaceEvent{
        State* state;
    };

    union{
        AddEvent add;
        RemoveEvent remove;
        ReplaceEvent replace;
    };
    
};