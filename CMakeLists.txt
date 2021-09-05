cmake_minimum_required(VERSION 3.8)

project(Game)

set(CMAKE_CXX_STANDARD 17)

# includes
include_directories(src)

# find SFML 2.5
if(WIN32)
    set(SFML_DIR libraries/win/SFML-2.5.1/lib/cmake/SFML/)
elseif(MSVC)
    set(SFML_DIR libraries/msvc/SFML-2.5.1/lib/cmake/SFML/)
else()
    set(SFML_DIR libraries/unix/SFML-2.5.1/lib/cmake/SFML/)
endif(WIN32)

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

add_executable(Game src/main.cpp src/json/json.hpp src/game.hpp src/game.cpp src/gameEvent.hpp src/gameEvent.cpp src/signal/listener.hpp src/signal/listener.cpp src/signal/signal.hpp src/signal/signal.cpp src/state/state.hpp src/state/state.cpp src/state/machine.hpp src/state/machine.cpp src/state/stateEvent.hpp src/state/stateEvent.cpp src/systems/scene.hpp src/systems/scene.cpp src/systems/systemsManager.hpp src/systems/systemsManager.cpp src/systems/assetManager.cpp src/systems/assetManager.hpp src/systems/inputHandler.hpp src/systems/inputHandler.cpp src/objects/gameObject.cpp src/objects/gameObject.hpp src/systems/animation.hpp src/systems/animation.cpp src/systems/animatedSprite.hpp src/systems/animatedSprite.cpp)

# compile options
target_compile_options(Game PRIVATE -Wall)

# link libraries
target_link_libraries(Game sfml-graphics sfml-window sfml-system sfml-audio sfml-network)