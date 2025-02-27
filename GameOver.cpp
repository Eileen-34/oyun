#include "GameOver.h"

GameOver::GameOver(const sf::Font& font)
        : gameOverText("Game Over!", font, 40),
          finalScoreText("", font, 30),
          promptText("Another game?", font, 30),
          yesButton("Yes", font, sf::Vector2f(300, 400), sf::Vector2f(100, 50)),
          noButton("No", font, sf::Vector2f(450, 400), sf::Vector2f(100, 50)) {
    gameOverText.setFillColor(sf::Color::White);
    finalScoreText.setFillColor(sf::Color::White);
    promptText.setFillColor(sf::Color::White);

    gameOverText.setPosition(300, 100);
    finalScoreText.setPosition(300, 150);
    promptText.setPosition(300, 250);
}

void GameOver::setFinalScore(int playerScore, int opponentScore) {
    finalScoreText.setString("Final Score: \nYou: " + std::to_string(playerScore) +
                             " - Computer: " + std::to_string(opponentScore));
}

void GameOver::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    yesButton.handleEvent(event, window);
    noButton.handleEvent(event, window);
}

void GameOver::update(const sf::RenderWindow& window) {
    yesButton.update(window);
    noButton.update(window);
}

void GameOver::draw(sf::RenderWindow& window) const {
    window.draw(gameOverText);
    window.draw(finalScoreText);
    window.draw(promptText);
    yesButton.draw(window);
    noButton.draw(window);
}

void GameOver::setOnYesClicked(std::function<void()> onClick) {
    yesButton.setOnClick(onClick);
}

void GameOver::setOnNoClicked(std::function<void()> onClick) {
    noButton.setOnClick(onClick);
}