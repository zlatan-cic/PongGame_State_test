#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"

class Game
{
private:
    sf::RenderWindow window;
    State* currentState;
    State* nextState;

public:
    Game();
    ~Game();

    void run();
    void changeState(State* newState);
    sf::RenderWindow& getWindow();
};