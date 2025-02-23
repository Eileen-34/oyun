cmake_minimum_required(VERSION 3.26)
project(oyun)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.6.2 COMPONENTS graphics window system audio REQUIRED)

add_executable(oyun main.cpp
        Button.h
        Button.cpp
        Menu.h
        Menu.cpp
        Game.h
        Game.cpp
        About.h
        About.cpp
)

# Link SFML libraries
target_link_libraries(oyun
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)

# Copy assets to build directory
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
