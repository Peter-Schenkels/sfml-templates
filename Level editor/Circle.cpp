#include "Circle.hpp"


void Circle::mouseMove( sf::Vector2f mousePosition, bool & mouseSelection) {

    if (body.getGlobalBounds().contains(mousePosition)){
        
        if(mouseSelection == false){
            selected = true;
            mouseSelection = true;
        }

        if (selected){
            move(sf::Vector2f(
                mousePosition.x - radius,
                mousePosition.y - radius
                )
            );
        }

    }

}

std::string Circle::exportString() {

    std::string exportStr = "1 (" +
    std::to_string(position.x) + "," +
    std::to_string(position.y) + ") (" +
    std::to_string(radius) + "," +
    std::to_string(radius) + ") Circle " + name 
    + " " + std::to_string(color.r)
    + "," + std::to_string(color.g) 
    + ',' + std::to_string(color.b) 
    + "," + std::to_string(color.a)
    + " /";

    return exportStr;
}