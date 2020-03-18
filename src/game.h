// game.h 
// Game class defination
// Member functions are implement in game.cpp

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <windows.h>
#include "vector2.h"
#include "world.h"
#include "mario.h"
#include "tilemap.h"
#include "Coins.h"
#include "enemy.h"
class Game
{
public:
	Game(int** map, int** c);
	void init();
	void start();
private:
	void movementHandle();
	void showmenu();
	void loss();
	void fall();
	void win();
	void uplevel();
	void setEnemy(int currentlevel);
	void fire();
private:
	sf::View view;
	sf::RenderWindow window{sf::VideoMode(1920, 1080), "Mario Game!"};
	sf::Font font;
	sf::Text text;
	sf::Text temp;
	sf::Text temp1;
	sf::Clock clock;
    sf::Time elapsed;
	sf::Event event;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	bool rightswitch = false;
	bool leftswitch = false;
	bool cancontrol{ true };
	Mario mario;
	World world;
	std::vector<Enemy*> enemys;
	std::vector<sf::CircleShape*> gun;
	Enemy enemy{850,60,792};
	TileMap tilemap;
	Coins coins;
	int** level;
	int** c;
	int currentlevel{0};
	int score[3]{0};
	int mariostate{0};
	sf::RectangleShape winsign;
	sf::Texture wintexture;

};

#endif
