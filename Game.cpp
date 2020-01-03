#include "Game.h"

//Static functions

//Initializer functions
//Initializer functions
void Game::initWindow()
{
    //Create a SFML window using options from a window.init file
	this -> window = new sf::RenderWindow(sf::VideoMode(800, 600), "C++ SFML RPG!");
}

//Constructors/destructors

Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//functions

void Game::updateDt()    
{
    //updates the dt variable with the time it takes to update and render one frame
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window->clear();

    //Render items
    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
