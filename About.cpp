#include "About.h"

About::About(const sf::Font& font)
        : backButton("Back to Menu", font, sf::Vector2f(300, 600), sf::Vector2f(200, 50)) {
    // Load the background image
    if (!backgroundTexture.loadFromFile("../assets/about_background.jpg")) {
        throw std::runtime_error("Failed to load about background image!");
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Resize the background image to make it smaller
    float scaleFactor = 0.5f; // Adjust this value to make the image smaller or larger
    backgroundSprite.setScale(scaleFactor, scaleFactor);

    // Position the background image at the top of the screen
    float windowWidth = 800; // Replace with your window width
    float imageWidth = backgroundSprite.getGlobalBounds().width;
    backgroundSprite.setPosition((windowWidth - imageWidth) / 2, 20); // 20 pixels from the top

    // Set up the "About" text
    aboutText.setFont(font);
    aboutText.setString(
            "\n\nAbout the Game"
            "\n\nThis game is developed by Aylin Oymak as a project "
            "\nsubmission for 'Programming in C++' taught by David "
            "\nHackbarth in summer term 2025 "
            "\nat Berlin School of Economics and Law. "
            "\n\nIt is meant for educational purposes only. "
            "\nPlease do not rely on it."
            "\n\n\n Have fun!"
    );
    aboutText.setCharacterSize(26);
    aboutText.setFillColor(sf::Color::White);

    // Center the "About" text on the screen
    sf::FloatRect textBounds = aboutText.getLocalBounds();
    aboutText.setOrigin(textBounds.width / 2, textBounds.height / 2);
    aboutText.setPosition(200, 250); // Center of window
    /*
    // Position the text below the background image
    float textX = (windowWidth - aboutText.getLocalBounds().width) / 2;
    float textY = backgroundSprite.getPosition().y + backgroundSprite.getGlobalBounds().height + 20; // 20 pixels below the image
    aboutText.setPosition(textX, textY);
     */
}

void About::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    backButton.handleEvent(event, window);
}

void About::update(const sf::RenderWindow& window) {
    backButton.update(window);
}

void About::draw(sf::RenderWindow& window) const {
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