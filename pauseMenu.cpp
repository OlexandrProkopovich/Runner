#include "pauseMenu.h"


const std::string pathToButton1 = "../images/Buttons/Vector.png";
const std::string pathToButton2 = "../images/Buttons/Vector-1.png";
const std::string pathToFont = "../font/Maestroc.otf";

pauseMenu::pauseMenu(sf::RenderWindow& window, std::string pachToBackgroung, float x, float y)
    : _window(window), _pachToBackgroung(pachToBackgroung), _x(x), _y(y), button1(750, 300, 0, sf::Color::White, pathToFont, "", pathToButton1),
    button2(750, 500, 0, sf::Color::White, pathToFont, "", pathToButton2), ResumeRequested(false), QuitRequested(false)
{
    _backgroundImage.loadFromFile(_pachToBackgroung);
    _backgroundTexture.loadFromImage(_backgroundImage);
    _backgroundSprite.setTexture(_backgroundTexture);
    _backgroundSprite.setPosition(_x, _y);
    _backgroundSprite.setScale(1.07, 1.07);
}

void pauseMenu::render()
{
    _window.clear();
    _window.draw(_backgroundSprite);
    button1.render(_window);
    button2.render(_window);
    _window.display();
}

void pauseMenu::handleInput()
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
                ResumeRequested = true;
            }
            // Перевірте, чи миша знаходиться над текстом "Налаштування"
            else if (button2.getGlobalBounds().contains(mousePos))
            {
                QuitRequested = true;
            }
        }

    }
}

void pauseMenu::update()
{

}

bool pauseMenu::isResumeRequested() const {
    return ResumeRequested;
}
bool pauseMenu::isQuitRequested() const {
    return QuitRequested;
}
