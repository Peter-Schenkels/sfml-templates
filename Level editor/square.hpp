#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>
#include "object.hpp"


class Square : public object {

private:
    sf::RectangleShape body;


public:
    Square(sf::Vector2f size, sf::Vector2f position):
        object(size, position, body),
        body(size)
    
    
    {}




};



#endif