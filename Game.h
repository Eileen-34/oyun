#ifndef OYUN_GAME_H
#define OYUN_GAME_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "About.h"
#include "GameRules.h"
#include "Play.h"
#include "GameOver.h"

using namespace sf;

class Game {
public:
    Game();
    void run();

private:
    void handleEvents();
    void update();
    void render();

    RenderWindow window;
    Texture backgroundTexture;
    Sprite backgroundSprite;
    Font font;
    Menu menu;
    Play play;
    GameRules gameRules;
    About about;
    GameOver gameOver;

    enum class GameState {
        Menu,
        Play,
        Rules,
        About,
        Exit,
        GameOver
    } currentState;

};

#endif //OYUN_GAME_H
