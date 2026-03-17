# Pong Game – C++ / SFML / State Pattern

## Overview
This is a retro-style Pong game built using C++ and SFML.  
The goal of this project was to learn game development basics and implement a clean architecture using the State Pattern.

## Features
- Classic Pong gameplay (2 players)
- Smooth movement using delta time
- Ball collision with walls and paddles
- Score system
- Multiple game states (Play, Pause, Game Over)

## State Pattern
The game is structured using the State Pattern.  
Instead of writing all logic in one place, the game is divided into separate states.

## Each state has its own:
- handleEvent (input)
- update (logic)
- render (drawing)

## States used:
- MenuState
- PlayState
- PauseState
- GameOverState

## Controls
W / S → Player 1 movement  
Arrow Up / Down → Player 2 movement  
Escape → Pause / Exit  
Enter → Continue game  

## Gameplay Logic
- Ball moves using delta time
- Ball bounces from top and bottom walls
- Ball changes direction on paddle collision
- When the ball passes left or right side, score is updated
- First player to reach the score limit wins

## Game Over
When a player reaches the target score:
- Game switches to GameOverState
- Winner is displayed
- Player can restart or exit

## What I Learned
- How to structure a game using State Pattern
- Handling input, update, and rendering loops
- Basic collision detection
- Managing game states dynamically
- Working with SFML for graphics and input

## Future Improvements
- Add sound effects
- Add menu navigation
- Improve collision physics (angles)
- Add single player (AI)
- Polish UI and animations
