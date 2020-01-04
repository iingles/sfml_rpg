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

void Game::initStates()
{
    this->states.push(new GameState(this->window));
}

//Constructors/destructors

Game::Game()
{
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
	delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

//functions

void Game::endApplication()
{
    std::cout << "Ending Application" << "\n";
}

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

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        //If it wants to quit, do this
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //End the application
    else
    {
        this->endApplication();
        this->window->close();
    }

}

void Game::render()
{
    this->window->clear();

    //Render items

    //when we render our state, we can send a pointer to the window
    if (!this->states.empty())
    {
        this->states.top()->render(this->window);
    }
    
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
