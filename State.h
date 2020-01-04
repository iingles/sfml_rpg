#ifndef STATE_H
#define STATE_H

#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

/*
	State class is going to be the "meat" of the game
*/

class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture*> textures;
	bool quit;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();
	virtual void endState() = 0;

	//Every function needs to define updateKeyBinds
	virtual void updateKeyBinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;

	//if nothing is given, render to the window; if to a specific target, render here. 
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif