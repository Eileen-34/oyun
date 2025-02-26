#include "Play.h"
#include <cstdlib>
#include <ctime>

Play::Play(const sf::Font& font)
        : font(font), playerScore(0), opponentScore(0), currentRound(1) {
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Load textures for rock, paper, scissors
    if (!rockTexture.loadFromFile("../assets/rock.png") ||
        !paperTexture.loadFromFile("../assets/paper.png") ||
        !scissorsTexture.loadFromFile("../assets/scissors.png")) {
        throw std::runtime_error("Failed to load images!");
    }

    // Set up sprites
    rockSprite.setTexture(rockTexture);
    paperSprite.setTexture(paperTexture);
    scissorsSprite.setTexture(scissorsTexture);

    // Resize images to the same size (e.g., 100x100)
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
    playerLabelText.setFont(font);
    opponentLabelText.setFont(font);
    playerScoreText.setFont(font);
    opponentScoreText.setFont(font);
    resultText.setFont(font);
    takeYourPickText.setFont(font); // Initialize "Take your pick" text

    // Set up "Take your pick" text
    takeYourPickText.setString("Take your pick");
    takeYourPickText.setCharacterSize(24);
    takeYourPickText.setFillColor(sf::Color::White);

    // Position the texts
    float windowWidth = 800; // Replace with your window width
    float windowHeight = 800; // Replace with your window height

    // Round text at the top center
    roundText.setPosition((windowWidth - roundText.getLocalBounds().width) / 2, 50);

    // Player label on the left
    playerLabelText.setString("Your Score");
    playerLabelText.setPosition(50, 150);

    // Opponent label on the right
    opponentLabelText.setString("Opponent's Score");
    opponentLabelText.setPosition(windowWidth - opponentLabelText.getLocalBounds().width - 50, 150);

    // Player and opponent scores in the middle, below the round text
    playerScoreText.setPosition((windowWidth / 2) - 100, 200);
    opponentScoreText.setPosition((windowWidth / 2) + 50, 200);

    // Result text below the scores
    resultText.setPosition((windowWidth - resultText.getLocalBounds().width) / 2, 300);

    // Position "Take your pick" text underneath the images
    takeYourPickText.setPosition((windowWidth - takeYourPickText.getLocalBounds().width) / 2, startY + imageSize + 20);

    updateTexts();
}

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
    }
}

void Play::update(const sf::RenderWindow& window) {
    // Update logic if needed
}

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

    // Draw "Take your pick" text
    window.draw(takeYourPickText); // Ensure this is called
}

void Play::reset() {
    playerScore = 0;
    opponentScore = 0;
    currentRound = 1;
    updateTexts();
}

void Play::determineWinner(int playerChoice, int opponentChoice) {
    if (playerChoice == opponentChoice) {
        resultText.setString("It is a tie!");
    } else if ((playerChoice == 0 && opponentChoice == 2) ||
               (playerChoice == 1 && opponentChoice == 0) ||
               (playerChoice == 2 && opponentChoice == 1)) {
        playerScore++;
        resultText.setString("You win this round!");
    } else {
        opponentScore++;
        resultText.setString("You lose this round!");
    }

    currentRound++;
    updateTexts();

    if (currentRound > 3) {
        // End of game logic
        resultText.setString("Game Over! Final Score - You: " + std::to_string(playerScore) +
                             " Opponent: " + std::to_string(opponentScore));
        reset();
    }
}

void Play::updateTexts() {
    roundText.setString("Round " + std::to_string(currentRound));
    playerScoreText.setString(std::to_string(playerScore));
    opponentScoreText.setString(std::to_string(opponentScore));
}