#pragma once
#include "State.h"

class Game;
class PlayState : public State
{
private:
	Game* game; // forward declaration. remember!!!!

	sf::RectangleShape p1;
	sf::RectangleShape p2;
	sf::CircleShape ball;

	float m_ballSpeed_X;
	float m_ballSpeed_Y;

public:
	PlayState(Game* game);

	void handleEvent(sf::Event& event) override;
	void update() override;
	void render(sf::RenderWindow& window) override;

};