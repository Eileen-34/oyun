#ifndef OYUN_BUTTON_H
#define OYUN_BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

class Button {
public:
    Button(
            const std::string& text,
            const sf::Font& font,
            const sf::Vector2f& position,
            const sf::Vector2f& size);

    void setOnClick(std::function<void()> onClick);
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;

private:
    void centerText();

    sf::RectangleShape shape;
    sf::Text label;
    sf::Color defaultColor;
    sf::Color hoverColor;
    std::function<void()> onClick;
};

#endif //OYUN_BUTTON_H
