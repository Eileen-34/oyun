#ifndef OYUN_PLAY_H
#define OYUN_PLAY_H

#include <SFML/Graphics.hpp>
#include "Button.h"

class Play {
public:
    Play(const sf::Font& font);

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;

    void reset();

    void setOnBackToMenuClicked(std::function<void()> onClick);
    void setOnQuitClicked(std::function<void()> onClick);

private:
    sf::Font font;
    sf::Text roundText;
    sf::Text playerLabelText;
    sf::Text opponentLabelText;
    sf::Text playerScoreText;
    sf::Text opponentScoreText;
    sf::Text resultText;
    sf::Text takeYourPickText;

    sf::Texture rockTexture;
    sf::Texture paperTexture;
    sf::Texture scissorsTexture;
    sf::Sprite rockSprite;
    sf::Sprite paperSprite;
    sf::Sprite scissorsSprite;

    Button backToMenuButton;
    Button quitButton;

    int playerScore;
    int opponentScore;
    int currentRound;

    void determineWinner(int playerChoice, int opponentChoice);
    void updateTexts();
};

#endif //OYUN_PLAY_H
