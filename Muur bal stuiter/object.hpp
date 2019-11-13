#ifndef object_hpp
#define object_hpp

#include "hitbox.hpp"

class object {

protected:
	float height, width;
	hitbox collision;
	sf::Vector2f position;

public:
	object(float height, float width, sf::Vector2f & position);

	hitbox getHitbox();

	virtual void intersect(sf::FloatRect collider) = 0;

};


#endif