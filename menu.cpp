#include "menu.h"


const std::string pathToButton = "../images/Buttons/playbuttOn.png";
const std::string pathToFont = "../font/Maestroc.otf";

Menu::Menu(sf::RenderWindow& window, std::string pachToBackgroung, float x, float y)
    : _window(window), _pachToBackgroung(pachToBackgroung), _x(x), _y(y), button1(750, 300, 60, sf::Color::White, pathToFont, "New Game", pathToButton),
    button2(750, 500, 60, sf::Color::White, pathToFont, "Settings", pathToButton), button3(750, 700, 60, sf::Color::White, pathToFont, "Quit", pathToButton),
    newGameRequested(false), settingsRequested(false), exitRequested(false)
{
    _backgroundImage.loadFromFile(_pachToBackgroung);
    _backgroundTexture.loadFromImage(_backgroundImage);
    _backgroundSprite.setTexture(_backgroundTexture);
    _backgroundSprite.setPosition(_x, _y);
    _backgroundSprite.setScale(1.07, 1.07);
}

void Menu::render()
{
    _window.clear();
    _window.draw(_backgroundSprite);
    button1.render(_window);
    button2.render(_window);
    button3.render(_window);
    _window.display();
}

void Menu::handleInput()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _window.close();
        }
        
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePos(sf::Mouse::getPosition(_window));

            // Перевірте, чи миша знаходиться над текстом "Нова гра"
            if (button1.getGlobalBounds().contains(mousePos))
            {
                newGameRequested = true;
            }
            // Перевірте, чи миша знаходиться над текстом "Налаштування"
            else if (button2.getGlobalBounds().contains(mousePos))
            {
                settingsRequested = true;
            }
            // Перевірте, чи миша знаходиться над текстом "Вихід"
            else if (button3.getGlobalBounds().contains(mousePos))
            {
                exitRequested = true;
            }
        }
        
    }
}

void Menu::update()
{

}

bool Menu::isNewGameRequested() const {
    return newGameRequested;
}
bool Menu::isSettingsRequested() const {
    return settingsRequested;
}
bool Menu::isExitRequested() const {
    return exitRequested;
}