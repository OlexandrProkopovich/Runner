#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class Dog
{
private:
    float _x, _y;
    float _speed;
    float _gravity = 0.0;
    float _gravity_down = 5.0f;  
    float _gravity_up = -5.0f;  
    bool inGround = false;

    std::string _pathToDog;
    sf::Image _Dog_image;
    sf::Texture _Dog_texture;

    sf::Sprite _Sprite;
public:
    Dog(float x, float y, float speed, std::string pathToDog);
    void render(sf::RenderWindow& window);
    void animation(float& time, float& CurrentFrame);
    void jump();
    void move(float& time);
    void move_wasd();
    void applyGravity(float& time); 
    void deleteGravity();
    void Dog::setSpeed(float speed)
    {
        _speed = speed;
    }

public:
    sf::Vector2f pos();
    sf::FloatRect getGlobalBounds();
};

