#ifndef OYUN_MENU_H
#define OYUN_MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"

class Menu {
public:
    Menu(const sf::Font& font);

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;

    void setOnPlayClicked(std::function<void()> onClick);
    void setOnScoresClicked(std::function<void()> onClick);
    void setOnRulesClicked(std::function<void()> onClick);
    void setOnAboutClicked(std::function<void()> onClick);
    void setOnExitClicked(std::function<void()> onClick);

private:
    std::vector<Button> buttons;
};

#endif //OYUN_MENU_H
