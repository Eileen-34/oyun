#pragma once
#include "GameRules.h"
#include "rules.h" // Byte array for rules.png

using namespace sf;

// Constructor
GameRules::GameRules(const Font& font)
        : backButton("Back", font, Vector2f(120, 700), Vector2f(100, 50)) {
    // Load the background image from memory
    if (!backgroundTexture.loadFromMemory(assets_rules_png, assets_rules_png_len)) {
        throw std::runtime_error("Failed to load rules background image from memory!");
    }
    backgroundSprite.setTexture(backgroundTexture);

    /*
    // Load the background image from file
    if (!backgroundTexture.loadFromFile("/Users/03oymaka19/CLionProjects/oyun/assets/rules.png")) {
        throw std::runtime_error("Failed to load rules background image!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    */

    // Resizes the background image
    float scaleFactor = 0.6f;
    backgroundSprite.setScale(scaleFactor, scaleFactor);

    // Positions the background image at the top of the screen
    float windowWidth = 800;
    float imageWidth = backgroundSprite.getGlobalBounds().width;
    backgroundSprite.setPosition((windowWidth - imageWidth) / 2, 20);

    // Sets up the "Rules" text
    rulesText.setFont(font);
    rulesText.setString(
            "The rules:\n"
            "1. Rock wins against scissors.\n"
            "2. Paper wins against rock.\n"
            "3. Scissors win against paper.\n"
            "4. Round: Each game consists of six rounds.\n"
            "5. Scoring:\n"
            "- If it is a tie, neither player scores a point.\n"
            "- Otherwise, the winner of each round earns one point."
    );
    rulesText.setCharacterSize(30);
    rulesText.setFillColor(sf::Color::White);

    // Centers the "Rules" text on the screen
    FloatRect textBounds = rulesText.getLocalBounds();
    rulesText.setOrigin(textBounds.width / 2, textBounds.height / 2);
    rulesText.setPosition(120, 460); //
}

void GameRules::handleEvent(const Event& event, const RenderWindow& window) {
    backButton.handleEvent(event, window);
}

void GameRules::update(const RenderWindow& window) {
    backButton.update(window);
}

void GameRules::draw(RenderWindow& window) const {
    // Draws the background
    window.draw(backgroundSprite);

    // Draws the "Rules" text
    window.draw(rulesText);

    // Draws the "Back" button
    backButton.draw(window);
}

void GameRules::setOnBackClicked(std::function<void()> onClick) {
    backButton.setOnClick(onClick);
}
