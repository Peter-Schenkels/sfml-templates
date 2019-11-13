#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>



class hitbox {

public:
	sf::Vector2f position;
	sf::Rect<float> lineLeft;
	sf::Rect<float> lineRight;
	sf::Rect<float> lineTop;
	sf::Rect<float> lineBottom;

	hitbox(float height, float width, sf::Vector2f position):
		position(position),
		lineLeft(position.x, position.y + height, position.x, position.y + height),
		lineRight(position.x + width,position.y + height, position.x + width, position.y +height),
		lineTop(position.x, position.y, position.x + width, position.y),
		lineBottom(position.x, position.y + height, position.x + width, position.y + height)
	{}


	void update( sf::Vector2f newPosition){
		position = newPosition;
	}

};

class object {

protected:
	hitbox collision;
	sf::Vector2f position;

public:
	object(float height, float width, sf::Vector2f & position):
		collision(height, width, position),
		position(position)
	{}

	virtual void collision(object collider);
	hitbox getHitbox(){ return collision; }

};

class ball : public object{

private:
	float size;
	
public:

	sf::Vector2f speed{1.f, 1.f};
	ball( sf::Vector2f position, float size = 30.0 );
	void collision(object collider);
	void draw( sf::RenderWindow & window ) const;
	void move( sf::Vector2f delta );
	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );


};

#endif
