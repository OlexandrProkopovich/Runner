#include <SFML/Graphics.hpp>


class button
{
private:
    float _width, _height;
    int _x_pos, _y_pos;
    int _text_size;

    std::string _pathToButton;
    sf::Image _buttonImage;
    sf::Texture _buttonTexture;
    sf::Sprite _buttonSprite;

    std::string _font_string;
    std::string _button_text;

    sf::Color _color_text;
    sf::Font _font;

    sf::Text _text;
public:
    button(float x_pos, float y_pos, float text_size, sf::Color color_text, std::string font, std::string button_text, std::string pathToButton);
    void render(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds() const;
    void SetPosition(float x, float y);
    
};