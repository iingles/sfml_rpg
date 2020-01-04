#ifndef GAME_H
#define GAME_H

#include "GameState.h"


class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	//Delta time keeps track of how long it takes to do one update call and one render call (frame)
	sf::Clock dtClock;
	float dt;

	/*
		State pointer; State is an abstract class so we can only create pointers
		Here we create a stack to add states to
	*/
	std::stack<State*> states;
	
	//Initialization functions
	void initWindow();
	void initStates();

public:
	//Constructors/destructors
	Game();
	virtual ~Game();

	//functions

	//regular
	void endApplication();


	//update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//render
	void render();

	//core
	void run();
};

#endif