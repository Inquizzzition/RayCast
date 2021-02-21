#include "object.h"

Sphere::Sphere(Vec3 c, double r)
{
	crd = c;
	radius = r;
}

void Sphere::set_crd(Vec3 crd) 
{
	this->crd = crd;
}

Vec3 Sphere::get_crd()
{
	return crd;
}

Colr Sphere::get_colr() 
{
	return colr;
}

void Sphere::set_colr(Colr colr)
{
	this->colr = colr;
}

bool Sphere::intersect(Ray ray, double& t)
{
	Vec3 o = ray.get_o();
	Vec3 d = ray.get_d();
	Vec3 oc = o - crd;
	double b = 2 * dot(oc, d);
	double c = dot(oc, oc) - radius * radius;
	double dis = b * b - c * 4;
	if (dis < 0)
		return false;
	else {
		dis = sqrt(dis);
		double t0 = -b - dis;
		double t1 = -b + dis;
		if (t0 > t1)
			t = t1;
		else
			t = t0;
		return false;
	}
}

Ray::Ray(Vec3 a, Vec3 b)
{
	o = a;
	d = b;
}
Vec3 Ray::get_o()
{
	return o;
}

Vec3 Ray::get_d()
{
	return d;
}
void Ray::set_o(Vec3 t)
{
	o = t;
}

void Ray::set_d(Vec3 t)
{
	d = t;
}


