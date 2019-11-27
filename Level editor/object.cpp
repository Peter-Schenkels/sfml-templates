#include "object.hpp"

object::object(float height, float width, sf::Vector2f & position):
		height(height),
		width(width),
		position(position)
		
	{}

object::object():
		height(0),
		width(0),
		position(sf::Vector2f{0,0})
	{}
