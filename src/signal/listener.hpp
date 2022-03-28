#pragma once

// Model for a listener of events
template<typename T>
class Listener {
    public:
        virtual void onNotify(const T& event) = 0;
        virtual ~Listener() = default;
};