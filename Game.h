#pragma once
#include <SFML/Graphics.hpp>
#include "dog.h"
#include "Sky.h"
#include "ground.h"
#include "menu.h"
#include "stone.h"

enum GameState
{
	MENU,
	PLAYING,
	PAUSED
};

class Game
{
public:
	Game();
	void run();
private:
	void processInput();
	void update();
	void render();
	void clear();
	void updateTotalDistance();

	GameState gameState;
	Menu menu;

	
	sf::Clock stoneSpawnClock_downPlatform;
	sf::Time stoneSpawnInterval_downPlatform; 
	std::vector<Stone*> stones_downPlatform;
	std::vector<Stone*> stonesToRemove_downPlatform;

	sf::Clock stoneSpawnClock_upPlatform;
	sf::Time stoneSpawnInterval_upPlatform;
	std::vector<Stone*> stones_upPlatform;
	std::vector<Stone*> stonesToRemove_upPlatform;


	sf::RenderWindow window;
	Dog dog;
	
	std::vector<Sky*> skies;
	std::vector<Ground*> grounds_down;
	std::vector<Ground*> grounds_up;

	button button1;

	sf::Clock clock;  
	sf::View view;
	sf::Font font;
	float CurrentFrame = 0;  
	float totalDistance = 0; 
	sf::Text distanceText;
	

};