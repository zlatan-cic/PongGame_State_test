#include "PauseState.h"
#include "PlayState.h"
#include "Game.h"
#include <iostream>

PauseState::PauseState(Game* game)
{
	this->game = game;

	
	if (!font.loadFromFile("fonts/Gameplay.ttf"))
	{
		std::cout << "Error loading font!\nFrom PasueState\n";
	}

	pauseTitle.setFont(font);
	pauseTitle.setCharacterSize(40);
	pauseTitle.setFillColor(sf::Color::White);

	pauseTitle.setString("Paused Game");
	pauseTitle.setOrigin(pauseTitle.getGlobalBounds().width / 2.f, 0.f);
	pauseTitle.setPosition(400.f, 300.f);


	instructionText.setFont(font);
	instructionText.setCharacterSize(20);
	instructionText.setFillColor(sf::Color::White);

	instructionText.setString("If you want to continue, press Enter. If you want to end the game, press Escape.");
	instructionText.setOrigin(instructionText.getGlobalBounds().width / 2.f, 0.f);
	instructionText.setPosition(400.f, 350.f);
}

void PauseState::handleEvent(sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			game->getWindow().close();
		}

		if (event.key.code == sf::Keyboard::Enter)
		{
			game->changeState(new PlayState(game));
		}
	}
}

void PauseState::update(float dt)
{

}

void PauseState::render(sf::RenderWindow& window)
{
	window.draw(pauseTitle);
	window.draw(instructionText);
}