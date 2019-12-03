
# pragma once

#ifndef OBJECT_CONTAINER_HPP
#define OBJECT_CONTAINER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include "object.hpp"
#include "actions.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Sprite.hpp"
#include "Line.hpp"

#define MAXOBJECTS 100


class ObjectContainer {


private:

    object * container[MAXOBJECTS];
    unsigned int containerPointer = 0;


public:

    ObjectContainer(){};


    void addObject
    ( 
        std::string type,
        sf::Vector2f size,
        sf::Vector2f position,
        std::string name,
        sf::Color color,
        std::string fileLocation
    );

    void update();

    void deselect();

    void draw(sf::RenderWindow & window);

    void mouseMove(sf::Vector2i mousePosition, bool & mouseSelection);

    std::string exportString();

};


#endif