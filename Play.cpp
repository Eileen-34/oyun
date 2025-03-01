#pragma once
#include "Play.h"
#include "rock.h" // Byte array for rock.png
#include "paper.h" // Byte array for paper.png
#include "scissors.h" // Byte array for scissors.png
#include <cstdlib>
#include <ctime>

//Constructor of the play screen
Play::Play(const sf::Font& font)
        : font(font), playerScore(0), opponentScore(0), currentRound(1),
          backToMenuButton("Back", font, sf::Vector2f(50, 700), sf::Vector2f(150, 50)),
          quitButton("Quit", font, sf::Vector2f(600, 700), sf::Vector2f(150, 50)),
          onGameOver(nullptr), isGameOverDelay(false), gameOverDelayDuration(1.0f) { // 1 seconds delay
    // Sets the random number generator with the current time
    std::srand(std::time(nullptr));

    if (!rockTexture.loadFromMemory(assets_rock_png, assets_rock_png_len) ||
        !paperTexture.loadFromMemory(assets_paper_png, assets_paper_png_len) ||
        !scissorsTexture.loadFromMemory(assets_scissors_png, assets_scissors_png_len)) {
        throw std::runtime_error("Failed to load images from memory!");
    }

    /*
    // Load textures for rock, paper, scissors
    if (!rockTexture.loadFromFile("/Users/03oymaka19/CLionProjects/oyun/assets/rock.png") ||
        !paperTexture.loadFromFile("/Users/03oymaka19/CLionProjects/oyun/assets/paper.png") ||
        !scissorsTexture.loadFromFile("/Users/03oymaka19/CLionProjects/oyun/assets/scissors.png")) {
        throw std::runtime_error("Failed to load images!");
    }
     */

    // Set up sprites
    rockSprite.setTexture(rockTexture);
    paperSprite.setTexture(paperTexture);
    scissorsSprite.setTexture(scissorsTexture);

    // Resize images to the same size
    float imageSize = 100.0f;
    rockSprite.setScale(imageSize / rockTexture.getSize().x, imageSize / rockTexture.getSize().y);
    paperSprite.setScale(imageSize / paperTexture.getSize().x, imageSize / paperTexture.getSize().y);
    scissorsSprite.setScale(imageSize / scissorsTexture.getSize().x, imageSize / scissorsTexture.getSize().y);

    // Position the sprites on the left side (player side)
    float startX = 50; // Left margin
    float startY = 400; // Vertical position
    float spacing = 150; // Horizontal spacing between images
    rockSprite.setPosition(startX, startY);
    paperSprite.setPosition(startX + spacing, startY);
    scissorsSprite.setPosition(startX + 2 * spacing, startY);

    // Initialize texts
    roundText.setFont(font);
    roundText.setCharacterSize(50);

    playerLabelText.setFont(font);
    opponentLabelText.setFont(font);
    playerScoreText.setFont(font);
    opponentScoreText.setFont(font);

    // Initialize choice texts
    playerChoiceText.setFont(font);
    playerChoiceText.setCharacterSize(28);
    playerChoiceText.setFillColor(sf::Color::White);
    playerChoiceText.setPosition(50, 250);

    opponentChoiceText.setFont(font);
    opponentChoiceText.setCharacterSize(28);
    opponentChoiceText.setFillColor(sf::Color::White);
    opponentChoiceText.setPosition(600, 250);

    // Set up font of the texts
    resultText.setFont(font);
    takeYourPickText.setFont(font);

    // Set up "Take your pick" text
    takeYourPickText.setString("Take your pick");
    takeYourPickText.setCharacterSize(26);
    takeYourPickText.setFillColor(sf::Color::White);

    float windowWidth = 800;

    // Round text position
    roundText.setPosition(350, 50);

    // Player label and position
    playerLabelText.setString("Your Score");
    playerLabelText.setCharacterSize(30);
    playerLabelText.setPosition(50, 150);

    // Opponent label and position
    opponentLabelText.setString("Computer's Score");
    opponentLabelText.setCharacterSize(30);
    opponentLabelText.setPosition(windowWidth - opponentLabelText.getLocalBounds().width - 200, 150);

    // Positions of player and opponent scores
    playerScoreText.setPosition((windowWidth / 2) - 200, 150);
    opponentScoreText.setPosition((windowWidth / 2) + 150, 150);

    // Result text position
    resultText.setPosition(350, 300);

    // Positions the text underneath the images
    takeYourPickText.setPosition((windowWidth - takeYourPickText.getLocalBounds().width) / 4, startY + imageSize + 20);

    // Updates the texts to display initial values
    updateTexts();
}

// Handles user input events
void Play::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (rockSprite.getGlobalBounds().contains(mousePos)) {
            int opponentChoice = rand() % 3;
            determineWinner(0, opponentChoice);
        } else if (paperSprite.getGlobalBounds().contains(mousePos)) {
            int opponentChoice = rand() % 3;
            determineWinner(1, opponentChoice);
        } else if (scissorsSprite.getGlobalBounds().contains(mousePos)) {
            int opponentChoice = rand() % 3;
            determineWinner(2, opponentChoice);
        }

        // Handle button clicks
        backToMenuButton.handleEvent(event, window);
        quitButton.handleEvent(event, window);
    }
}

// Draws the Play screen (text, sprites, and buttons) to the window
void Play::draw(sf::RenderWindow& window) const {
    window.draw(roundText);
    window.draw(playerLabelText);
    window.draw(opponentLabelText);
    window.draw(playerScoreText);
    window.draw(opponentScoreText);
    window.draw(resultText);

    window.draw(rockSprite);
    window.draw(paperSprite);
    window.draw(scissorsSprite);

    // Draw choice texts
    window.draw(playerChoiceText);
    window.draw(opponentChoiceText);

    // Draws "Take your pick" text
    window.draw(takeYourPickText);

    // Draw buttons
    backToMenuButton.draw(window);
    quitButton.draw(window);
}

void Play::determineWinner(int playerChoice, int opponentChoice) {
    if (currentRound > 5) {
        // Prevents any actions if the game has ended after 5 rounds
        return;
    }

    std::string playerChoiceStr;
    std::string computerChoiceStr;

    // Convert player's choice to a string
    switch (playerChoice) {
        case 0: playerChoiceStr = "Rock";
        break;
        case 1: playerChoiceStr = "Paper";
        break;
        case 2: playerChoiceStr = "Scissors";
        break;
    }

    // Converts computer's choice to a string
    switch (opponentChoice) {
        case 0: computerChoiceStr = "Rock";
        break;
        case 1: computerChoiceStr = "Paper";
        break;
        case 2: computerChoiceStr = "Scissors";
        break;
    }

    // Update the choice texts
    playerChoiceText.setString("Your choice: \n" + playerChoiceStr);
    opponentChoiceText.setString("Computer's choice: \n" + computerChoiceStr);

    // Determines the winner of a round based on the player's and computer's choices
    if (playerChoice == opponentChoice) {
        resultText.setString("It is a tie!");
    } else if ((playerChoice == 0 && opponentChoice == 2) ||
               (playerChoice == 1 && opponentChoice == 0) ||
               (playerChoice == 2 && opponentChoice == 1)) {
        playerScore++; // Player wins
        resultText.setString("You win this round!");
    } else {
        opponentScore++; // Computer wins
        resultText.setString("You lose this round!");
    }

    currentRound++;
    updateTexts();

    if (currentRound > 5) {
        // Start the game over delay
        isGameOverDelay = true;
        gameOverTimer.restart(); // Starts the timer
    }
}
void Play::update(const sf::RenderWindow& window) {
    backToMenuButton.update(window);
    quitButton.update(window);

    // Checks if the game over delay is active and the delay has passed
    if (isGameOverDelay && gameOverTimer.getElapsedTime().asSeconds() >= gameOverDelayDuration) {
        // Triggers game over callback after the delay
        if (onGameOver) {
            onGameOver(playerScore, opponentScore);
        }
        isGameOverDelay = false; // Reset the delay flag
    }
}

// Resets the game states
void Play::reset() {
    // Clears scores and round
    playerScore = 0;
    opponentScore = 0;
    currentRound = 1;

    // Resets the delay flag
    isGameOverDelay = false;

    // Clears choice texts and result text
    playerChoiceText.setString("");
    opponentChoiceText.setString("");
    resultText.setString("");

    updateTexts();
}

// Callback function to be executed when the game ends.
void Play::setOnGameOver(std::function<void(int playerScore, int opponentScore)> onGameOver) {
    this->onGameOver = onGameOver;
}

// Updates the displayed texts (round, player score, and opponent score).
void Play::updateTexts() {
    roundText.setString("Round " + std::to_string(currentRound));
    playerScoreText.setString(std::to_string(playerScore));
    opponentScoreText.setString(std::to_string(opponentScore));
}

// Callback functions for the "Back to Menu" and "Quit" button clicks.
void Play::setOnBackToMenuClicked(std::function<void()> onClick) {
    backToMenuButton.setOnClick(onClick);
}

void Play::setOnQuitClicked(std::function<void()> onClick) {
    quitButton.setOnClick(onClick);
}
