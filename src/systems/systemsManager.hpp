#pragma once

#include "assetManager.hpp"
#include "inputHandler.hpp"
#include "singleton.hpp"

class SystemsManager : public Singleton<SystemsManager>{
    private:
        AssetManager assetManager_;
        InputHandler inputHandler_;

    public:
        AssetManager& getAssetManager();
        InputHandler& getInputHandler();
};