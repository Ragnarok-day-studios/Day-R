#pragma once

#include <queue>
#include <set>
#include "listener.hpp"

template<typename T>
class Signal{
    private:
        std::queue<T> events_;
        std::set<Listener<T>*> listeners_;

    public:
        void addListener(Listener<T>* listener){
            listeners_.insert(listener);
        }

        void removeListener(Listener<T>* listener){
            listeners_.erase(listeners_.find(listener));
        }

        void notify(const T& event){
            events_.push(event);
        }

        void handleEvents(){
            T* event;
            while(!events_.empty()){
                event = &events_.front();
                for(auto l : listeners_){
                    l->onNotify(*event);
                }
                events_.pop();
            }
        }
};