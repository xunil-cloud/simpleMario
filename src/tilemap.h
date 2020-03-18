// tilemap.h 
//TileMap class defination
// Member functions are implement in tilemap.cpp
#include <string>
#include <SFML/Graphics.hpp>
#include "mario.h"
#include "boundingbox.h"
#include "vector2.h"

#ifndef TILEMAP_h
#define TILEMAP_h
#define FALL -1
#define WIN 1


struct Vectori {
	int x;
	int y;
	Vectori(int x, int y) {
		this->x = x;
		this->y = y;

	}
};

class TileMap {

public:
	bool load(const std::string& tileset, Vectori tileSize, int scale,  int* tiles,  int width,  int height,  Vectori position);
	void draw(sf::RenderTarget& target);
	int resolveCollision(Mario& mario);

private:
	void resolve(Mario& mario, BoundingBox& map);

protected:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::RenderStates states;
    int offsetX{0};
    int offsetY{0};
    float tilerealsizeX{0};
    float tilerealsizeY{0};
    int width{0};
	int tilewidth{ 0 };
    int height{0};
	int tileheight{ 0 };
    int scale{0};
    int* map{NULL};

	
};



#endif