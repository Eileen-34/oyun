#ifndef OYUN_GAMEOVER_H
#define OYUN_GAMEOVER_H

#include <SFML/Graphics.hpp>
#include "Button.h"

class GameOver {
public:
    GameOver(const sf::Font& font);

    void setFinalScore(int playerScore, int opponentScore);
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;

    void setOnYesClicked(std::function<void()> onClick);
    void setOnNoClicked(std::function<void()> onClick);

private:
    sf::Text gameOverText;
    sf::Text finalScoreText;
    sf::Text promptText;
    Button yesButton;
    Button noButton;
};

#endif //OYUN_GAMEOVER_H
