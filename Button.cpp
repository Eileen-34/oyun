#include "Button.h"

Button::Button(
        const std::string& text,
        const sf::Font& font,
        const sf::Vector2f& position,
        const sf::Vector2f& size)
        : defaultColor(sf::Color(70, 70, 70, 200)),
          hoverColor(sf::Color(100, 100, 100, 200)) {
    // Set up the button shape
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(defaultColor);

    // Set up the button label
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(26);
    label.setFillColor(sf::Color::White);

    centerText();
    /*
    // Center the text in the button
    sf::FloatRect textBounds = label.getLocalBounds();
    float textWidth = textBounds.width;
    float textHeight = textBounds.height;

    // Calculate the centered position
    float textX = position.x + (size.x - textWidth) / 2;
    float textY = position.y + (size.y - textHeight) / 2 - textBounds.top;

    label.setPosition(textX, textY);
    */
}

void Button::centerText() {
    sf::FloatRect textBounds = label.getLocalBounds();

    // Get the button's position and size
    sf::Vector2f buttonPosition = shape.getPosition();
    sf::Vector2f buttonSize = shape.getSize();

    // Calculate the centered position for the text
    float textX = buttonPosition.x + (buttonSize.x - textBounds.width) / 2 - textBounds.top;
    float textY = buttonPosition.y + (buttonSize.y - textBounds.height) / 2 - textBounds.top;

    label.setPosition(textX, textY);
}

void Button::setOnClick(std::function<void()> onClick) {
    this->onClick = onClick;
}

void Button::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (shape.getGlobalBounds().contains(mousePos) && onClick) {
            onClick();
        }
    }
}

void Button::update(const sf::RenderWindow& window) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    shape.setFillColor(shape.getGlobalBounds().contains(mousePos) ? hoverColor : defaultColor);
}

void Button::draw(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(label);
}