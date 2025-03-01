#ifndef OYUN_GAME_H
#define OYUN_GAME_H

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "About.h"
#include "GameRules.h"
#include "Play.h"
#include "GameOver.h"

class Game {
public:
    Game();
    void run();

private:
    void handleEvents();
    void update();
    void render();

    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    Menu menu;
    Play play;
    GameRules gameRules;
    About about;
    GameOver gameOver;

    enum class GameState {
        Menu,
        Play,
        Scores,
        Rules,
        About,
        Exit,
        GameOver
    } currentState;

};

#endif //OYUN_GAME_H
