#include "ObjectContainer.hpp"


void ObjectContainer::addObject
( 
    std::string type,
    sf::Vector2f size,
    sf::Vector2f position,
    std::string name,
    sf::Color color,
    std::string fileLocation

)
{
    try {   
        
        if (type == "Rectangle"){
            container[containerPointer] = new Rectangle(size, position, name, color);
            containerPointer++;
        } 
        else if (type == "Circle"){
            container[containerPointer] = new Circle(size.x, position, name, color);
            containerPointer++;
        }
        else if (type == "Sprite"){
            container[containerPointer] = new Sprite(position, fileLocation, size, name, color);
            containerPointer++;
        }
        else if (type == "Line"){
            container[containerPointer] = new Line(position, size, name, color);
            containerPointer++;
        }
        else {
            throw(type);
        }

    }
    catch(std::string type){
        std::cout << "error unable to recognise type: \"" << type << "\"" << std::endl;
    }

}


void ObjectContainer::update(){

    unsigned int itemNr = 0;

    for(auto item : container){

        if(itemNr == containerPointer)
            break;
        
        item->update();
        itemNr++;

    }

}

void ObjectContainer::deselect(){

    unsigned int itemNr = 0;

    for(auto item : container){
        if(itemNr == containerPointer)
            break;
        
        item->deselect();
        itemNr++;

    }

}

void ObjectContainer::draw(sf::RenderWindow & window){

    unsigned int itemNr = 0;

    for(auto item : container){
        
        if(itemNr == containerPointer)
            break;
        
        item->draw(window);
        itemNr++;

    }

}

void ObjectContainer::mouseMove(sf::Vector2i mousePosition, bool & mouseSelection){

    sf::Vector2f newMousePosition = static_cast<sf::Vector2f>(mousePosition);
    unsigned int itemNr = 0;
    
    for(auto object : container){
        
        if(itemNr == containerPointer)
            break;
        
        object->mouseMove(newMousePosition, mouseSelection);
        itemNr++;

    }

}

std::string ObjectContainer::exportString(){

    unsigned int itemNr = 0;
    std::string exportString;

    for(auto object : container){
        
        if(itemNr == containerPointer)
            break;
        
        exportString += object->exportString();
        exportString += "\n";
        itemNr++;

    }

    return exportString += "0";
    
}