#include "Sky.h"

Sky::Sky(float x, float y, std::string skyString) : _x(x), _y(y), _skyString(skyString)
{
	_skyImage.loadFromFile(_skyString);
	_skyTexture.loadFromImage(_skyImage);
	_skySprite.setTexture(_skyTexture);
	_skySprite.setScale(2.5, 2.5);
	_skySprite.setPosition(_x, _y);
}

void Sky::render(sf::RenderWindow& window)
{
	window.draw(_skySprite);
}