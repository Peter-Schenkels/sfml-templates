#include "ObjectContainer.hpp"


void ObjectContainer::addCircle(sf::Vector2f position, float radius, std::string name, sf::Color color ){
    
    container[containerPointer] = new Circle(radius, position, name, color);
    containerPointer++;
}

void ObjectContainer::addRectangle(sf::Vector2f position, sf::Vector2f size, std::string name, sf::Color color ){

    container[containerPointer] = new Rectangle(size, position, name, color);
    containerPointer++;

}

void ObjectContainer::addSprite(sf::Vector2f position, sf::Vector2f size, std::string name, sf::Color color, std::string imgLocation){

    container[containerPointer] = new Sprite(position, imgLocation, size, name, color);
    containerPointer++;

}

void ObjectContainer::addLine(sf::Vector2f position, sf::Vector2f size, std::string name, sf::Color color){
    
    container[containerPointer] = new Line(position, size, name, color);
    containerPointer++;

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

void ObjectContainer::select(sf::Vector2i mousePosition){
    
    sf::Vector2f newMousePosition = static_cast<sf::Vector2f>(mousePosition);
    unsigned int itemNr = 0;

    for(auto item : container){
        if(itemNr == containerPointer)
            break;
        
        item->select(newMousePosition);
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

void ObjectContainer::mouseMove(sf::Vector2i mousePosition){

    sf::Vector2f newMousePosition = static_cast<sf::Vector2f>(mousePosition);
    unsigned int itemNr = 0;
    
    for(auto object : container){
        
        if(itemNr == containerPointer)
            break;
        
        object->mouseMove(newMousePosition);
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

    return exportString;
    
}