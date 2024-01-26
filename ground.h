#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Ground {
private:
    float _x, _y;
    std::string _groundString;
    sf::Image _groundImage;
    sf::Texture _groundTexture;
    sf::Sprite _groundSprite;
    std::vector<Ground*> grounds;
    bool _stonesSpawned = false;  // Додавання флагу для визначення, чи камені вже спавнені

public:
    Ground(float x, float y, std::string groundString);
    void render(sf::RenderWindow& window);
    sf::Vector2f pos()
    {
        return _groundSprite.getPosition();
    }
    void Ground::setPos(float x, float y)
    {
        // Set the position of the ground sprite
        _groundSprite.setPosition(x, y);
    }

    float Ground::getWidth() const
    {
        // Get the width of the ground sprite
        return _groundSprite.getGlobalBounds().width;
    }

    bool hasStones() const
    {
        // Перевіряємо, чи камені вже спавнені
        return _stonesSpawned;
    }

    void setStonesSpawned(bool spawned)
    {
        // Встановлюємо флаг спавнення каменів
        _stonesSpawned = spawned;
    }
  

};