// enemy.h 
// Enemy class defination
// Member functions are implement in enemy.cpp

#include "mario.h"
#include <iostream>
#include <SFML/Audio.hpp>

#ifndef ENEMY_h
#define ENEMY_h


class Enemy : public Mario {

public:
	Enemy(float c, float r, float y);
	void draw(sf::RenderWindow& target);
	void todead();
	void tofired();
	bool ifdead() { return dead; };
	bool iffired() { return fired;  };
	void reset();
	virtual void integrate(float duration);
	void checkkill(Mario & mario);
	void setCenter(float c) { center = c; }
	void setRadius(float r) { radius = r; }

private:
	bool dead{ false };
	bool fired{ false };
	float radius{ 0 };
	float center{ 0 };
	float walkspeed{ -100 };
	sf::Music killedeffect;
	sf::Music killeffect;

};

#endif