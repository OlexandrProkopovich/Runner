#include "ground.h"

Ground::Ground(float x, float y, std::string groundString) : _x(x), _y(y), _groundString(groundString)
{
	_groundImage.loadFromFile(_groundString);
	_groundTexture.loadFromImage(_groundImage);
	_groundSprite.setTexture(_groundTexture);
	_groundSprite.setPosition(_x, _y);
}

void Ground::render(sf::RenderWindow& window)
{
	window.draw(_groundSprite);
}
