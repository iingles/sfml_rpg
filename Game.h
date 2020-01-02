#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<ctime>
#include<cstdlib>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"



class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	//Delta time keeps track of how long it takes to do one update call and one render call (frame)
	sf::Clock dtClock;
	float dt;

	//Initialization functions
	void initWindow();

public:
	//Constructors/destructors
	Game();
	virtual ~Game();

	//functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif