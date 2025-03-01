#pragma once
#include "Menu.h"

using namespace sf;

// Constructor intitializes the menu with the font asset
Menu::Menu(const Font& font) {
    // Creates and positions the buttons on the menu screen
    buttons.emplace_back("Play", font, Vector2f(300, 300), Vector2f(200, 50));
    buttons.emplace_back("Rules", font, Vector2f(300, 400), Vector2f(200, 50));
    buttons.emplace_back("About", font, Vector2f(300, 500), Vector2f(200, 50));
    buttons.emplace_back("Exit", font, Vector2f(300, 600), Vector2f(200, 50));
}

// Handles user input
void Menu::handleEvent(const Event& event, const RenderWindow& window) {
    for (auto& button : buttons) {
        button.handleEvent(event, window);
    }
}

// Updates the button states of the menu
void Menu::update(const RenderWindow& window) {
    for (auto& button : buttons) {
        button.update(window);
    }
}

// Draws the menu buttons to the window
void Menu::draw(RenderWindow& window) const {
    for (const auto& button : buttons) {
        button.draw(window);
    }
}

// Callback functions for each button click
void Menu::setOnPlayClicked(std::function<void()> onClick) {
    buttons[0].setOnClick(onClick);
}

void Menu::setOnRulesClicked(std::function<void()> onClick) {
    buttons[1].setOnClick(onClick);
}

void Menu::setOnAboutClicked(std::function<void()> onClick) {
    buttons[2].setOnClick(onClick);
}

void Menu::setOnExitClicked(std::function<void()> onClick) {
    buttons[3].setOnClick(onClick);
}
