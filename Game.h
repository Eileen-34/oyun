#ifndef OYUN_GAME_H
#define OYUN_GAME_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "About.h"
#include "GameRules.h"
#include "Play.h"
#include "GameOver.h"

// To avoid typing "sf::" repeatedly
using namespace sf;

// Game class manages the overall game state and transitions between screens
class Game {
public:
    // Constructor
    Game();

    // Main game loop handling events, updating the game state and rendering the screen
    void run();

private:
    // Handles user input events
    void handleEvents();

    // Updates the game state based on the current screen
    void update();

    // Renders the current screen (menu, play, rules, about, and game over)
    void render();

    // SFML window for rendering the game
    RenderWindow window;

    // Background texture and sprite
    Texture backgroundTexture;
    Sprite backgroundSprite;

    // Font used for rendering
    Font font;

    // Game screens
    Menu menu;
    Play play;
    GameRules gameRules;
    About about;
    GameOver gameOver;

    // Enum to represent the current game state
    enum class GameState {
        Menu,
        Play,
        Rules,
        About,
        Exit,
        GameOver
    } currentState; // Variable to track the current game state

};

#endif //OYUN_GAME_H
