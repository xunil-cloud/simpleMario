//vector.cpp
//Implementation  of Vector2 class
#include "vector2.h"


Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::addScaledVector(const Vector2& vector, float scale) {
	x = x + scale * vector.x;
	y = y + scale * vector.y;
}

