#include "object.hpp"

Object::Object(sf::Vector2f position, sf::Vector2f size):
    position(position),
	size(size)
{
    return; 
}


void Object::draw( sf::RenderWindow & window ) 
{
    draw_implementation(window);
}

void Object::move( sf::Vector2f delta )
{
	position += delta;
}

void Object::jump( sf::Vector2f target )
{
	position = target;
}

void Object::update()
{
	position += speed;
}

void Object::jump( sf::Vector2i target )
{
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}

void Object::print_implementation(std::ostream & os) const {
	os << "<>\n";
}

void Object::select(sf::Event event){

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
		if (get_boundaries().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))){
			selected = true;
			if (event.mouseMove.x > 0 && event.mouseMove.y > 0){
				jump(sf::Vector2f(
					event.mouseMove.x-(size.x / 2), 
					event.mouseMove.y-(size.y / 2)
					)
				);
			}
		}
	}
	else{
		selected = false;
	}
	
}
