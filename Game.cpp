#pragma once

#include "Game.h"
#include "GameOver.h"
#include "game_background.h" // Byte array for game_background.jpg
#include "KenneyHighSquare.h" // Byte array for KenneyHighSquare.ttf

using namespace sf;

Game::Game()
        : window(VideoMode(800, 800), "Rock Paper Scissors Game"),
          menu(font),
          play(font),
          gameRules(font),
          about(font),
          gameOver(font),
          currentState(GameState::Menu) {

    // Load background image from memory
    if (!backgroundTexture.loadFromMemory(assets_game_background_jpg, assets_game_background_jpg_len)) {
        throw std::runtime_error("Failed to load background image from memory!");
    }
    backgroundSprite.setTexture(backgroundTexture);

    /*
    // Load background image from file
    if (!backgroundTexture.loadFromFile("/Users/03oymaka19/CLionProjects/oyun/assets/game_background.jpg")) {
        throw std::runtime_error("Failed to load background image!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    */

    // Center the background image at the top
    float windowWidth = window.getSize().x;
    float backgroundWidth = backgroundSprite.getLocalBounds().width;
    backgroundSprite.setPosition((windowWidth - backgroundWidth) / 2, -130);

    // Load font from memory
    if (!font.loadFromMemory(assets_KenneyHighSquare_ttf, assets_KenneyHighSquare_ttf_len)) {
        throw std::runtime_error("Failed to load font from memory!");
    }
    /*
    // Load font from file
    if (!font.loadFromFile("/Users/03oymaka19/CLionProjects/oyun/assets/KenneyHighSquare.ttf")) {
        throw std::runtime_error("Failed to load font!");
    }
    */

    // Set up menu button callbacks
    menu.setOnPlayClicked([this]() { currentState = GameState::Play; play.reset(); });
    menu.setOnRulesClicked([this]() { currentState = GameState::Rules; });
    menu.setOnAboutClicked([this]() { currentState = GameState::About; });
    menu.setOnExitClicked([this]() { currentState = GameState::Exit; });

    // Set up Play page button callbacks
    play.setOnBackToMenuClicked([this]() { currentState = GameState::Menu; });
    play.setOnQuitClicked([this]() { window.close(); });

    // Set up the "Back to Menu" button callback in the GameRules page
    gameRules.setOnBackClicked([this]() { currentState = GameState::Menu; }); // Switch back to Menu
    // Set up the "Back to Menu" button callback in the About page
    about.setOnBackClicked([this]() { currentState = GameState::Menu; }); // Switch back to Menu

    // Set up GameOver page button callbacks
    gameOver.setOnYesClicked([this]() {
        play.reset(); // Reset the Play state
        currentState = GameState::Play; // Switch to Play state
    });
    gameOver.setOnNoClicked([this]() { window.close(); });

    // Set up Play's game over callback
    play.setOnGameOver([this](int playerScore, int opponentScore) {
        gameOver.setFinalScore(playerScore, opponentScore); // Set final score
        currentState = GameState::GameOver; // Switch to GameOver state
    });
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents() {
    Event event{};
    while (window.pollEvent(event)) {
        // Close the window if the X button is clicked
        if (event.type == Event::Closed) {
            window.close();
        }
        // Close the window if the Esc key is pressed (only if the window wasn't already closed)
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
            window.close();
        }
    }

        // Handle events based on the current state
        switch (currentState) {
            case GameState::Menu:
                menu.handleEvent(event, window);
                break;
            case GameState::Play:
                play.handleEvent(event, window);
                break;
            case GameState::Rules:
                gameRules.handleEvent(event, window);
                break;
            case GameState::About:
                about.handleEvent(event, window);
                break;
            case GameState::GameOver:
                gameOver.handleEvent(event, window);
                break;
            default:
                break;
        }
    }


void Game::update() {
    // Update based on the current state
    switch (currentState) {
        case GameState::Menu:
            menu.update(window);
            break;
        case GameState::Play:
            play.update(window);
            break;
        case GameState::Rules:
            gameRules.update(window);
            break;
        case GameState::About:
            about.update(window);
            break;
        case GameState::Exit:
            window.close();
            break;
        case GameState::GameOver:
            gameOver.update(window);
            break;
        default:
            break;
    }
}

void Game::render() {
    window.clear();

    // Draw background only for the Menu state
    if (currentState == GameState::Menu) {
        window.draw(backgroundSprite);
    }

    // Draw based on the current state
    switch (currentState) {
        case GameState::Menu:
            menu.draw(window);
            break;
        case GameState::Play:
            play.draw(window);
            break;
        case GameState::Rules:
            gameRules.draw(window);
            break;
        case GameState::About:
            about.draw(window);
            break;
        case GameState::GameOver:
            gameOver.draw(window);
            break;
        default:
            break;
    }

    window.display();
}
