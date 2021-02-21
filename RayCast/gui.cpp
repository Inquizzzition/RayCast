#include "gui.h"

Wind::Wind() :
	w(sf::VideoMode(MX, MY), "Race"),
	rs(sf::Vector2f(1, 1))
{}

void Wind::render(Colr cr, Vec2 crd) {
	rs.setFillColor(sf::Color(cr.r, cr.g, cr.b, cr.a));
	rs.setPosition(MX / 2 + crd.x, MY / 2 + crd.y);
	w.draw(rs);
}
void Wind::clear() {
	w.clear();
}
void Wind::draw() {
	w.display();
}