#pragma once
#include <SFML/Graphics.hpp>
#include <string>

const std::string pathsToStones[] = {
		"../images/stones/Group 26.png",
		"../images/stones/Group 27.png",
		"../images/stones/Group 28.png",
		"../images/stones/Group 29.png",
		"../images/stones/Group 30.png",
		"../images/stones/Group 31.png",
		"../images/stones/stone.png",
		"../images/stones/stone2.png",
		"../images/stones/stone3.png"
};

class Stone
{
private:
	float _x, _y;

	std::string _stoneString;
	sf::Image _stoneImage;
	sf::Texture _stoneTexture;
	sf::Sprite _stoneSprite;
	std::vector<Stone> _stones;

public:
	Stone(float x, float y, std::string stoneString);
	void render(sf::RenderWindow& window);
	sf::Vector2f pos() const;
	sf::FloatRect getGlobalBounds();
	void makeRotation()
	{
		_stoneSprite.setRotation(180);
	}
};