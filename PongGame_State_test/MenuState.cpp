#include "MenuState.h"
#include "Game.h"
#include <iostream>
//
#include <stdexcept>

MenuState::MenuState(Game* game)
{
	this->game = game;

	//font.loadFromFile("fonts/Gameplay.ttf");
	if (!font.loadFromFile("fonts/arial.ttf"))
	{
		std::cout << "Error text!";
	}

	title.setFont(font);
	title.setString("Welcome to Pong Game Rivals press Enter to continue");
	title.setCharacterSize(40);
	title.setPosition(200.f, 200.f);
}

void MenuState::handleEvent(sf::Event& event)
{

}

void MenuState::update()
{

}

void MenuState::render(sf::RenderWindow& window)
{
	window.draw(title);
}