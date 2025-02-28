#include "GameRules.h"

GameRules::GameRules(const sf::Font& font)
        : backButton("Back", font, sf::Vector2f(120, 700), sf::Vector2f(100, 50)) {
    // Load the background image
    if (!backgroundTexture.loadFromFile("/Users/03oymaka19/CLionProjects/oyun/assets/rules.png")) {
        throw std::runtime_error("Failed to load rules background image!");
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Resize the background image to make it smaller
    float scaleFactor = 0.6f;
    backgroundSprite.setScale(scaleFactor, scaleFactor);

    // Position the background image at the top of the screen
    float windowWidth = 800; // Replace with your window width
    float imageWidth = backgroundSprite.getGlobalBounds().width;
    backgroundSprite.setPosition((windowWidth - imageWidth) / 2, 20); // 20 pixels from the top

    // Set up the "Game Rules" text
    rulesText.setFont(font);
    rulesText.setString(
            "The rules are pretty straightforward.\n"
            "\n"
            "1. Rock wins against scissors.\n"
            "2. Scissors win against paper.\n"
            "3. Paper wins against rock. \n"
    );
    rulesText.setCharacterSize(30);
    rulesText.setFillColor(sf::Color::White);

    // Center the "Rules" text on the screen
    sf::FloatRect textBounds = rulesText.getLocalBounds();
    rulesText.setOrigin(textBounds.width / 2, textBounds.height / 2);
    rulesText.setPosition(120, 480); //
}

void GameRules::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    backButton.handleEvent(event, window);
}

void GameRules::update(const sf::RenderWindow& window) {
    backButton.update(window);
}

void GameRules::draw(sf::RenderWindow& window) const {
    // Draw the background
    window.draw(backgroundSprite);

    // Draw the "Game Rules" text
    window.draw(rulesText);

    // Draw the "Back to Menu" button
    backButton.draw(window);
}

void GameRules::setOnBackClicked(std::function<void()> onClick) {
    backButton.setOnClick(onClick);
}
