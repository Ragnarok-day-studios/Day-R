#pragma once

class Machine;

// Model of state from state machine
class State{
    private:
        bool active_;

    protected:
        Machine& fsm_;

    public:
        State(Machine& machine);
        ~State();

        void setActive(bool isActive);
        bool getActive();
};