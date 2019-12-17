#include "Rectangle.hpp"

Rectangle::Rectangle
    (
        sf::Vector2f size, 
        sf::Vector2f position, 
        std::string name, 
        sf::Color color
    ):
        object(position, name),
        size(size),
        body(size),
        color(color)
{
    update();
    setColor(color);
    
}

void Rectangle::select(sf::Vector2f mousePosition) {
    deselect();
    if (body.getGlobalBounds().contains(mousePosition)){
        selected = true;
    }
    
}

void Rectangle::mouseMove( sf::Vector2f mousePosition ) {

    if (body.getGlobalBounds().contains(mousePosition)){

        if (selected){
            move(sf::Vector2f
                (
                mousePosition.x - size.x / 2,
                mousePosition.y - size.y / 2
                )
            );
        }
    
    }

}

std::string Rectangle::exportString() {

    std::string exportStr = "Rectangle (" +
    std::to_string(position.x) + "," +
    std::to_string(position.y) + ") (" +
    std::to_string(size.x) + "," +
    std::to_string(size.y) + ") " + name    
    + " " + std::to_string(color.r)
    + "," + std::to_string(color.g) 
    + ',' + std::to_string(color.b) 
    + "," + std::to_string(color.a)
    + " /";

    return exportStr;

}