cmake_minimum_required(VERSION 3.8)

project(TenQuatersEngine)

set(CMAKE_CXX_STANDARD 20)

# includes
#include_directories(include)

# find SFML 2.5
if (WIN32)
    set(SFML_DIR ../libraries/win/SFML-2.5.1/lib/cmake/SFML)
elseif (MSVC)
    set(SFML_DIR ../libraries/msvc/SFML-2.5.1/lib/cmake/SFML)
else ()
    set(SFML_DIR ../libraries/unix/SFML-2.5.1/lib/cmake/SFML)
endif (WIN32)

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

add_library(TenQuatersEngine SHARED src/signal/listener.cpp src/signal/signal.cpp src/state/state.cpp src/state/machine.cpp src/state/stateEvent.cpp src/systems/scene.cpp src/systems/systemsManager.cpp src/systems/assetManager.cpp src/systems/inputHandler.cpp src/objects/gameObject.cpp src/systems/animation.cpp src/systems/animatedSprite.cpp src/map/logicalMap.cpp src/map/logicalField.cpp src/map/graphicalMap.cpp src/map/mapMask.cpp src/systems/mapDecoder.cpp)

# compile options
target_compile_options(TenQuatersEngine PRIVATE -Wall)

# link libraries
target_link_libraries(TenQuatersEngine sfml-graphics sfml-window sfml-system sfml-audio sfml-network)