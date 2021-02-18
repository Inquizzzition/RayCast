#include "gui.h"
#include "object.h"
#include <iostream>
int main() {
	Wind w;
	Colr red(178, 34, 34, 255);
	while (true) {
		w.clear();
		for (int i = -50; i <= 50; i++)
			for (int j = -50; j <= 50; j++) {
				Vec2 v(i, j);
				w.render(red, v);
			}
		w.draw();
	}
}