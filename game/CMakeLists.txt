cmake_minimum_required(VERSION 3.8)

project(Game)

set(CMAKE_CXX_STANDARD 20)

# includes
include_directories(include)

add_subdirectory(../engine)

# find SFML 2.5
if(WIN32)
    set(SFML_DIR ../libraries/win/SFML-2.5.1/lib/cmake/SFML)
elseif(MSVC)
    set(SFML_DIR ../libraries/msvc/SFML-2.5.1/lib/cmake/SFML)
else()
    set(SFML_DIR ../libraries/unix/SFML-2.5.1/lib/cmake/SFML)
endif(WIN32)

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

add_executable(Game src/main.cpp src/game.cpp src/gameEvent.cpp)

# compile options
target_compile_options(Game PRIVATE -Wall)

# link libraries
target_link_libraries(Game sfml-graphics sfml-window sfml-system sfml-audio sfml-network TenQuatersEngine)

target_include_directories(Game "../engine/include")