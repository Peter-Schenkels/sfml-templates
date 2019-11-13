#include "wall.hpp"


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