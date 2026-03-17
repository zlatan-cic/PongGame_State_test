#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"
#include <iostream>

MenuState::MenuState(Game* game)
{
    this->game = game;
    startGame = false;

    if (!font.loadFromFile("fonts/Gameplay.ttf"))
    {
        std::cout << "Error loading font!\n";
    }

    title.setFont(font);
    title.setString("Welcome to Pong Game Rivals\nPress Enter to continue");
    title.setCharacterSize(24);
    title.setFillColor(sf::Color::White);
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

void MenuState::update(float dt)
{
    if (startGame)
    {
        game->changeState(new PlayState(game));
        startGame = false;
    }
}

void MenuState::render(sf::RenderWindow& window)
{
    window.draw(title);
}