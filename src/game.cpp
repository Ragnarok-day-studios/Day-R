#include "game.hpp"
#include <systems/systemsManager.hpp>
#include <iostream>

Game::Game(){
    window_.create(sf::VideoMode(1920, 1080), "Game");

    SystemsManager::get().getAssetManager().load();

    SystemsManager::get().getInputHandler().addListener(this);
    SystemsManager::get().getInputHandler().registerWindow(&window_);

    gameEventSender.addListener(this);

    sceneMachine_.add(newGame());

    active_ = true;
}

void Game::run(){
    sf::Clock clock;
    sf::Time time;

    Scene* scene;

    //sf::Time fpsShowTime = sf::seconds(0.5);
    //sf::Time deltaTime = sf::Time::Zero;
    

    while(active_){
        time = clock.restart();

        scene = getScene();

        SystemsManager::get().getInputHandler().handleEvents();
        gameEventSender.handleEvents();

        scene->update(time);

        window_.clear();

        window_.draw(*scene);
        //deltaTime += time;
        /*while(deltaTime >= fpsShowTime){
            std::cout << static_cast<int>(sf::seconds(1) / time) << "\n";
            deltaTime -= fpsShowTime;
        }*/
        window_.display();
    }

    window_.close();
    gameEventSender.removeListener(this);
}

Game::~Game(){
    SystemsManager::get().getInputHandler().removeListener(this);
    sceneMachine_.clear();
}

void Game::onNotify(const sf::Event& event){
    if(event.type == sf::Event::Closed){
        active_ = false;
    }
}

void Game::onNotify(const GameEvent& event){

}

Scene* Game::getScene(){
    return static_cast<Scene*>(sceneMachine_.getState());
}

Scene* Game::newGame(){
    Scene* scene = new Scene(sceneMachine_);

    return scene;
}