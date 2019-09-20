#include"Point.h"

Point::Point()
{
}

Point::~Point()
{

}

double Point::getX()
{
	return x;
}
void Point::setX(double x)
{
	this->x = x;
}
double Point::getY()
{
	return y;
}
void Point::setY(double y)
{
	this->y = y;
}

bool Point::getTile()
{
	return tile;
}
void Point::setTile(bool tile)
{
	this->tile = tile;
}