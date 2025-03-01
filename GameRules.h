#ifndef OYUN_GAMERULES_H
#define OYUN_GAMERULES_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

// This class represents the rules screen of the game
class GameRules {
public:
    //Constructor
    explicit GameRules(const sf::Font& font);

    // Handles user input events (e.g., mouse clicks)
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);

    // Updates the state of the GameRules screen (e.g., button states)
    void update(const sf::RenderWindow& window);

    // Draws the GameRules screen (background, text, and buttons) to the window
    void draw(sf::RenderWindow& window) const;

    // Sets the callback function for the "Back" button click
    void setOnBackClicked(std::function<void()> onClick);

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Text rulesText;
    Button backButton;
};

#endif //OYUN_GAMERULES_H
