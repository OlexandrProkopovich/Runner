#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Sky
{
private:
	float _x, _y;
	std::string _skyString;
	sf::Image _skyImage;
	sf::Texture _skyTexture;
	sf::Sprite _skySprite;
public:
	Sky(float x, float y, std::string skyString);
	void render(sf::RenderWindow& window);
	sf::Vector2f pos()
	{
		return _skySprite.getPosition();
	}
	void Sky::setPos(float x, float y)
	{
		// Set the position of the ground sprite
		_skySprite.setPosition(x, y);
	}

	float Sky::getWidth() const
	{
		// Get the width of the ground sprite
		return _skySprite.getGlobalBounds().width;
	}
};