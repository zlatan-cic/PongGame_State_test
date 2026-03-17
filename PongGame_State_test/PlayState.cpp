#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* game)
{
    this->game = game;

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
}

void PlayState::update(float dt)
{
    float paddleSpeed = 300.f;

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

    ball.move(m_ballSpeed_X * dt, m_ballSpeed_Y * dt);

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
}

void PlayState::render(sf::RenderWindow& window)
{
    
    window.draw(p1);
    window.draw(p2);
    window.draw(ball);

    /*window.clear(sf::Color::Blue);

    window.draw(p1);
    window.draw(p2);
    window.draw(ball);*/
}