#pragma once
#include "State.h"

class Game;
class PauseState : public State
{
private:
	Game* game;

	sf::Font font;
	sf::Text pauseTitle;
	sf::Text instructionText;

public:
	PauseState(Game* game);

	void handleEvent(sf::Event& event);
	void update(float dt);
	void render(sf::RenderWindow& window);
};