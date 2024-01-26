#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "button.h"
class pauseMenu
{
public:
    pauseMenu(sf::RenderWindow& window, std::string pachToBackgroung, float x, float y);

    void render();
    void handleInput();
    void update();

    bool isResumeRequested() const;
    bool isQuitRequested() const;
private:
    float _x, _y;
    sf::RenderWindow& _window;

    std::string _pachToBackgroung;
    sf::Image _backgroundImage;
    sf::Texture _backgroundTexture;
    sf::Sprite _backgroundSprite;

    button button1;
    button button2;

    bool ResumeRequested;
    bool QuitRequested;
};