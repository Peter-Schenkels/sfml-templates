#include "line.hpp"

Line::Line(sf::Vector2f position, sf::Vector2f size, sf::Color color):
    Object(position, size),
    color(color)
{}

void Line::draw_implementation(sf::RenderWindow & window)
{
    line = sf::VertexArray(sf::Lines, 2);
    line[0].position = position + size;
    line[1].position = position;
    line[0].color = color;
    line[1].color = color;
    window.draw(line);
}

void Line::print_implementation(std::ostream & os) const 
{
    os << "<Line;";
    os << position.x << ";" << position.y << ";";
    os << size.x << ";" << size.y << ";";
    os << std::to_string(color.r) << ";" << std::to_string(color.g) << ";" << std::to_string(color.b) << ";" << std::to_string(color.a) << ";"; 
    os << ">\n";
}