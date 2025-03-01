#ifndef OYUN_GAMEOVER_H
#define OYUN_GAMEOVER_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;

// GameOver class represents the game over screen
class GameOver {
public:
    // Constructor: Initializes the GameOver screen with the given font
    GameOver(const Font& font);

    // Sets the final score text based on player and opponent scores
    void setFinalScore(int playerScore, int opponentScore);

    // Handles user input events (e.g., mouse clicks)
    void handleEvent(const Event& event, const RenderWindow& window);

    // Updates the state of the GameOver screen
    void update(const RenderWindow& window);

    // Draws the GameOver screen (text and buttons) to the window
    void draw(RenderWindow& window) const;

    // Callback function for the "Yes" button click
    void setOnYesClicked(std::function<void()> onClick);

    // Callback function for the "No" button click
    void setOnNoClicked(std::function<void()> onClick);

private:
    Text gameOverText;
    Text finalScoreText;
    Text promptText;
    Button yesButton;
    Button noButton;
};

#endif //OYUN_GAMEOVER_H
