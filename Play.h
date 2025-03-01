#ifndef OYUN_PLAY_H
#define OYUN_PLAY_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;

// Play class represents the gameplay screen
class Play {
public:
    // Constructor
    Play(const Font& font);

    // Handles user input events
    void handleEvent(const Event& event, const RenderWindow& window);

    // Updates the state of the play screen
    void update(const RenderWindow& window);

    // Draws the play screen
    void draw(RenderWindow& window) const;

    // Resets the game state
    void reset();

    // Callback functions for the back and Quit button click
    void setOnBackToMenuClicked(std::function<void()> onClick);
    void setOnQuitClicked(std::function<void()> onClick);

    // A method to set a callback for when the game is over
    void setOnGameOver(std::function<void(int playerScore, int opponentScore)> onGameOver);

private:
    // Fonts used for all the text components
    Font font;
    // Text components
    Text roundText;
    Text playerLabelText;
    Text opponentLabelText;
    Text playerScoreText;
    Text playerChoiceText;
    Text opponentChoiceText;
    Text opponentScoreText;
    Text resultText;
    Text takeYourPickText;

    // Textures and sprites for rock, paper, and scissors
    Texture rockTexture;
    Texture paperTexture;
    Texture scissorsTexture;
    Sprite rockSprite;
    Sprite paperSprite;
    Sprite scissorsSprite;

    // Buttons
    Button backToMenuButton;
    Button quitButton;

    // Game state variables
    int playerScore;
    int opponentScore;
    int currentRound;

    // Timer and delay for game ove
    Clock gameOverTimer; // Timer to track the delay
    bool isGameOverDelay;    // Flag to indicate if the delay is active
    float gameOverDelayDuration; // Duration of the delay in seconds

private:
    // Determines the winner
    void determineWinner(int playerChoice, int opponentChoice);
    // Updates the displayed texts (round, player score, and opponent score)
    void updateTexts();

    // Callback function for the game over event
    std::function<void(int playerScore, int opponentScore)> onGameOver; // Declare onGameOver
};

#endif //OYUN_PLAY_H
