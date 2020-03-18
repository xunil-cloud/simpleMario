//mario.cpp
//Implementation  of Mario class
#include "mario.h"
#include <iostream>

Mario::Mario() {
	texture.loadFromFile("mario.png");
	quad.resize(4);
	jumpeffect.openFromFile("jump.wav");
	
}
void Mario::setWalkspeedlimit(float speed) {
	walkspeedlimit = speed;
}

void Mario::setCanjump(bool b)
{
	canjump = b;
}

void Mario::walkRight() {
	acceleration.x = 1000;
}

void Mario::walkLeft() {
	acceleration.x = -1000;
}

void Mario::jump() {
	if ( canjumpfirsttime || (jumpcount < jumptimeslimit && jumpcount > 0) )
	{
		velocity.y = -1000;
		acceleration.y = 2400;
		updatejumpcount();
		jumpeffect.setPlayingOffset(sf::seconds(0.f));
		jumpeffect.play();
	}	
}

void Mario::stopWalking() {
	velocity.x = 0;
	acceleration.x = 0;
}

void Mario::integrate(float duration)
{
	velocity.addScaledVector(acceleration, duration);
	position.addScaledVector(velocity, duration);

	if (velocity.x > walkspeedlimit || velocity.x < -walkspeedlimit)
	{
		acceleration.x = 0;
	}
}

void Mario::updatejumpcount() {
	jumpcount--;
	
}

void Mario::resetjumpcount() {
	jumpcount = jumptimeslimit;
	canjumpfirsttime = true;
}
void Mario::setjumptimeslimit(int c) {
	jumptimeslimit = c;
}


void Mario::setPositionX(const float x)
{
	position.x = x;
}

void Mario::setPositionY(const float y)
{
	position.y = y;
}

void Mario::setVelocityX(const float x) {
	velocity.x = x;
}

void Mario::setVelocityY(const float y) {
	velocity.y = y;
}

void Mario::draw(sf::RenderWindow& target, float deltatime)
{
	if (velocity.x > 0)
		d = 0;
	else if (velocity.x < 0)
		d = 1;
	quad[0].position = sf::Vector2f(position.x - width / 2, position.y - height / 2);
	quad[1].position = sf::Vector2f(position.x + width / 2, position.y - height / 2);
	quad[2].position = sf::Vector2f(position.x + width / 2, position.y + height / 2);
	quad[3].position = sf::Vector2f(position.x - width / 2, position.y + height / 2);

	totaltime += deltatime;
	if (totaltime >= switchtime)
	{
		totaltime -= switchtime;
		currentimage++;
		if (currentimage >= imagecount)
		{
			currentimage = 0;
		}

	}
	if (velocity.y != 0)
	{
		quad[0].texCoords = sf::Vector2f(0.f + 14 * 6, 0.f + 20 * d);
		quad[1].texCoords = sf::Vector2f(14.f + 14 * 6, 0.f + 20 * d);
		quad[2].texCoords = sf::Vector2f(14.f + 14 * 6, 20.f + 20 * d);
		quad[3].texCoords = sf::Vector2f(0.f + 14 * 6, 20.f + 20 * d);
		
	}
	else if (velocity.x == 0)
	{
		quad[0].texCoords = sf::Vector2f(0.f, 0.f + 20 * d);
		quad[1].texCoords = sf::Vector2f(14.f, 0.f + 20 * d);
		quad[2].texCoords = sf::Vector2f(14.f, 20.f + 20 * d);
		quad[3].texCoords = sf::Vector2f(0.f, 20.f + 20 * d);
		currentimage = 0;
	}
	
	else {
		

		// define its texture area to be a 25x50 rectangle starting at (0, 0)
		quad[0].texCoords = sf::Vector2f(0.f + 14 * currentimage, 0.f + 20 * d);
		quad[1].texCoords = sf::Vector2f(14.f + 14 * currentimage, 0.f + 20 * d);
		quad[2].texCoords = sf::Vector2f(14.f + 14 * currentimage, 20.f + 20 * d);
		quad[3].texCoords = sf::Vector2f(0.f + 14 * currentimage, 20.f + 20 * d);

	}
		states.texture = &texture;
		target.draw(quad, states);
	
	
	//shape.setPosition(sf::Vector2f(position.x - width / 2, position.y - height / 2));
}

void Mario::reset() {
	attacked = false;
	d = 0;
	setVelocityX(0);
	setPositionX(getWidth() / 2);
	setPositionY(100);
	setVelocityY(0);
	setAccelerationX(0);
	return;

}

void Mario::killed()
{
	attacked = true;
}

