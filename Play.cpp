#include "Play.h"
#include <cstdlib>
#include <ctime>
/*
Play::Play(const sf::Font& font)
        : font(font), playerScore(0), opponentScore(0), currentRound(1),
          backToMenuButton("Back", font, sf::Vector2f(50, 700), sf::Vector2f(150, 50)),
          quitButton("Quit", font, sf::Vector2f(600, 700), sf::Vector2f(150, 50)),
          onGameOver(nullptr) { // Initialize onGameOver to nullptr
    // Seed the random number generator with the current time
    std::srand(std::time(nullptr));

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

    // Resize images to the same size (100x100)
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

    resultText.setFont(font);
    takeYourPickText.setFont(font); // Initialize "Take your pick" text

    // Set up "Take your pick" text
    takeYourPickText.setString("Take your pick");
    takeYourPickText.setCharacterSize(26);
    takeYourPickText.setFillColor(sf::Color::White);

    // Position the texts
    float windowWidth = 800;

    // Round text at the top center
    roundText.setPosition(350, 50);

    // Player label on the left
    playerLabelText.setString("Your Score");
    playerLabelText.setCharacterSize(30);
    playerLabelText.setPosition(50, 150);

    // Opponent label on the right
    opponentLabelText.setString("Computer's Score");
    opponentLabelText.setCharacterSize(30);
    opponentLabelText.setPosition(windowWidth - opponentLabelText.getLocalBounds().width - 200, 150);

    // Player and opponent scores in the middle, below the round text
    playerScoreText.setPosition((windowWidth / 2) - 200, 150);
    opponentScoreText.setPosition((windowWidth / 2) + 150, 150);

    // Result text below the scores
    resultText.setPosition(350, 300);

    // Position the text underneath the images
    takeYourPickText.setPosition((windowWidth - takeYourPickText.getLocalBounds().width) / 4, startY + imageSize + 20);

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

        // Handle button clicks
        backToMenuButton.handleEvent(event, window);
        quitButton.handleEvent(event, window);
    }
}

void Play::update(const sf::RenderWindow& window) {
    backToMenuButton.update(window);
    quitButton.update(window);
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

    // Draw choice texts
    window.draw(playerChoiceText);
    window.draw(opponentChoiceText);

    // Draw "Take your pick" text
    window.draw(takeYourPickText);

    // Draw buttons
    backToMenuButton.draw(window);
    quitButton.draw(window);
}

void Play::reset() {
    playerScore = 0;
    opponentScore = 0;
    currentRound = 1;

    // Clear choice texts and result text
    playerChoiceText.setString("");
    opponentChoiceText.setString("");
    resultText.setString("");

    updateTexts();
}

void Play::determineWinner(int playerChoice, int opponentChoice) {
    std::string playerChoiceStr;
    std::string computerChoiceStr;

    switch (playerChoice) {
        case 0: playerChoiceStr = "Rock"; break;
        case 1: playerChoiceStr = "Paper"; break;
        case 2: playerChoiceStr = "Scissors"; break;
    }

    switch (opponentChoice) {
        case 0: computerChoiceStr = "Rock"; break;
        case 1: computerChoiceStr = "Paper"; break;
        case 2: computerChoiceStr = "Scissors"; break;
    }

    playerChoiceText.setString("Your choice: \n" + playerChoiceStr);
    opponentChoiceText.setString("Computer's choice: \n" + computerChoiceStr);

    // Determine the winner
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

    if (currentRound > 5) {
        // Trigger game over callback
        if (onGameOver) { // Check if onGameOver is set
            onGameOver(playerScore, opponentScore);
        }
    }
}

void Play::setOnGameOver(std::function<void(int playerScore, int opponentScore)> onGameOver) {
    this->onGameOver = onGameOver;
}

void Play::updateTexts() {
    roundText.setString("Round " + std::to_string(currentRound));
    playerScoreText.setString(std::to_string(playerScore));
    opponentScoreText.setString(std::to_string(opponentScore));
}

void Play::setOnBackToMenuClicked(std::function<void()> onClick) {
    backToMenuButton.setOnClick(onClick);
}

void Play::setOnQuitClicked(std::function<void()> onClick) {
    quitButton.setOnClick(onClick);
}*/
#include "Play.h"
#include <cstdlib>
#include <ctime>

Play::Play(const sf::Font& font)
        : font(font), playerScore(0), opponentScore(0), currentRound(1),
          backToMenuButton("Back", font, sf::Vector2f(50, 700), sf::Vector2f(150, 50)),
          quitButton("Quit", font, sf::Vector2f(600, 700), sf::Vector2f(150, 50)),
          onGameOver(nullptr), isGameOverDelay(false), gameOverDelayDuration(1.0f) { // 1 seconds delay
    // Seed the random number generator with the current time
    std::srand(std::time(nullptr));

    // Load textures for rock, paper, scissors
    if (!rockTexture.loadFromFile("assets/rock.png") ||
        !paperTexture.loadFromFile("assets/paper.png") ||
        !scissorsTexture.loadFromFile("assets/scissors.png")) {
        throw std::runtime_error("Failed to load images!");
    }

    // Set up sprites
    rockSprite.setTexture(rockTexture);
    paperSprite.setTexture(paperTexture);
    scissorsSprite.setTexture(scissorsTexture);

    // Resize images to the same size (100x100)
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

    resultText.setFont(font);
    takeYourPickText.setFont(font); // Initialize "Take your pick" text

    // Set up "Take your pick" text
    takeYourPickText.setString("Take your pick");
    takeYourPickText.setCharacterSize(26);
    takeYourPickText.setFillColor(sf::Color::White);

    // Position the texts
    float windowWidth = 800;

    // Round text at the top center
    roundText.setPosition(350, 50);

    // Player label on the left
    playerLabelText.setString("Your Score");
    playerLabelText.setCharacterSize(30);
    playerLabelText.setPosition(50, 150);

    // Opponent label on the right
    opponentLabelText.setString("Computer's Score");
    opponentLabelText.setCharacterSize(30);
    opponentLabelText.setPosition(windowWidth - opponentLabelText.getLocalBounds().width - 200, 150);

    // Player and opponent scores in the middle, below the round text
    playerScoreText.setPosition((windowWidth / 2) - 200, 150);
    opponentScoreText.setPosition((windowWidth / 2) + 150, 150);

    // Result text below the scores
    resultText.setPosition(350, 300);

    // Position the text underneath the images
    takeYourPickText.setPosition((windowWidth - takeYourPickText.getLocalBounds().width) / 4, startY + imageSize + 20);

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

        // Handle button clicks
        backToMenuButton.handleEvent(event, window);
        quitButton.handleEvent(event, window);
    }
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

    // Draw choice texts
    window.draw(playerChoiceText);
    window.draw(opponentChoiceText);

    // Draw "Take your pick" text
    window.draw(takeYourPickText);

    // Draw buttons
    backToMenuButton.draw(window);
    quitButton.draw(window);
}

void Play::determineWinner(int playerChoice, int opponentChoice) {
    if (currentRound > 5) {
        // Prevent any actions if the game has ended after 5 rounds
        return;
    }

    std::string playerChoiceStr;
    std::string computerChoiceStr;

    switch (playerChoice) {
        case 0: playerChoiceStr = "Rock"; break;
        case 1: playerChoiceStr = "Paper"; break;
        case 2: playerChoiceStr = "Scissors"; break;
    }

    switch (opponentChoice) {
        case 0: computerChoiceStr = "Rock"; break;
        case 1: computerChoiceStr = "Paper"; break;
        case 2: computerChoiceStr = "Scissors"; break;
    }

    playerChoiceText.setString("Your choice: \n" + playerChoiceStr);
    opponentChoiceText.setString("Computer's choice: \n" + computerChoiceStr);

    // Determine the winner
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

    if (currentRound > 5) {
        // Start the game over delay
        isGameOverDelay = true;
        gameOverTimer.restart(); // Start the timer
    }
}
void Play::update(const sf::RenderWindow& window) {
    backToMenuButton.update(window);
    quitButton.update(window);

    // Check if the game over delay is active and the delay has passed
    if (isGameOverDelay && gameOverTimer.getElapsedTime().asSeconds() >= gameOverDelayDuration) {
        // Trigger game over callback after the delay
        if (onGameOver) {
            onGameOver(playerScore, opponentScore);
        }
        isGameOverDelay = false; // Reset the delay flag
    }
}

void Play::reset() {
    playerScore = 0;
    opponentScore = 0;
    currentRound = 1;
    isGameOverDelay = false; // Reset the delay flag

    // Clear choice texts and result text
    playerChoiceText.setString("");
    opponentChoiceText.setString("");
    resultText.setString("");

    updateTexts();
}

void Play::setOnGameOver(std::function<void(int playerScore, int opponentScore)> onGameOver) {
    this->onGameOver = onGameOver;
}

void Play::updateTexts() {
    roundText.setString("Round " + std::to_string(currentRound));
    playerScoreText.setString(std::to_string(playerScore));
    opponentScoreText.setString(std::to_string(opponentScore));
}

void Play::setOnBackToMenuClicked(std::function<void()> onClick) {
    backToMenuButton.setOnClick(onClick);
}

void Play::setOnQuitClicked(std::function<void()> onClick) {
    quitButton.setOnClick(onClick);
}
///TODO implement scores page.
