#include "gui.h"

Wind::Wind() :
	w(sf::VideoMode(1920, 1080), "Race"),
	rs(sf::Vector2f(1, 1))
{}

void Wind::render(Colr cr, Vec2 crd) {
	rs.setFillColor(sf::Color(cr.r, cr.g, cr.b, cr.a));
	rs.setPosition(960 + crd.x, 540 + crd.y);
	w.draw(rs);
}
void Wind::clear() {
	w.clear();
}
void Wind::draw() {
	w.display();
}