#include "Game.h"

//Static functions

//Initializer functions
void Game::initWindow()
{
    //Create a SFML window using options from a window.init file
	
    std::ifstream ifs("config/window.ini");
       
    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    //don't forget to close the file!
    ifs.close();

    //Used c_str() here because for some reason it was failing without it
    this->window = new sf::RenderWindow(window_bounds, title.c_str());
    this->window ->setFramerateLimit(framerate_limit);
    this->window ->setVerticalSyncEnabled(vertical_sync_enabled);
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
