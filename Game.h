#ifndef OYUN_GAME_H
#define OYUN_GAME_H

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "About.h"

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
    About about;
    enum class GameState {
        Menu,
        Play,
        Scores,
        Rules,
        About,
        Exit } currentState;
};

#endif //OYUN_GAME_H
