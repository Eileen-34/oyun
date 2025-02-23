#ifndef OYUN_ABOUT_H
#define OYUN_ABOUT_H

#include <SFML/Graphics.hpp>
#include "Button.h"

class About {
public:
    About(const sf::Font& font);

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;

    void setOnBackClicked(std::function<void()> onClick);

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Text aboutText;
    Button backButton;
};

#endif //OYUN_ABOUT_H
