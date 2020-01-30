#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	
	rect.setSize(sf::Vector2f(100, 100));
	rect.setPosition(20, 300);
	

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	if (input->isKeyDown(sf::Keyboard::D))
	{
		rect.move(rectspeed * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		rect.move(-rectspeed * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::W))
	{
		rect.move(0, -rectspeed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		rect.move(0, rectspeed * dt);
	}
	if (rect.getPosition().x + rect.getSize().x > window->getSize().x)
	{
		//rectspeed = -rectspeed;
		float x = window->getSize().x - rect.getSize().x;
		rect.setPosition(x, rect.getPosition().y);
	}
	if (rect.getPosition().y + rect.getSize().y > window->getSize().y)
	{
		float y = window->getSize().y - rect.getSize().y;
		rect.setPosition(rect.getPosition().x, y);
		//rectspeed = -rectspeed;
	}
	if (rect.getPosition().x + rect.getSize().x > window->getSize().x)
	{

		rectspeed = -rectspeed;
	}
}




// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}