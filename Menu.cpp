#include "Menu.h"

Menu::Menu(const sf::Font& font) {
    // Create buttons
    buttons.emplace_back("Play", font, sf::Vector2f(300, 300), sf::Vector2f(200, 50));      ///DONE
    buttons.emplace_back("Scores", font, sf::Vector2f(300, 400), sf::Vector2f(200, 50));   ///TODO
    buttons.emplace_back("Rules", font, sf::Vector2f(300, 500), sf::Vector2f(200, 50)); ///DONE
    buttons.emplace_back("About", font, sf::Vector2f(300, 600), sf::Vector2f(200, 50));      ///DONE
    buttons.emplace_back("Exit", font, sf::Vector2f(300, 700), sf::Vector2f(200, 50));       ///DONE
}

void Menu::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    for (auto& button : buttons) {
        button.handleEvent(event, window);
    }
}

void Menu::update(const sf::RenderWindow& window) {
    for (auto& button : buttons) {
        button.update(window);
    }
}

void Menu::draw(sf::RenderWindow& window) const {
    for (const auto& button : buttons) {
        button.draw(window);
    }
}

void Menu::setOnPlayClicked(std::function<void()> onClick) {
    buttons[0].setOnClick(onClick);
}

void Menu::setOnScoresClicked(std::function<void()> onClick) {
    buttons[1].setOnClick(onClick);
}

void Menu::setOnRulesClicked(std::function<void()> onClick) {
    buttons[2].setOnClick(onClick);
}

void Menu::setOnAboutClicked(std::function<void()> onClick) {
    buttons[3].setOnClick(onClick);
}

void Menu::setOnExitClicked(std::function<void()> onClick) {
    buttons[4].setOnClick(onClick);
}

// https://wrpsa.com/the-official-rules-of-rock-paper-scissors/
// https://www.rpsgame.org/random
// https://www.twoplayergames.org/game/rock-paper-scissors
