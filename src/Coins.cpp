#include "Coins.h"
#include <iostream>


bool Coins::load(const std::string& tileset, Vectori tileSize, int scale, int* tiles, int width, int height, Vectori position)
{
	// load the tileset texture
	if (!m_tileset.loadFromFile(tileset))
		return false;
	int count{ 0 };
	for (int i = 0; i < width; ++i)
		for (int j = 0; j < height; ++j) {
			if (tiles[i + j * width] != -1)
			{
				count++;
			}
		}
	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.clear();
	m_vertices.resize(width * height * 4);
	
	// populate the vertex array, with one quad per tile
	for (int i = 0; i < width; ++i)
		for (int j = 0; j < height; ++j)
		{
			// get the current tile number
			int tileNumber = tiles[i + j * width];
			if (tileNumber != 0)
			{
				continue;
			}
			// find its position in the tileset texture
			//int tu = tileNumber % (m_tileset.getSize().x / int(tileSize.x));
			//int tv = tileNumber / (m_tileset.getSize().x / int(tileSize.x));

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x * scale + position.x, j * tileSize.y * scale + position.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x * scale + position.x, j * tileSize.y * scale + position.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x * scale + position.x, (j + 1) * tileSize.y * scale + position.y);
			quad[3].position = sf::Vector2f(i * tileSize.x * scale + position.x, (j + 1) * tileSize.y * scale + position.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(0 * tileSize.x, 0 * tileSize.y);
			quad[1].texCoords = sf::Vector2f((0 + 1) * tileSize.x, 0 * tileSize.y);
			quad[2].texCoords = sf::Vector2f((0 + 1) * tileSize.x, (0 + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(0 * tileSize.x, (0 + 1) * tileSize.y);
			
		}

	map = tiles;
	this->width = tileSize.x * scale;
	this->tilewidth = width;
	this->height = tileSize.y * scale;
	this->tileheight = height;
	this->scale = scale;
	offsetX = position.x;
	offsetY = position.y;

	return true;
}




Coins::Coins()
{
	eateneffect.openFromFile("eatcoin.wav");
	
}

void Coins::resolveCollision(Mario& mario) {
	

	/*float left = mario.getPositionX() - mario.getWidth() / 2 - offsetX;
	float top = mario.getPositionY() - mario.getHeight() / 2 - offsetY;
	float right = mario.getPositionX() + mario.getWidth() / 2 - offsetX;
	float bottom = mario.getPositionY() + mario.getHeight() / 2 - offsetY;
	int leftbox = int(left / width);
	int topbox = int(top / height);
	int rightbox = int(right / width);
	int bottombox = int(bottom / height);*/
	float marioX = mario.getPositionX() - offsetX;
	float marioY = mario.getPositionY() - offsetY;
	float deltaX = 0;
	float deltaY = 0;

	/*if (bottom < 0)
	{
		return;
	}
	if (bottom > height * tileheight)
		bottombox = tileheight - 1;
	if (topbox > height * tileheight)
	{
		topbox = tileheight - 1;
	}

	if (top < 0)
	{
		topbox = 0;
	}*/

	
	for (int x = 0; x < tilewidth; x++)
		for (int y = 0; y < tileheight; y++)
		{

			if (map[x + y * tilewidth] != 0)
				continue;

			deltaX = abs(marioX - (x * width + width / 2)) - (mario.getWidth() / 2 + width / 2);
			deltaY = abs(marioY - (y * height + height / 2)) - (mario.getHeight() / 2 + height / 2);

			if (deltaX < 0 && deltaY < 0)
			{		
				map[x + y * tilewidth] = 1;
				count++;
				sf::Vertex* quad = &m_vertices[(x + y * tilewidth) * 4];
				quad[0].texCoords = sf::Vector2f(1 * width/scale, 1 * height / scale);
				quad[1].texCoords = sf::Vector2f((1 + 1) * width / scale, 1 * height / scale);
				quad[2].texCoords = sf::Vector2f((1 + 1) * width / scale, (1 + 1) * height / scale);
				quad[3].texCoords = sf::Vector2f(1 * width / scale, (1 + 1) * height / scale);
				eateneffect.setPlayingOffset(sf::seconds(0));
				eateneffect.play();
				std::cout << "play" << std::endl;
			}
		}
	
}

void Coins::reset() { 

	for (int x = 0; x < tilewidth; x++) {
		for (int y = 0; y < tileheight; y++) {

			if (map[x + y * tilewidth] == 1) {
				
				map[x + y * tilewidth] = 0;
				count = 0;
				sf::Vertex* quad = &m_vertices[(x + y * tilewidth) * 4];
				quad[0].texCoords = sf::Vector2f(0 * width/scale, 0 * height / scale);
				quad[1].texCoords = sf::Vector2f((0 + 1) * width / scale, 0 * height / scale);
				quad[2].texCoords = sf::Vector2f((0 + 1) * width / scale, (0 + 1) * height / scale);
				quad[3].texCoords = sf::Vector2f(0 * width / scale, (0 + 1) * height / scale);
			}
		}
	}
	return;
}