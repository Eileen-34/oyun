#pragma once
#include "Button.h"

Button::Button(
        const std::string& text,
        const sf::Font& font,
        const sf::Vector2f& position,
        const sf::Vector2f& size)
        : defaultColor(sf::Color(51, 51, 51, 200)),
          hoverColor(sf::Color(255, 212, 57, 200)) {
    // Set up the button shape
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(defaultColor);
    shape.setOutlineThickness(2); // Add an outline
    shape.setOutlineColor(sf::Color::Transparent); // Outline color

    // Set up the button label
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(28);
    label.setFillColor(sf::Color::White);

    centerText();
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
    if (shape.getGlobalBounds().contains(mousePos)) {
        shape.setFillColor(hoverColor);
        shape.setOutlineColor(sf::Color::White); // Highlight outline on hover
    } else {
        shape.setFillColor(defaultColor);
        shape.setOutlineColor(sf::Color::Transparent); // Remove outline when not hovered
    }
}

void Button::draw(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(label);
}