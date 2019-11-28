#include "object.hpp"

object::object(sf::Vector2f & size, sf::Vector2f & position, sf::Shape &shape):
		size(size),
		position(position),
		shape(shape)
	{}
	

object::object():
		size(sf::Vector2f{0,0})
		position(sf::Vector2f{0,0})
	{}
