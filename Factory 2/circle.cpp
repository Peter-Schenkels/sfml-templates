#include <SFML/Graphics.hpp>
#include "circle.hpp"
#include <iostream>
#include <string>  

Circle::Circle( sf::Vector2f position, float size, sf::Color color ):
	Object(position, {size, size}),
	color(color)

{}

void Circle::print_implementation(std::ostream & os) const
{
	os << "<Circle;";
	os << position.x << ";" << position.y << ";" << size.x << ";";
	os << std::to_string(color.r) << ";" << std::to_string(color.g) << ";" << std::to_string(color.b) << ";" << std::to_string(color.a) << ";"; 
	os << ">\n";
}


void Circle::draw_implementation(sf::RenderWindow & window)
{
	circle.setRadius(size.x/2);
	circle.setPosition(position);
	circle.setFillColor(color);
	if(selected) circle.setOutlineThickness(1);
	else circle.setOutlineThickness(0);
	window.draw(circle);
}

void Circle::update()
{
	position += speed;
}

bool Circle::intersect(sf::FloatRect collider)
{
	bool intersect = false;

	return intersect;

}
