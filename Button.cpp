#pragma once
#include "Button.h"

using namespace sf;

Button::Button(
        const std::string& text,
        const Font& font,
        const Vector2f& position,
        const Vector2f& size)
        : defaultColor(Color(51, 51, 51, 200)),
          hoverColor(Color(255, 212, 57, 200)) {
    // Set up the button shape
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(defaultColor);
    shape.setOutlineThickness(2); // Add an outline
    shape.setOutlineColor(Color::Transparent); // Outline color

    // Set up the button label
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(28);
    label.setFillColor(Color::White);

    centerText();
}

void Button::centerText() {
    FloatRect textBounds = label.getLocalBounds();

    // Get the button's position and size
    Vector2f buttonPosition = shape.getPosition();
    Vector2f buttonSize = shape.getSize();

    // Calculate the centered position for the text
    float textX = buttonPosition.x + (buttonSize.x - textBounds.width) / 2 - textBounds.top;
    float textY = buttonPosition.y + (buttonSize.y - textBounds.height) / 2 - textBounds.top;

    label.setPosition(textX, textY);
}

void Button::setOnClick(std::function<void()> onClick) {
    this->onClick = onClick;
}

void Button::handleEvent(const Event& event, const RenderWindow& window) {
    if (event.type == Event::MouseButtonPressed) {
        Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
        if (shape.getGlobalBounds().contains(mousePos) && onClick) {
            onClick();
        }
    }
}

void Button::update(const RenderWindow& window) {
    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
    if (shape.getGlobalBounds().contains(mousePos)) {
        shape.setFillColor(hoverColor);
        shape.setOutlineColor(Color::White); // Highlight outline on hover
    } else {
        shape.setFillColor(defaultColor);
        shape.setOutlineColor(Color::Transparent); // Remove outline when not hovered
    }
}

void Button::draw(RenderWindow& window) const {
    window.draw(shape);
    window.draw(label);
}