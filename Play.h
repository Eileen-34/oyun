#ifndef OYUN_PLAY_H
#define OYUN_PLAY_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

// Play class represents the gameplay screen
class Play {
public:
    // Constructor
    Play(const sf::Font& font);

    // Handles user input events
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);

    // Updates the state of the play screen
    void update(const sf::RenderWindow& window);

    // Draws the play screen
    void draw(sf::RenderWindow& window) const;

    // Resets the game state
    void reset();

    // Callback functions for the back and Quit button click
    void setOnBackToMenuClicked(std::function<void()> onClick);
    void setOnQuitClicked(std::function<void()> onClick);

    // A method to set a callback for when the game is over
    void setOnGameOver(std::function<void(int playerScore, int opponentScore)> onGameOver);

private:
    // Fonts used for all the text components
    sf::Font font;
    // Text components
    sf::Text roundText;
    sf::Text playerLabelText;
    sf::Text opponentLabelText;
    sf::Text playerScoreText;
    sf::Text playerChoiceText;
    sf::Text opponentChoiceText;
    sf::Text opponentScoreText;
    sf::Text resultText;
    sf::Text takeYourPickText;

    // Textures and sprites for rock, paper, and scissors
    sf::Texture rockTexture;
    sf::Texture paperTexture;
    sf::Texture scissorsTexture;
    sf::Sprite rockSprite;
    sf::Sprite paperSprite;
    sf::Sprite scissorsSprite;

    // Buttons
    Button backToMenuButton;
    Button quitButton;

    // Game state variables
    int playerScore;
    int opponentScore;
    int currentRound;

    // Timer and delay for game ove
    sf::Clock gameOverTimer; // Timer to track the delay
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
