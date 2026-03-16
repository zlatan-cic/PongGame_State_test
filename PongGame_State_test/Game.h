#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"

class Game
{
private:
	sf::RenderWindow window;
	State* currentState; // trenutno aktivan state

public:
	Game(); // "napravi prozor"
	~Game(); // "cisti memoriju"

	void run(); // game loop u mainu
	void changeState(State* newState); // menja state

	sf::RenderWindow& getWindow(); 
};