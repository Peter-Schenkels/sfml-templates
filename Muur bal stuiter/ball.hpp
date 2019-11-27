#ifndef _BALL_HPP
#define _BALL_HPP

#include "object.hpp"


class ball : public object{

private:
	float size;
	
public:
	sf::Vector2f speed{1.2, 1.3};

	ball( sf::Vector2f position, float size = 30.0 );

	void intersect(sf::FloatRect collider) override;

	void draw( sf::RenderWindow & window ) const;

	void move( sf::Vector2f delta );

	void jump( sf::Vector2f target );

	void jump( sf::Vector2i target );

	sf::Vector2f getSize() {return {size, size};}
	
	sf::Vector2f getPosition() {return position;}


};

#endif
