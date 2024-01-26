#include "dog.h"

Dog::Dog(float x, float y, float speed, std::string pathToDog) : _x(x), _y(y), _speed(speed), _pathToDog(pathToDog)
{
    _Dog_image.loadFromFile(_pathToDog);
    _Dog_texture.loadFromImage(_Dog_image);
    _Sprite.setTexture(_Dog_texture);
    _Sprite.setPosition(_x, _y);
}

void Dog::animation(float& time, float& CurrentFrame) {
    int frameInTexture = 6;
    CurrentFrame += time * 0.03;
    if (CurrentFrame >= frameInTexture) { CurrentFrame -= frameInTexture; }
    _Sprite.setTextureRect(sf::IntRect(128 * static_cast<int>(CurrentFrame), 0, 128, 69));
}

void Dog::render(sf::RenderWindow& window)
{
    window.draw(_Sprite);
}

void Dog::jump()
{
   
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            inGround = false;
            _gravity = _gravity_up;
            _Sprite.setScale(1, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            inGround = false;
            _gravity = _gravity_down;
            _Sprite.setScale(1, 1);
            _Sprite.setOrigin(0, 0);
        }
    
}

void Dog::move(float& time)
{
    float deltaTime = time * _speed;
    _Sprite.move(deltaTime, 0);
}

void Dog::applyGravity(float& time)
{  
    if(!inGround )
    {
        _Sprite.move(0, _gravity * time * 0.5);
    }
}

void Dog::deleteGravity() {
    inGround = true;
    _gravity = 0;
}

sf::Vector2f Dog::pos()
{
    return _Sprite.getPosition();
}

void Dog::move_wasd()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _Sprite.move(-1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _Sprite.move(1, 0);
    }
}

sf::FloatRect Dog::getGlobalBounds()
{
    return _Sprite.getGlobalBounds();
}


