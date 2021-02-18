#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "strc.h"

class Wind {
private:
	sf::RenderWindow w;
	sf::RectangleShape rs;
public:
	Wind();
	void draw();
	void clear();
	void render(Colr colr, Vec2 crd);
};



#endif