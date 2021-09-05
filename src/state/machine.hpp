#pragma once

#include <stack>
#include <signal/signal.hpp>
#include "state.hpp"
#include "stateEvent.hpp"

class Machine : public Signal<StateEvent>, public Listener<StateEvent>{
    private:
        std::stack<State*> states_;

    public:
        void add(State* state);
        void replace(State* state);
        void remove(unsigned int count = 1);
        void clear();

        void onNotify(const StateEvent& event) override;

        State* getState();

        Machine();
        ~Machine();
};