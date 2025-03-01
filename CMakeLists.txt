cmake_minimum_required(VERSION 3.26)
project(oyun)

set(CMAKE_CXX_STANDARD 17)

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
        GameRules.h
        GameRules.cpp
        Play.h
        Play.cpp
        GameOver.h
        GameOver.cpp
        about_background.h
        game_background.h
        KenneyHighSquare.h
        paper.h
        rock.h
        rules.h
        scissors.h
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
