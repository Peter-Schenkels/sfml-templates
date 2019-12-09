#include "Circle.hpp"
#include <iostream>

void Circle::mouseMove( sf::Vector2f mousePosition) {

    if (body.getGlobalBounds().contains(mousePosition)){

        std::cout << name << "hey jogne ben je geslected 1?? " << selected << std::endl;
        if (selected){
            move(sf::Vector2f(
                mousePosition.x - radius,
                mousePosition.y - radius
                )
            );
        }

    }

}


void Circle::select(sf::Vector2f mousePosition) {

    deselect();
    if (body.getGlobalBounds().contains(mousePosition)){
        selected = true;
        std::cout << name << "hey jogne ben je geslected 3?? " << selected << std::endl;
    }
    
}

std::string Circle::exportString() {

    std::string exportStr = "/ (" +
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