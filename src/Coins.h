#include "boundingbox.h"
#include "tilemap.h"
#include <vector>
#include <SFML/Audio.hpp>
class Coins : public TileMap
{
public:
	Coins();
	void resolveCollision(Mario& mario);
	bool load(const std::string& tileset, Vectori tileSize, int scale, int* tiles, int width, int height, Vectori position);
	void reset();
	int getcount() { return count; }
	 
private:
	std::vector<BoundingBox*> coins;
	int count{ 0 };
	sf::Music eateneffect;



};

