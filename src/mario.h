// mario.h 
// Mario class defination
// Member functions are implement in mario.cpp

#ifndef MARIO_H
#define MARIO_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include "particle.h"
//#include "boundingbox.h"
#include "vector2.h"



class Mario
{

public:
    Mario();//constructor
	
    void setWalkspeedlimit(float speed);
    float getWalkspeedlimit() { return walkspeedlimit; }
	void setCanjump(bool b);
	bool getCanjump() { return canjump; }

    void walkRight();
    void walkLeft();
    void jump();
    void stopWalking();
	virtual void integrate(float duration);

    void setjumptimeslimit(int c);
    void resetjumpcount();
    bool canjumpfirsttime{false};

	float getPositionX() { return position.x; }
	float getPositionY() { return position.y; }
	float getVelocityX() { return velocity.x; }
	float getVelocityY() { return velocity.y; }
	float getHeight() { return height; }
	float getWidth() { return width; }

	void setPositionX(const float x);
	void setPositionY(const float y);
	void setVelocityX(const float x);
	void setVelocityY(const float y);
	void setAccelerationY(float y){acceleration.y = y;}
	void setAccelerationX(float x){acceleration.x = x;}
	void draw(sf::RenderWindow& target, float deltatime);
	void reset();
	bool attacked{ false }; 
	void killed();
	void reducelife() { life--; }
	int getlife() { return life; }
	void setlife(int n) { life = 3; }

private:
    void updatejumpcount();

protected:


	Vector2 position{14 ,100};
	Vector2 velocity{0,0};
	Vector2 acceleration{0, 2200};
	float height{40};
	float width{28};

	int	life{3};
	int	level{1};
	float walkspeedlimit{800};
	

    int jumpcount{2};
    int jumptimeslimit{1};
	bool canjump{false};
	sf::Texture texture;
	sf::VertexArray quad{sf::Quads, 4};
	sf::RenderStates states;
	int imagecount{ 6 };
	int currentimage{ 0 };
	float switchtime{ 0.1f };
	float totaltime{ 0.f };
	int d{ 0 };
	sf::Music jumpeffect;
};

#endif