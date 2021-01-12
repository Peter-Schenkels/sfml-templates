#pragma once

#include <SFML/Graphics.hpp>
#include "object.hpp"


class Rectangle : public Object {

protected:
    sf::RectangleShape rectangle;
    sf::Color color;

    /**
     * @brief Implementation of the draw method
     * @param  {sf::RenderWindow} window : 
     */
    void draw_implementation(sf::RenderWindow & window) override;
	/**
	 * @brief implements the << operator for this object
	 * @param os output ostream 
	**/
    void print_implementation(std::ostream & os) const override;

public:
    /**
     * @brief Default rectangle constructor
    **/
    Rectangle();
    /**
     * @brief rectangle constructor
     * @param size size of the rectangle
     * @param position position of the rectangle
    **/
    Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    
  
};

