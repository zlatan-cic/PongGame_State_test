#include "PlayState.h"
#include "Game.h"
#include <iostream>

PlayState::PlayState(Game* game)
{
	this->game = game;

	ball.setPosition(390.f, 290.f);
	ball.setRadius(10.f);
	ball.setFillColor(sf::Color::White);
	m_ballSpeed_X = 0.3f;
	m_ballSpeed_Y = 0.3f;

	p1.setSize(sf::Vector2f(20.f, 100.f));
	p1.setPosition(15.f, 250.f); // centerY - halfHeight
	p1.setFillColor(sf::Color::White);

	p2.setSize(sf::Vector2f(20.f, 100.f));
	p2.setPosition(780.f, 250.f); 
	p2.setFillColor(sf::Color::White);
}

void PlayState::handleEvent(sf::Event& event)
{
}

void PlayState::render(sf::RenderWindow& window)
{
	window.draw(p1);
	window.draw(p2);
	window.draw(ball);
}

void PlayState::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		p1.move(0.f, -1.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		p1.move(0.f, 1.f );
	}

	ball.move(m_ballSpeed_X, m_ballSpeed_Y);
}