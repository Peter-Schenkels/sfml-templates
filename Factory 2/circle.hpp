#pragma once

#include <SFML/Graphics.hpp>
#include "object.hpp"
#include <iostream>

class Circle : public Object 
{
protected:
	sf::CircleShape circle;
	sf::Color color;
	/**
	 * @brief implements the << operator for this object
	 * @param os output ostream 
	**/
	void print_implementation(std::ostream & os) const override;
	/**
     * @brief Draw implementation of this class 
     * @param window A renderwindow where the object gets drawn in
    **/
	void draw_implementation(sf::RenderWindow & window) override;

public:
	/**
	 * @brief Constructor of Circle
	 * @param position The 2d position of the Circle
	 * @param size The diameter of the Circle
	**/
	Circle( sf::Vector2f position, float size, sf::Color color );
	/**
	 * @brief Sets the speed of the object
	 * @param speed A vector with speed for x & y
	**/
	bool intersect(sf::FloatRect collider);
	/**
     * @brief Virtual update method that can updates certain parameters like speed intersection or position
    **/
	void update() override;

	
};

