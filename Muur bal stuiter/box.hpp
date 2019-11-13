#ifndef box_hpp
#define box_hpp

#include "wall.hpp"

class box {

private:
	wall &left;
	wall &right;
	wall &top;
	wall &bottom;

public:
	box(wall &left, wall &right, wall &top, wall &bottom);

	void move( sf::Vector2f delta );

	void draw(sf::RenderWindow & window);

	
};

#endif