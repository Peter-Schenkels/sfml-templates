#include "box.hpp"

box::box(wall &left, wall &right, wall &top, wall &bottom):
		left(left),
		right(right),
		top(top),
		bottom(bottom)
	{}

void box::move( sf::Vector2f delta ){
    left.move(delta);
    right.move(delta);
    top.move(delta);
    bottom.move(delta);
}

void box::draw(sf::RenderWindow & window){
    left.draw(window);
    right.draw(window);
    top.draw(window);
    bottom.draw(window);
}