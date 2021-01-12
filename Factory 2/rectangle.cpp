    
#include "rectangle.hpp"    
#include <SFML/Graphics.hpp>
    
Rectangle::Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color):
    Object(position, size),
    color(color)
{}

void Rectangle::draw_implementation(sf::RenderWindow & window)
{

    rectangle.setPosition(position);
    rectangle.setSize(size);
    rectangle.setFillColor(color);
    if(selected) rectangle.setOutlineThickness(1);
    else rectangle.setOutlineThickness(0);
    window.draw(rectangle);

}

void Rectangle::print_implementation(std::ostream & os) const
{
	os << "<Rectangle;";
	os << position.x << ";" << position.y << ";";
    os << size.x << ";" << size.y << ";";
	os << std::to_string(color.r) << ";" << std::to_string(color.g) << ";" << std::to_string(color.b) << ";" << std::to_string(color.a) << ";"; 
	os << ">\n";
}
