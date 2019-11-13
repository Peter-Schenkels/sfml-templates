#include "object.hpp"

object::object(float height, float width, sf::Vector2f & position):
		height(height),
		width(width),
		collision(position, {height, width}),
		position(position)
		
	{}

hitbox object::getHitbox(){ return collision; }