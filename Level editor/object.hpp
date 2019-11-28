#ifndef object_hpp
#define object_hpp

#include "hitbox.hpp"

class object {

protected:
	sf::Vector2f size;
	sf::Vector2f position;
	

public:
	sf::Shape & shape;
	
	object();

	object(sf::Vector2f & size, sf::Vector2f & position, sf::Shape &shape);

	virtual void draw();

	sf::Vector2f getSize() { return size; }
	sf::Vector2f getPosition() { return position; }


};


#endif