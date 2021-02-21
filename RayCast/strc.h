#ifndef STRC_H
#define STRC_H

const double MX = 1920;
const double MY = 1080;

struct Vec3 {
	double x, y, z;
	Vec3();
	Vec3(double x, double y, double z);
	Vec3 operator - (Vec3 v) {
		return Vec3(x - v.x, y - v.y, z - v.z);
	}
};

double dot(Vec3 v1, Vec3 v2);

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