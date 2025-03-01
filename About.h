#ifndef OYUN_ABOUT_H
#define OYUN_ABOUT_H

#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;

class About {
public:
    About(const Font& font);

    void handleEvent(const Event& event, const sf::RenderWindow& window);
    void update(const RenderWindow& window);
    void draw(RenderWindow& window) const;

    void setOnBackClicked(std::function<void()> onClick);

private:
    Texture backgroundTexture;
    Sprite backgroundSprite;
    Text aboutText;
    Button backButton;
};

#endif //OYUN_ABOUT_H
