#pragma once
#include "State.h"
#include <string>

class Game; // Foward dec.
class GameOverState : public State
{
private:
	
	Game* game;

	std::string winner;

	sf::Font font;
	sf::Text winnerText;
	sf::Text instructionText;

public:
	GameOverState(Game* game, const std::string& winner);

	void handleEvent(sf::Event& event);
	void update(float dt);
	void render(sf::RenderWindow& window);
};