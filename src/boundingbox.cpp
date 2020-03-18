#include "boundingbox.h"

BoundingBox::BoundingBox(float x, float y, float width, float height)
{
	this->centerX = x + width/2;
	this->centerY = y + height/2;
	this->halfwidth = width/2;
	this->halfheight = height/2;
}

float BoundingBox::getCenterX()
{
	return centerX;
}

float BoundingBox::getCenterY()
{
	return centerY;
}

float BoundingBox::getHalfHeight()
{
	return halfheight;
}

float BoundingBox::getHalfWidth()
{
	return halfwidth;
}
