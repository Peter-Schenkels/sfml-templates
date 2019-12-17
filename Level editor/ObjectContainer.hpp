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

    void addCircle(sf::Vector2f position, float radius, std::string name, sf::Color color );

    void addRectangle(sf::Vector2f position, sf::Vector2f size, std::string name, sf::Color color );

    void addSprite(sf::Vector2f position, sf::Vector2f size, std::string name, sf::Color color, std::string imgLocation);

    void addLine(sf::Vector2f position, sf::Vector2f size, std::string name, sf::Color color);

    void update();

    void select(sf::Vector2i mousePosition);

    void deselect();

    void draw(sf::RenderWindow & window);

    void mouseMove(sf::Vector2i mousePosition);

    std::string exportString();

};


#endif