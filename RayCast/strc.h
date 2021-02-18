#ifndef STRC_H
#define STRC_H

struct Vec3 {
	double x, y, z;
	Vec3();
	Vec3(double x, double y, double z);
};

struct Vec2 {
	double x, y;
	Vec2();
	Vec2(double x, double y);
};

struct Colr {
	double r, g, b, a;
	Colr();
	Colr(double r, double g, double b, double a);
};
#endif