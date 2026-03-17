#include "GameOverState.h"
#include "Game.h"
#include "PlayState.h"
#include <iostream>

GameOverState::GameOverState(Game* game, const std::string& winner)
{
	this->game = game;
	this->winner = winner;

	if (!font.loadFromFile("fonts/Gameplay.ttf"))
	{
		std::cout << "Error loading font!\nFrom GameOverState\n";
	}

	winnerText.setFont(font);
	winnerText.setCharacterSize(30);
	winnerText.setFillColor(sf::Color::Yellow);

	winnerText.setString("Winner is !!! " + winner);
	winnerText.setOrigin(winnerText.getGlobalBounds().width / 2.f, 0.f);
	winnerText.setPosition(400.f, 300.f);

	instructionText.setFont(font);
	instructionText.setCharacterSize(20);
	instructionText.setFillColor(sf::Color::White);

	instructionText.setString("If you want to continue, press Enter.\nIf you want to end the game, press Escape.");
	instructionText.setOrigin(instructionText.getGlobalBounds().width / 2.f, 0.f);
	instructionText.setPosition(400.f, 250.f);

}

void GameOverState::handleEvent(sf::Event& event)
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

void GameOverState::update(float dt)
{

}

void GameOverState::render(sf::RenderWindow& window)
{
	window.draw(winnerText);
	window.draw(instructionText);
}