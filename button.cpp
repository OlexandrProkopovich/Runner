#include "button.h"

button::button(float x_pos, float y_pos, float text_size, sf::Color color_text, std::string font, std::string button_text, std::string pathToButton) :  _x_pos(x_pos),
_y_pos(y_pos), _text_size(text_size), _color_text(color_text), _font_string(font), _button_text(button_text), _pathToButton(pathToButton)
{
    _buttonImage.loadFromFile(_pathToButton);
    _buttonTexture.loadFromImage(_buttonImage);
    _buttonSprite.setTexture(_buttonTexture);
    _buttonSprite.setScale(1.5, 1.5);
    _buttonSprite.setPosition(_x_pos, _y_pos);

    _font.loadFromFile(_font_string);

    _text.setString(button_text);
    _text.setFont(_font);
    _text.setCharacterSize(_text_size);

    // Визначте розміри тексту
    sf::FloatRect textBounds = _text.getLocalBounds();

    // Розмістіть текст по центру спрайта
    float textPosX = _x_pos + (_buttonSprite.getLocalBounds().width - textBounds.width) / 2.0f + 70;
    float textPosY = _y_pos + (_buttonSprite.getLocalBounds().height - textBounds.height) / 2.0f;

    _text.setPosition(textPosX, textPosY);
    _text.setFillColor(color_text);

}

void button::render(sf::RenderWindow& window)
{
    window.draw(_buttonSprite);
    window.draw(_text);
}

sf::FloatRect button::getGlobalBounds() const
{
    return _buttonSprite.getGlobalBounds();
}

void button::SetPosition(float x, float y)
{
    sf::FloatRect textBounds = _text.getLocalBounds();
    _buttonSprite.setPosition(x, y);
    _text.setPosition(x, y);
}