#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	sf::RectangleShape rect;
	float rectspeed = 200.f;

	sf::CircleShape circle;
	float circlespeed = 300.f;

	// vector for position
	sf::Vector2f pos{ 100, 100 };

	// vector for velocity
	sf::Vector2f vel{ 1, 1 };

	
	


	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
};