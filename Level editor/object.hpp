#ifndef object_hpp
#define object_hpp

#include "hitbox.hpp"

class object {

protected:
	float height, width;
	sf::Vector2f position;

public:
	object();

	object(float height, float width, sf::Vector2f & position);

	virtual void draw();


};


#endif