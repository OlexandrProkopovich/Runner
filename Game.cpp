#include "Game.h"
#include "function.h"


const int WIDTH = 1920;
const int HEIGHT = 1080;
const int DOG_POSITION_X = 300;
const int DOG_POSITION_Y = 840;

const std::string pathToDog = "../images/Dogs/dog_set.png";
const std::string pathToSky = "../images/Sky/Sky.png";
const std::string pathToGround_down = "../images/Ground/Ground_down1.png";
const std::string pathToGround_up = "../images/Ground/Ground_up1.png";

const std::string pathToFont = "../font/Maestroc.otf";
const std::string pathToBeckgroundMenu = "../images/back/menu_background.png";
const std::string pathToPausedMenu = "../images/back/menu_background.png";
const std::string pathToButton1 = "../images/Buttons/PauseButton.png";

const std::string pathToPausedMenuBack = "../images/Buttons/Rectangle 81.png";

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Speedy paws"), dog(DOG_POSITION_X, DOG_POSITION_Y, 3.0, pathToDog), menu(window, pathToBeckgroundMenu, 0, 0),
button1(1800, 30, 4, sf::Color::White, pathToFont, "", pathToButton1), gameState(GameState::MENU), stoneSpawnInterval_downPlatform(sf::seconds(0.7)), stoneSpawnInterval_upPlatform(sf::seconds(0.8))

{
	initialize_ground(grounds_down, 3, WIDTH, pathToGround_down);
	initialize_ground(grounds_up, 3, WIDTH, pathToGround_up);
	initialize_sky(skies, 4, 1170, pathToSky);
	font.loadFromFile(pathToFont);
	view.setSize(WIDTH, HEIGHT);

	
}

void Game::run()
{
	while (window.isOpen())
	{
		switch (gameState)
		{
		case GameState::MENU:
			menu.handleInput();
			menu.update();
			menu.render();
			if (menu.isNewGameRequested())
			{
				gameState = PLAYING;
			} 
			
			break;

		case GameState::PLAYING:
			processInput();
			update();
			render();

			break;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}
	clear();
}

void Game::processInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		
	}
}

void Game::updateTotalDistance()
{
	float distanceDelta = (0 + dog.pos().x) / 100000.0f;

	totalDistance += distanceDelta;

	distanceText.setFont(font);  
	distanceText.setString( std::to_string(static_cast<int>(totalDistance)) + " m");
	distanceText.setCharacterSize(60);
	distanceText.setFillColor(sf::Color::White);
	distanceText.setPosition(window.getView().getCenter().x, 30);
}

void Game::update()
{
	stoneSpawner_down(stoneSpawnClock_downPlatform, stoneSpawnInterval_downPlatform, view, stones_downPlatform, 840);
	deleteStone(stones_downPlatform, stonesToRemove_downPlatform, view);
	stoneSpawner_up(stoneSpawnClock_upPlatform, stoneSpawnInterval_upPlatform, view, stones_upPlatform, 235);
	deleteStone(stones_upPlatform, stonesToRemove_upPlatform, view);
	
	
	col(stones_downPlatform, dog);
	col(stones_upPlatform, dog);

	sf::Time elapsed = clock.restart(); 
	float time = elapsed.asMicroseconds() / 2000.0f;

	view.setCenter(WIDTH / 2 + dog.pos().x - DOG_POSITION_X, HEIGHT / 2); 
	window.setView(view);
	

	dog.animation(time, CurrentFrame);   
	dog.move(time);
	//dog.move_wasd();
	dog.applyGravity(time);
	dog.jump();

	if (dog.pos().y <= 230 || dog.pos().y >= 840)
	{
		dog.deleteGravity();
	}

	dog.jump();

	plate_transfer(dog, grounds_down, grounds_up);
	sky_transfer(dog, skies);
	updateTotalDistance();
	button1.SetPosition(window.getView().getCenter().x + 800 , 30);
	
}

void Game::render() 
{
	window.clear(sf::Color::Cyan);
	render_ground(window, grounds_down);
	render_ground(window, grounds_up);
	render_sky(window, skies);
	
	window.draw(distanceText);
	button1.render(window);
	for (auto& stone : stones_downPlatform) {
		stone->render(window);
	}

	for (auto& stone : stones_upPlatform) {
		stone->render(window);
	}
	dog.render(window);
	window.display();
}

void Game::clear()
{
	for (auto& ground : grounds_down)
	{
		delete ground;
	}

	for (auto& ground : grounds_up)
	{
		delete ground;
	}

	for (auto& sky : skies)
	{
		delete sky;
	}
}