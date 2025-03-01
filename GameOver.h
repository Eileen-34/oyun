#ifndef OYUN_GAMEOVER_H
#define OYUN_GAMEOVER_H

#include <SFML/Graphics.hpp>
#include "Button.h"

// GameOver class: Represents the game over screen
class GameOver {
public:
    // Constructor: Initializes the GameOver screen with the given font
    GameOver(const sf::Font& font);

    // Sets the final score text based on player and opponent scores
    void setFinalScore(int playerScore, int opponentScore);

    // Handles user input events (e.g., mouse clicks)
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);

    // Updates the state of the GameOver screen (e.g., button states)
    void update(const sf::RenderWindow& window);

    // Draws the GameOver screen (text and buttons) to the window
    void draw(sf::RenderWindow& window) const;

    // callback function for the "Yes" button click
    void setOnYesClicked(std::function<void()> onClick);

    // callback function for the "No" button click
    void setOnNoClicked(std::function<void()> onClick);

private:
    sf::Text gameOverText;
    sf::Text finalScoreText;
    sf::Text promptText;
    Button yesButton;
    Button noButton;
};

#endif //OYUN_GAMEOVER_H
