#pragma once
#include "GameOver.h"

// Constructor: Initializes the GameOver screen with text and buttons
GameOver::GameOver(const sf::Font& font)
        : gameOverText("Game Over\n\n", font, 50),
          finalScoreText("", font, 30),
          promptText("\n\nWhat a game! \n\nWould you like to play again?", font, 30),
          yesButton("Yes", font, sf::Vector2f(300, 450), sf::Vector2f(100, 50)),
          noButton("No", font, sf::Vector2f(450, 450), sf::Vector2f(100, 50)) {
    // Sets text colors
    gameOverText.setFillColor(sf::Color::White);
    finalScoreText.setFillColor(sf::Color::White);
    promptText.setFillColor(sf::Color::White);

    // Positions the text elements
    gameOverText.setPosition(300, 100);
    finalScoreText.setPosition(300, 150);
    promptText.setPosition(300, 250);
}

// Sets the final score text based on player and opponent scores
void GameOver::setFinalScore(int playerScore, int opponentScore) {
    finalScoreText.setString("\n\nFinal Score: \nYou: " + std::to_string(playerScore) +
                             " - Computer: " + std::to_string(opponentScore));
}

// Handles user input events (e.g., mouse clicks)
void GameOver::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    yesButton.handleEvent(event, window);
    noButton.handleEvent(event, window);
}

// Updates the state of the GameOver screen (e.g., button states)
void GameOver::update(const sf::RenderWindow& window) {
    yesButton.update(window);
    noButton.update(window);
}

// Draws the GameOver screen (text and buttons) to the window
void GameOver::draw(sf::RenderWindow& window) const {
    window.draw(gameOverText);
    window.draw(finalScoreText);
    window.draw(promptText);
    yesButton.draw(window);
    noButton.draw(window);
}

// Sets the callback function for the "Yes" button click
void GameOver::setOnYesClicked(std::function<void()> onClick) {
    yesButton.setOnClick(onClick);
}

// Sets the callback function for the "No" button click
void GameOver::setOnNoClicked(std::function<void()> onClick) {
    noButton.setOnClick(onClick);
}
