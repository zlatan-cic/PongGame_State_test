#include "MenuState.h"
#include "Game.h"
#include <iostream>
#include "PlayState.h"
//
#include <stdexcept>

MenuState::MenuState(Game* game)
{
	this->game = game;

	startGame = false;

	//font.loadFromFile("fonts/Gameplay.ttf");
	if (!font.loadFromFile("fonts/Gameplay.ttf"))
	{
		std::cout << "Error text!";
	}

	title.setFont(font);
	title.setString("Welcome to Pong Game Rivals press Enter to continue");
	title.setCharacterSize(18);
	title.setPosition(90.f, 200.f);
}

void MenuState::handleEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Enter)
		{
			startGame = true;
		}
	}
}

void MenuState::update()
{
	if (startGame)
	{
		game->changeState(new PlayState(game));
	}
}

void MenuState::render(sf::RenderWindow& window)
{
	window.draw(title);
}