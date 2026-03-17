#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "Game.h"
#include <iostream>

PlayState::PlayState(Game* game)
{
    this->game = game;

    p1Score = 0;
    p2Score = 0;

    if (!font.loadFromFile("fonts/Gameplay.ttf"))
    {
        std::cout << "Error loading font!\n";
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    //scoreText.setPosition(310.f, 15.f);
    scoreText.setString("0 : 0");

    ball.setRadius(10.f);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(390.f, 290.f);

    m_ballSpeed_X = 300.f;
    m_ballSpeed_Y = 300.f;

    p1.setFillColor(sf::Color::Red);
    p1.setSize(sf::Vector2f(20.f, 100.f));
    p1.setPosition(15.f, 250.f);

    p2.setFillColor(sf::Color::Green);
    p2.setSize(sf::Vector2f(20.f, 100.f));
    p2.setPosition(765.f, 250.f);


}

void PlayState::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            game->changeState(new PauseState(game));
        }
    }
}

void PlayState::update(float dt)
{
    float paddleSpeed = 300.f;
    const int WIN_SCORE = 5;

    if (p1Score >= WIN_SCORE)
    {
        game->changeState(new GameOverState(game, "P1"));
        return;
    }

    if (p2Score >= WIN_SCORE)
    {
        game->changeState(new GameOverState(game, "P2"));
        return;
    }

    /// Bat movment ///
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        p1.move(0.f, -paddleSpeed * dt);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        p1.move(0.f, paddleSpeed * dt);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        p2.move(0.f, -paddleSpeed * dt);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        p2.move(0.f, paddleSpeed * dt);
    }
    ////
    ball.move(m_ballSpeed_X * dt, m_ballSpeed_Y * dt);
    ////

    ///
    if (ball.getPosition().x <= 0.f)
    {
        p2Score++;
        ball.setPosition(390.f, 290.f);
        m_ballSpeed_X = -m_ballSpeed_X;
    }

    if (ball.getPosition().x >= 800.f)
    {
        p1Score++;
        ball.setPosition(390.f, 290.f);
        m_ballSpeed_X = -m_ballSpeed_X;
    }

    /// Wall ///
    if (ball.getPosition().y <= 0.f)
    {
        m_ballSpeed_Y = -m_ballSpeed_Y;
    }

    if (ball.getPosition().y + ball.getRadius() * 2 >= 600.f)
    {
        m_ballSpeed_Y = -m_ballSpeed_Y;
    }

    if (ball.getGlobalBounds().intersects(p1.getGlobalBounds()))
    {
        m_ballSpeed_X = -m_ballSpeed_X;
    }

    if (ball.getGlobalBounds().intersects(p2.getGlobalBounds()))
    {
        m_ballSpeed_X = -m_ballSpeed_X;
    }

    if (p1.getPosition().y < 0.f)
        p1.setPosition(p1.getPosition().x, 0.f);

    if (p1.getPosition().y + 100.f > 600.f)
        p1.setPosition(p1.getPosition().x, 500.f);

    if (p2.getPosition().y < 0.f)
        p2.setPosition(p2.getPosition().x, 0.f);

    if (p2.getPosition().y + 100.f > 600.f)
        p2.setPosition(p2.getPosition().x, 500.f);

    scoreText.setString("P1: " + std::to_string(p1Score) + "   P2: " + std::to_string(p2Score));
    scoreText.setOrigin(scoreText.getGlobalBounds().width / 2.f, 0.f);
    scoreText.setPosition(400.f, 15.f);
}

void PlayState::render(sf::RenderWindow& window)
{
    
    window.draw(p1);
    window.draw(p2);
    window.draw(ball);
    window.draw(scoreText);

    /*window.clear(sf::Color::Blue);

    window.draw(p1);
    window.draw(p2);
    window.draw(ball);*/
}