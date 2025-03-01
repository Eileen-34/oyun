#ifndef OYUN_GAMERULES_H
#define OYUN_GAMERULES_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;

// GameRules class represents the "rules" screen of the game
class GameRules {
public:
    //Constructor
    explicit GameRules(const Font& font);

    // Handles user input events (e.g., mouse clicks)
    void handleEvent(const Event& event, const RenderWindow& window);

    // Updates the state of the "rules" screen (e.g., button states)
    void update(const RenderWindow& window);

    // Draws the rules screen (background, text, and buttons) to the window
    void draw(RenderWindow& window) const;

    // Sets the callback function for the "Back" button click
    void setOnBackClicked(std::function<void()> onClick);

private:
    Texture backgroundTexture;
    Sprite backgroundSprite;
    Text rulesText;
    Button backButton;
};

#endif //OYUN_GAMERULES_H
