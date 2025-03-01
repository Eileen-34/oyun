#ifndef OYUN_GAMERULES_H
#define OYUN_GAMERULES_H

#include <SFML/Graphics.hpp>
#include "Button.h"

class GameRules {
public:
    explicit GameRules(const sf::Font& font);

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;

    void setOnBackClicked(std::function<void()> onClick);

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Text rulesText;
    Button backButton;
};

#endif //OYUN_GAMERULES_H
