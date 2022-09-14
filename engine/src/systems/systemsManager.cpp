#include "systems/systemsManager.hpp"

AssetManager &SystemsManager::getAssetManager() {
    return assetManager_;
}

InputHandler &SystemsManager::getInputHandler() {
    return inputHandler_;
}