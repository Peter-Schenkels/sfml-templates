#include "picture.hpp"
#include <iostream>




void Picture::draw_implementation( sf::RenderWindow & window)
{
    sprite.setPosition(position);
    window.draw(sprite);
    if(selected){
        sf::RectangleShape rectangle;
        rectangle.setPosition(position);
        rectangle.setSize(size);
        rectangle.setFillColor({0,0,0,0});
        rectangle.setOutlineThickness(1);
        window.draw(rectangle);
    }
}

void Picture::print_implementation(std::ostream & os) const
{
	os << "<Picture;";
	os << position.x << ";" << position.y << ";";
    os << size.x << ";" << size.y << ";";
	os << file_path << ";";
	os << ">\n";
}

Picture::Picture(sf::Vector2f position, sf::Vector2f size, std::string file_path):
    Object(position, size),
    file_path(file_path)
{

    if (!texture.loadFromFile(file_path))
    {
        std::cerr << "failed to load image: " << file_path << std::endl;
    }
    sprite.setTexture(texture);

    auto t_size = texture.getSize();
    auto scale = sf::Vector2f{size.x / t_size.x, size.y / t_size.y};
    sprite.setScale(scale);

}