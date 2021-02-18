#include "strc.h"

Vec3::Vec3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vec3::Vec3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec2::Vec2()
{
	this->x = 0;
	this->y = 0;
}

Vec2::Vec2(double x, double y)
{
	this->x = x;
	this->y = y;
}


Colr::Colr() {
	this->r = 0;
	this->g = 0;
	this->b = 0;
	this->a = 0;
}
Colr::Colr(double r, double g, double b, double a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}