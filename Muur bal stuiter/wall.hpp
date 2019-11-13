#ifndef wall_hpp
#define wall_hpp

#include "object.hpp"

class wall : public object{

public:

	wall(sf::Vector2f position, float height, float width);
	
	void draw( sf::RenderWindow & window ) const;
	void move( sf::Vector2f delta );
	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );
	void intersect(sf::FloatRect collider) override;


};

#endif