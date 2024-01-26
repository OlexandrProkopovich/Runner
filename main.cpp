#include "Game.h"

int main()
{
	Game game;
	game.run();
	return 0;
}
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <string>
//#include "dog.h"
//#include "ground.h"
//#include "Sky.h"
//#include "stone.h"
//
//const int WIDTH = 1920;
//const int HEIGHT = 1080;
//const std::string pathToDog = "../images/dogs/dog_set.png";
//const std::string pathToGround_down = "../images/back1.png";
//const std::string pathToGround_up = "../images/back2.png";
//const std::string pathToSky = "../images/Sky.png";
//
//const std::string pathToStone1 = "../images/stones/Group 26.png";
//const std::string pathToStone2 = "../images/stones/Group 27.png";
//const std::string pathToStone3 = "../images/stones/Group 28.png";
//const std::string pathToStone4 = "../images/stones/Group 29.png";
//const std::string pathToStone5 = "../images/stones/Group 30.png";
//const std::string pathToStone6 = "../images/stones/Group 31.png";
//const std::string pathToStone7 = "../images/stones/stone.png";
//const std::string pathToStone8 = "../images/stones/stone2.png";
//const std::string pathToStone9 = "../images/stones/stone3.png";
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Speede Paws");
//
//    Dog dog(WIDTH / 2, 700, 3.0, pathToDog);
//
//    std::vector<Ground*> groundsVector;
//    std::vector<Ground*> groundsVector_up;
//    std::vector<Sky*> skysVector;
//
//    for (int i = -1; i < 2; i++)
//    {
//        Ground* newGround = new Ground(i * WIDTH, 140, pathToGround_down);
//        groundsVector.push_back(newGround);
//    }
//
//    for (int i = -1; i < 2; i++)
//    {
//        Ground* newGround = new Ground(i * WIDTH, -140, pathToGround_up);
//        groundsVector_up.push_back(newGround);
//    }
//
//    for (int i = -1; i < 2; i++)
//    {
//        Sky* newSky = new Sky(i * WIDTH, 80, pathToSky);
//        skysVector.push_back(newSky);
//    }
//
//    Sky sky(0, 0, pathToSky);
//    sf::View view;
//    view.setSize(WIDTH, HEIGHT);
//
//
//    float CurrentFrame = 0;  // ігровий час
//    sf::Clock clock;
//
//    while (window.isOpen())
//    {
//        float time = clock.getElapsedTime().asMicroseconds();
//        clock.restart();
//        time /= 2000;
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
        /*if (dog.pos().x >= groundsVector_up[2]->pos().x)
        {
            Ground* firstGround = groundsVector_up.front();
            groundsVector_up.erase(groundsVector_up.begin());
            firstGround->setPos(groundsVector_up.back()->pos().x + firstGround->getWidth() - 1, -140);
            groundsVector_up.push_back(firstGround);
        }*/
//
//        if (dog.pos().x >= groundsVector[2]->pos().x)
//        {
//            Ground* firstGround = groundsVector.front();
//            groundsVector.erase(groundsVector.begin());
//            firstGround->setPos(groundsVector.back()->pos().x + firstGround->getWidth() - 1, 140);
//            groundsVector.push_back(firstGround);
//        }
//
//        if (dog.pos().x >= skysVector[2]->pos().x)
//        {
//            Sky* firstSky = skysVector.front();
//            skysVector.erase(skysVector.begin());
//            firstSky->setPos(skysVector.back()->pos().x + firstSky->getWidth() - 1, 80);
//            skysVector.push_back(firstSky);
//        }
//        dog.move(time);
//        dog.animation(time, CurrentFrame);
        /*dog.applyGravity(time);

        if (dog.pos().y <= 254 || dog.pos().y >= 740)
        {
            dog.deleteGravity();
        }

        dog.jump();*/
//        view.setCenter(WIDTH / 2 + dog.pos().x - 600, HEIGHT / 2);
//        window.setView(view);
//
//        window.clear();
//
//        for (auto& sky : skysVector)
//        {
//            sky->render(window);
//        }
//
//        for (auto& ground : groundsVector)
//        {
//            ground->render(window);
//        }
//
//        for (auto& ground : groundsVector_up)
//        {
//            ground->render(window);
//        }
//
//
//        dog.render(window);
//        window.display();
//    }
//
    /*for (auto& ground : groundsVector)
    {
        delete ground;
    }

    for (auto& ground : groundsVector_up)
    {
        delete ground;
    }

    for (auto& sky : skysVector)
    {
        delete sky;
    }*/
//
//    return 0;
//}
