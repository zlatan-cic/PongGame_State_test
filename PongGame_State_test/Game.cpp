#include "Game.h"
#include "MenuState.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "Pong Game State patterns"),
    currentState(nullptr),
    nextState(nullptr)
{
    currentState = new MenuState(this);
}

void Game::run()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        sf::Event event;

        while (window.pollEvent(event))
        {


            if (event.type == sf::Event::Closed)
                window.close();

            /*if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape)
            {
                window.close();
                
            }*/

            currentState->handleEvent(event);
        }

        currentState->update(dt);

        if (nextState != nullptr)
        {
            delete currentState;
            currentState = nextState;
            nextState = nullptr;
        }

        window.clear(); 
        currentState->render(window);
        window.display();
    }
}

void Game::changeState(State* newState)
{
    nextState = newState;
}

Game::~Game()
{
    delete currentState;
    delete nextState;
}

sf::RenderWindow& Game::getWindow()
{
    return window;
}