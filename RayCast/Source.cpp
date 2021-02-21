#include "gui.h"
#include "object.h"
#include <iostream>
int main() {
	Wind w;
	Colr red(178, 34, 34, 255);
	Sphere sphere(Vec3(20, 0, 0), 10);
	while (true) {
		w.clear();
		for (double i = -(MX / 2); i <= MX / 2; i++)
			for (double j = -(MY / 2); j <= MY / 2; j++) {
				Ray ray(Vec3(i, j, 0), Vec3(0, 0, 1));
				double t = 2e4;
				if (sphere.intersect(ray, t))
					w.render(sphere.set_colr, Vec2(i, j));
				else
					w.render(Colr(0, 0, 0), Vec2(i, j))
			}
		w.draw();
	}
}