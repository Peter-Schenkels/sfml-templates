#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball( sf::Vector2f position, float size ) :
	object(size * 2, size * 2, position),
	size( size)
{}

void ball::draw( sf::RenderWindow & window ) const {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	window.draw(circle);
}

void ball::move( sf::Vector2f delta ){
	collision.update((position + delta));
	position = position + delta;
}

void ball::jump( sf::Vector2f target ){
	collision.update(target);
	position = target;
}

void ball::jump( sf::Vector2i target ){
	collision.update(sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}

void ball::intersect(sf::FloatRect collider){

	if(collision.bottomSideIntersect(collider)){
		speed.y *= -1;
	}
	if(collision.topSideIntersect(collider)){
		speed.y *= -1;
	}
	if(collision.leftSideIntersect(collider)){
		speed.x *= -1;
	}
	if(collision.rightSideIntersect(collider)){
		speed.x *= -1;
	}

}

wall::wall(sf::Vector2f position, float height, float width):
	object(height, width, position)
{}

void wall::draw(sf::RenderWindow & window ) const{
	sf::RectangleShape rectangle;
	rectangle.setSize({height, width});
	rectangle.setPosition(position);
	window.draw(rectangle);
}

void wall::move( sf::Vector2f delta ){
	collision.update((position + delta));
	position = position + delta;

}

void wall::jump( sf::Vector2f target ){
	collision.update(target);
	position = target;
}

void wall::jump( sf::Vector2i target ){
	collision.update(sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}

void wall::intersect(sf::FloatRect collider){
	return;
}