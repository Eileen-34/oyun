#pragma once
#include "About.h"
#include "about_background.h" // Byte array for about_background.jpg

using namespace sf;

About::About(const sf::Font& font)
        : backButton("Back", font, Vector2f(200, 700), sf::Vector2f(100, 50)) {
    // Load the background image from memory
    if (!backgroundTexture.loadFromMemory(assets_about_background_jpg, assets_about_background_jpg_len)) {
        throw std::runtime_error("Failed to load about background image from memory!");
    }
    backgroundSprite.setTexture(backgroundTexture);

    /*
    // Load the background image from file
    if (!backgroundTexture.loadFromFile("/Users/03oymaka19/CLionProjects/oyun/assets/about_background.jpg")) {
        throw std::runtime_error("Failed to load about background image!");
    }
    backgroundSprite.setTexture(backgroundTexture);
     */

    // Resize the background image
    float scaleFactor = 0.5f;
    backgroundSprite.setScale(scaleFactor, scaleFactor);

    // Position the background image at the top of the screen
    float windowWidth = 800;
    float imageWidth = backgroundSprite.getGlobalBounds().width;
    backgroundSprite.setPosition((windowWidth - imageWidth) / 2, 20);

    // Set up the "About" text
    aboutText.setFont(font);
    aboutText.setString(
            "\n\nAbout the Game:"
            "\n\nThis game was developed by Aylin Oymak "
            "\nas a project submission for "
            "\n'Programming in C++' course taught"
            "\nby David Hackbarth in summer term 2025 "
            "\nat Berlin School of Economics and Law. "
            "\n\nIt is meant for educational purposes only. "
            "\n\n\n Have fun!"
    );
    aboutText.setCharacterSize(30);
    aboutText.setFillColor(Color::White);

    // Center the "About" text on the screen
    sf::FloatRect textBounds = aboutText.getLocalBounds();
    aboutText.setOrigin(textBounds.width / 2, textBounds.height / 2);
    aboutText.setPosition(200, 250); // Center of window
}

void About::handleEvent(const sf::Event& event, const RenderWindow& window) {
    backButton.handleEvent(event, window);
}

void About::update(const RenderWindow& window) {
    backButton.update(window);
}

void About::draw(RenderWindow& window) const {
    // Draw the background
    window.draw(backgroundSprite);

    // Draw the "About" text
    window.draw(aboutText);

    // Draw the "Back to Menu" button
    backButton.draw(window);
}

void About::setOnBackClicked(std::function<void()> onClick) {
    backButton.setOnClick(onClick);
}
