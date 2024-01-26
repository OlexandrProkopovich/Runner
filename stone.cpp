#include "stone.h"

Stone::Stone(float x, float y, std::string stoneString) : _x(x), _y(y), _stoneString(stoneString)
{
	_stoneImage.loadFromFile(_stoneString);
	_stoneTexture.loadFromImage(_stoneImage);
	_stoneSprite.setTexture(_stoneTexture);
	_stoneSprite.setPosition(_x, _y);
}

void Stone::render(sf::RenderWindow& window)
{
	window.draw(_stoneSprite);
}

sf::Vector2f Stone::pos() const
{
	return _stoneSprite.getPosition();
}

sf::FloatRect Stone::getGlobalBounds()
{
	return _stoneSprite.getGlobalBounds();
}
