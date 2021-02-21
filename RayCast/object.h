#ifndef OBJECT_H
#define OBJECT_H

#include<vector>
#include"strc.h"


class Ray
{
private:
	Vec3 o;
	Vec3 d;
public:
	Vec3 get_o();
	Vec3 get_d();
	void set_o(Vec3 t);
	void set_d(Vec3 t);
	Ray(Vec3 a, Vec3 b);
};

class Sphere {
private:
	Vec3 crd;
	Colr colr;
	double radius;
public:
	Sphere(Vec3 c, double r);
	void set_crd(Vec3 crd);
	Vec3 get_crd();
	Colr get_colr();
	void set_colr(Colr colr);
	bool intersect(Ray ray, double& t);
};
//class line {
//private:
//	Vec3 A;
//	Vec3 B;
//public:
//	void set_A(Vec3 crd);
//	void set_B(Vec3 crd);
//	Vec3 get_A();
//	Vec3 get_B();

//};

//class Cam {
//private:
//	Vec3 crd;
//	Colr colr;
//	double radius;
//public:
//	void set_crd(Vec3 crd);
//	Vec3 get_crd();
//	void set_colr(Colr colr);
//};


#endif