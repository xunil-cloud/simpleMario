
#include "tilemap.h"
#include <iostream>

//載入地圖
bool TileMap::load(const std::string& tileset, Vectori tileSize, int scale, int* tiles,  int width,  int height, Vectori position)
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
    m_vertices.resize(count * 4);
	count = 0;
    // populate the vertex array, with one quad per tile
    for (int i = 0; i < width; ++i)
        for (int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width];
			if (tileNumber == -1)
			{
				continue;
			}
            // find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / int(tileSize.x));
			int tv = tileNumber / (m_tileset.getSize().x / int(tileSize.x));

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(count) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x * scale + position.x, j * tileSize.y * scale + position.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x * scale + position.x, j * tileSize.y * scale + position.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x * scale + position.x, (j + 1) * tileSize.y * scale + position.y);
            quad[3].position = sf::Vector2f(i * tileSize.x * scale + position.x, (j + 1) * tileSize.y * scale + position.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			count++;
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

//將地圖畫在視窗上
void TileMap::draw(sf::RenderTarget& target) {

    states.texture = &m_tileset;
    target.draw(m_vertices, states);
}

//碰撞檢測
int TileMap::resolveCollision(Mario& mario) {
    mario.canjumpfirsttime = false;
    mario.setAccelerationY(2400);
	    
	if (mario.getPositionX() - mario.getWidth() / 2 - offsetX < 0)
	{
		mario.setPositionX(offsetX + mario.getWidth()/2);
		mario.setVelocityX(0);

	}

    if (mario.getPositionY() - mario.getHeight()/2 > 1100) 
        return FALL;
	
	else if (mario.getPositionX() + mario.getWidth() / 2 - offsetX  >  width * tilewidth)
	{
		mario.setPositionX(offsetX + width * tilewidth - mario.getWidth() / 2);
		mario.setVelocityX(0);
        return WIN;
	}

   float left = mario.getPositionX() - mario.getWidth()/2 - offsetX;
   float top = mario.getPositionY() - mario.getHeight()/2 - offsetY;
   float right = mario.getPositionX() + mario.getWidth()/2 - offsetX;
   float bottom = mario.getPositionY() + mario.getHeight()/2 - offsetY;
   int leftbox = int(left/width);
   int topbox = int(top/height);
   int rightbox = int(right/width);
   int bottombox = int(bottom/height);

	if (bottom < 0) 
	{
		return 0;
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
	}
	
    BoundingBox* box;
	
	for(int x = leftbox; x <= rightbox; x++)
		for (int y = topbox; y <= bottombox; y++)
		{
			
			if (map[x + y * tilewidth] == -1)
			{
				continue;
			}
			else
			{
				//std::cout << mario.getPositionY() << ' ' << mario.getVelocityY() << '\n' ;
				if (map[x - 1 + y * tilewidth] != -1 )
				{
					box = new BoundingBox((x - 1) * width + offsetX, y * height + offsetY, width * 2, height);
					resolve(mario, *box);
					delete box;
				}
				else
				{
					box = new BoundingBox(x * width + offsetX, y * height + offsetY, width, height);
					resolve(mario, *box);
					delete box;
					
				}
								
			}
		}
    
    return 0;
}
   
void TileMap::resolve(Mario& mario, BoundingBox& map) {



    float distanceX = mario.getPositionX() - (map.getCenterX());
    float distanceY = mario.getPositionY() - (map.getCenterY());

    float deltaX = abs(distanceX) - (mario.getWidth() / 2 + map.getHalfWidth());

    float deltaY = abs(distanceY) - (mario.getHeight() / 2 + map.getHalfHeight());


    
    if (deltaY > 0 || deltaX >= 0)
        return;
    
    if (deltaY > deltaX || mario.getVelocityX() == 0) {
        if (distanceY > 0)
        {
            mario.setPositionY(map.getBottom() + mario.getHeight() / 2);
            mario.setVelocityY(-mario.getVelocityY());
        }
        else
        {
            mario.setPositionY(map.getTop() - mario.getHeight() / 2);
            mario.setVelocityY(0);
			//mario.setAccelerationY(0);
            mario.resetjumpcount();
        }
    }
    else {
        if (distanceX > 0)
        {
            mario.setPositionX(map.getRight() + mario.getWidth() / 2);
            mario.setVelocityX(0);
        }
        else
        {
            mario.setPositionX(map.getLeft() - mario.getWidth() / 2);
            mario.setVelocityX(0);
        }
        
    }
}