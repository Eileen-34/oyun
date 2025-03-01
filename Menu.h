#ifndef OYUN_MENU_H
#define OYUN_MENU_H

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"

using namespace sf;

// Menu class represents the main menu screen of the game
class Menu {
public:
    // Constructor
    Menu(const Font& font);

    // Handles user input events
    void handleEvent(const Event& event, const RenderWindow& window);

    // Updates the state of the menu
    void update(const RenderWindow& window);

    // Draws the menu buttons to the window
    void draw(RenderWindow& window) const;

    // Callback functions for each button click
    void setOnPlayClicked(std::function<void()> onClick);
    void setOnRulesClicked(std::function<void()> onClick);
    void setOnAboutClicked(std::function<void()> onClick);
    void setOnExitClicked(std::function<void()> onClick);

private:
    // Vector to store the menu buttons
    std::vector<Button> buttons;
};

#endif //OYUN_MENU_H
