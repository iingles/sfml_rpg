#ifndef GAME_H
#define GAME_H

#include "State.h"


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