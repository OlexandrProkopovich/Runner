#include <SFML/Graphics.hpp>
#include "ground.h"
#include "Sky.h"
#include <vector>

void initialize_ground(std::vector<Ground*>& grounds, int count, int WIDTH, std::string pathToGround_down)
{
	for (int i = 0; i < count; i++)
	{
		Ground* newGround = new Ground(i * WIDTH, 0, pathToGround_down);
		grounds.push_back(newGround);
	}
}

void initialize_sky(std::vector<Sky*>& skies, int count, int WIDTH, std::string pathToGround_down)
{
	for (int i = 0; i < count; i++)
	{
		Sky* newGround = new Sky(i * WIDTH, 167, pathToGround_down);
		skies.push_back(newGround);
	}
}

void render_sky(sf::RenderWindow& window, std::vector<Sky*>& skies)
{
	for (auto& sky : skies)
	{
		sky->render(window);
	}
}

void render_ground(sf::RenderWindow& window, std::vector<Ground*>& grounds)
{
	for (auto& ground : grounds)
	{
		ground->render(window);
	}

}

void sky_transfer(Dog& dog, std::vector<Sky*>& skies)
{
	if (dog.pos().x >= skies[2]->pos().x)
	{
		Sky* firstSky = skies.front();
		skies.erase(skies.begin());
		firstSky->setPos(skies.back()->pos().x + firstSky->getWidth(), 167);
		skies.push_back(firstSky);
	}
}

void plate_transfer(Dog& dog, std::vector<Ground*>& grounds_down, std::vector<Ground*>& grounds_up)
{
	if (dog.pos().x >= grounds_down[2]->pos().x)
	{
		Ground* firstGround_down = grounds_down.front();
		grounds_down.erase(grounds_down.begin());
		firstGround_down->setPos(grounds_down.back()->pos().x + firstGround_down->getWidth(), 0);
		grounds_down.push_back(firstGround_down);

		Ground* firstGround_up = grounds_up.front();
		grounds_up.erase(grounds_up.begin());
		firstGround_up->setPos(grounds_up.back()->pos().x + firstGround_up->getWidth(), 0);
		grounds_up.push_back(firstGround_up);
	}
}

void stoneSpawner_down(sf::Clock& stoneSpawnClock, sf::Time stoneSpawnInterval, sf::View view, std::vector<Stone*>& stones, float Y)
{
	if (stoneSpawnClock.getElapsedTime() > stoneSpawnInterval)
	{
		// Randomly select a stone path from pathsToStones array
		std::string randomStonePath = pathsToStones[std::rand() % (sizeof(pathsToStones) / sizeof(pathsToStones[0]))];

		// Randomly set the X position for the stone
		float randomX = static_cast<float>((view.getCenter().x + 1920) + std::rand() % static_cast<int>(((view.getCenter().x + 3840) - (view.getCenter().x + 1920) + 1))); // Adjust the range as needed

		// Create a new stone object and add it to the vector
		Stone* newStone = new Stone(randomX, Y, randomStonePath);
		stones.push_back(newStone);

		// Reset the timer
		stoneSpawnClock.restart();
	}
}

void stoneSpawner_up(sf::Clock& stoneSpawnClock, sf::Time stoneSpawnInterval, sf::View view, std::vector<Stone*>& stones, float Y)
{
	if (stoneSpawnClock.getElapsedTime() > stoneSpawnInterval)
	{
		// Randomly select a stone path from pathsToStones array
		std::string randomStonePath = pathsToStones[std::rand() % (sizeof(pathsToStones) / sizeof(pathsToStones[0]))];

		// Randomly set the X position for the stone
		float randomX = static_cast<float>((view.getCenter().x + 1920) + std::rand() % static_cast<int>(((view.getCenter().x + 3840) - (view.getCenter().x + 1920) + 1))); // Adjust the range as needed

		// Create a new stone object and add it to the vector
		Stone* newStone = new Stone(randomX, Y, randomStonePath);
		newStone->makeRotation();
		stones.push_back(newStone);

		// Reset the timer
		stoneSpawnClock.restart();
	}
}

void deleteStone(std::vector<Stone*>& stones, std::vector<Stone*>& stonesToRemove, sf::View view)
{
	stones.erase(std::remove_if(stones.begin(), stones.end(), [view](Stone* stone) {
		return stone->pos().x + 200 < view.getCenter().x - 960;
		}), stones.end());

	// Видаліть камені, які були видалені
	for (auto& stone : stonesToRemove) {
		delete stone;
	}
	stonesToRemove.clear();
}

bool checkCollisionWithStone( std::vector<Stone*>& down_stones,  Dog& dog)
{
	sf::FloatRect dogBounds = dog.getGlobalBounds();

	for (auto& stone : down_stones)
	{
		sf::FloatRect stoneBounds = stone->getGlobalBounds();

		if (dogBounds.intersects(stoneBounds))
		{
			// Колізія відбулась
			return true;
		}
	}

	// Колізія не відбулась
	return false;
}

void col( std::vector<Stone*>& stones, Dog& dog)
{
	if (checkCollisionWithStone(stones, dog))
	{
		dog.setSpeed(0);
	}
}