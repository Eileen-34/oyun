#include "Game.h"

Game::Game()
        : window(sf::VideoMode(800, 800), "Rock-Paper-Scissors"),
          menu(font),
          about(font),
          gameRules(font),
          currentState(GameState::Menu) {
    // Load background image
    if (!backgroundTexture.loadFromFile("../assets/bigger+logo.jpg")) {
        throw std::runtime_error("Failed to load background image!");
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Center the background image at the top
    float windowWidth = window.getSize().x;
    float backgroundWidth = backgroundSprite.getLocalBounds().width;
    backgroundSprite.setPosition((windowWidth - backgroundWidth) / 2, 0);

    // Load font
    if (!font.loadFromFile("assets/KenneyHighSquare.ttf")) {
        throw std::runtime_error("Failed to load font!");
    }

    // Set up menu button callbacks
    menu.setOnPlayClicked([this]() { currentState = GameState::Play; });
    menu.setOnScoresClicked([this]() { currentState = GameState::Scores; });
    menu.setOnRulesClicked([this]() { currentState = GameState::Rules; });
    menu.setOnAboutClicked([this]() { currentState = GameState::About; });
    menu.setOnExitClicked([this]() { currentState = GameState::Exit; });

    // Set up the "Back to Menu" button callback in the GameRules page
    gameRules.setOnBackClicked([this]() { currentState = GameState::Menu; }); // Switch back to Menu
    // Set up the "Back to Menu" button callback in the About page
    about.setOnBackClicked([this]() { currentState = GameState::Menu; }); // Switch back to Menu
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        // Handle events based on the current state
        switch (currentState) {
            case GameState::Menu:
                menu.handleEvent(event, window);
                break;
            case GameState::Rules:
                about.handleEvent(event, window);
                break;
            case GameState::About:
                about.handleEvent(event, window);
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    // Update based on the current state
    switch (currentState) {
        case GameState::Menu:
            menu.update(window);
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
        case GameState::Rules:
            gameRules.draw(window);
            break;
        case GameState::About:
            about.draw(window);
            break;
        default:
            break;
    }

    window.display();
}
