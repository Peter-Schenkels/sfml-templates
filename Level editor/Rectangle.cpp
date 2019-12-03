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
}

void Rectangle::mouseMove( sf::Vector2f mousePosition, bool & mouseSelection ) {

    if (body.getGlobalBounds().contains(mousePosition)){

        if(mouseSelection == false){
            selected = true;
            mouseSelection = true;
        }

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

    std::string exportStr = "1 (" +
    std::to_string(position.x) + "," +
    std::to_string(position.y) + ") (" +
    std::to_string(size.x) + "," +
    std::to_string(size.y) + ") Rectangle " +
    name + " white";

    return exportStr;

}