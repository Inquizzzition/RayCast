#ifndef OBJECT_H
#define OBJECT_H

#include<vector>
#include"strc.h"

class Sphere {
private:
	Vec3 crd;
	Colr colr;
	double radius;
public:
	void set_crd(Vec3 crd);
	Vec3 get_crd();
	void set_colr(Colr colr);
};

class line {
private:
	Vec3 A;
	Vec3 B;
public:
	void set_A(Vec3 crd);
	void set_B(Vec3 crd);
	Vec3 get_A();
	Vec3 get_B();

};

class Cam {
private:
	Vec3 crd;
	Colr colr;
	double radius;
public:
	void set_crd(Vec3 crd);
	Vec3 get_crd();
	void set_colr(Colr colr);
};


#endif