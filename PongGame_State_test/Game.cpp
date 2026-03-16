#include "Game.h"
#include "MenuState.h"

Game::Game()
	: window(sf::VideoMode(800, 600), "Pong Game State patterns")
{
	currentState = new MenuState(this);
}

void Game::run()
{
	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			currentState->handleEvent(event);
		}

		/////////
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		////////

		currentState->update();

		window.clear();
		currentState->render(window);
		window.display();

		
	}

}

Game::~Game() // OBAVEZNO!!!!!!!
{
	delete currentState;
}