#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "button.h"
class Menu
{
public:
    Menu(sf::RenderWindow& window, std::string pachToBackgroung, float x, float y);
   
    void render();
    void handleInput();
    void update();
    
    bool isNewGameRequested() const;
    bool isSettingsRequested() const;
    bool isExitRequested() const;

private:
    float _x, _y;
    sf::RenderWindow& _window;
  
    std::string _pachToBackgroung;
    sf::Image _backgroundImage;
    sf::Texture _backgroundTexture;
    sf::Sprite _backgroundSprite;
    
    button button1;
    button button2;
    button button3;

    bool newGameRequested;
    bool settingsRequested;
    bool exitRequested;
};