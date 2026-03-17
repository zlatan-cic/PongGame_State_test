#pragma once
#include "State.h"

class Game; // forward declaration
class MenuState :public State
{
private:
	Game* game;

	sf::Font font;
	sf::Text title;

	bool startGame;

public:
	MenuState(Game* game);

	void handleEvent(sf::Event& event) override;
	void update() override;
	void render(sf::RenderWindow& window) override;

};