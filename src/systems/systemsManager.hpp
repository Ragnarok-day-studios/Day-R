#pragma once

#include "assetManager.hpp"
#include "inputHandler.hpp"
#include "singleton.hpp"

// Kind of a service provider built for managers
class SystemsManager : public Singleton<SystemsManager>{
    private:
        AssetManager assetManager_;
        InputHandler inputHandler_;

    public:
        AssetManager& getAssetManager();
        InputHandler& getInputHandler();
};