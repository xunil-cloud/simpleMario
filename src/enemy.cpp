#include "enemy.h"
#include "Windows.h"

Enemy::Enemy(float c, float r, float y)
{
	texture.loadFromFile("enemy.png");
	quad.resize(4);
	width = 25;
	height = 25;
	center = c;
	radius = r;
	setPositionX(c);
	setPositionY(y);
	setAccelerationX(0);
	setAccelerationY(2200);
	setVelocityX(-100);
	setVelocityY(0);

	killedeffect.openFromFile("killenemy.wav");
	killeffect.openFromFile("dead.wav");
	
}

void Enemy::draw(sf::RenderWindow& target)
{

	quad[0].position = sf::Vector2f(position.x - width / 2, position.y - height / 2);
	quad[1].position = sf::Vector2f(position.x + width / 2, position.y - height / 2);
	quad[2].position = sf::Vector2f(position.x + width / 2, position.y + height / 2);
	quad[3].position = sf::Vector2f(position.x - width / 2, position.y + height / 2);
	
	quad[0].texCoords = sf::Vector2f(0, 0);
	quad[1].texCoords = sf::Vector2f(16,0);
	quad[2].texCoords = sf::Vector2f(16,16);
	quad[3].texCoords = sf::Vector2f(0,16);

	
	states.texture = &texture;
	target.draw(quad, states);

	return;


}

void Enemy::todead()
{
	height = 12;
	dead = true;
	killedeffect.play();
}

void Enemy::tofired()
{
	fired = true;
}

void Enemy::reset() {
	dead = false;
	fired = false;
	height = 32;
	setPositionX(center);
	setVelocityX(walkspeed);
	return;
}

void Enemy::integrate(float duration)
{
	if (!dead)
	{
	velocity.x = walkspeed;

	}
	velocity.addScaledVector(acceleration, duration);
	position.addScaledVector(velocity, duration);
	if (position.x < center - radius && velocity.x < 0)
	{
		walkspeed = -walkspeed;
		velocity.x = walkspeed;
		
	}
	else if (position.x > center + radius && velocity.x > 0)
	{
		walkspeed = -walkspeed;
		velocity.x = walkspeed;
		
	}
	
}

void Enemy::checkkill(Mario &mario) {

	if (dead)
	{
		return;
	}

	float distanceX = mario.getPositionX() - getPositionX();
	float distanceY = mario.getPositionY() - getPositionY();

	float deltaX = abs(distanceX) - (mario.getWidth() / 2 + getWidth() / 2);

	float deltaY = abs(distanceY) - (mario.getHeight() / 2 + getHeight() / 2);



	if (deltaY > 0 || deltaX > 0)
		return;

	if (deltaY > deltaX) {
		if (distanceY > 0)
		{
			//mario.setPositionY(map.getBottom() + mario.getHeight() / 2);
			//mario.setVelocityY(-mario.getVelocityY());
			killeffect.setPlayingOffset(sf::seconds(0));
			killeffect.play();
			mario.killed();
			mario.setVelocityX(0);
			mario.setAccelerationX(0);
		}
		else
		{
			//mario.setPositionY(map.getTop() - mario.getHeight() / 2);
			//mario.setVelocityY(0);
			//mario.setAccelerationY(0);
			//mario.resetjumpcount();
			mario.setVelocityY(-500);
			mario.setVelocityX(0);
			setVelocityX(0);
			todead();
		}
	}
	else {
		killeffect.setPlayingOffset(sf::seconds(0));
		killeffect.play();
		mario.killed();
		mario.setVelocityX(0);
		mario.setAccelerationX(0);
	}
}