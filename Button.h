#ifndef OYUN_BUTTON_H
#define OYUN_BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

using namespace sf;

class Button {
public:
    Button(
            const std::string& text,
            const Font& font,
            const Vector2f& position,
            const Vector2f& size);

    void setOnClick(std::function<void()> onClick);
    void handleEvent(const Event& event, const RenderWindow& window);
    void update(const RenderWindow& window);
    void draw(RenderWindow& window) const;

private:
    void centerText();

    RectangleShape shape;
    Text label;
    Color defaultColor;
    Color hoverColor;
    std::function<void()> onClick;
};

#endif //OYUN_BUTTON_H
