#pragma once
// #define DEBUG
#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * An abstract class of a drawable object object
**/ 
class Object {

public:
    Object(sf::Vector2f position, sf::Vector2f size);
    /**
     * @brief Function that draws an object to a screen
     * @param window The render window that the object should be drawn on.
    **/
	void draw( sf::RenderWindow & window );
    /**
     * @brief moves the object to the delta position of it's own position.
     * @param delta A given delta to move the object by.
    **/
	void move( sf::Vector2f delta );
    /**
     * @brief Set the position of the object to the given target position
     * @param target The new position of the object
    **/
	virtual void jump( sf::Vector2f target );
    /**
     * @brief Set the position of the object to the given target position
     * @param target The new position of the object
    **/
	virtual void jump( sf::Vector2i target );
    /**
     * @brief Virtual update method that can updates certain parameters like speed intersection or position
    **/
    virtual void update();

    sf::Vector2f getPosition()
    {
        return position;
    }

    void setPosition(sf::Vector2f i_position)
    {
        position = i_position;
    }

    // friend std::ostream &operator<<(std::ostream & os, const Object&object);
    /**
     * @brief virtual printing class that should be implemented by every object called by the << operator method
     * @param os The ostream where the data shoudl be shoved to.
    **/
    virtual void print_implementation(std::ostream & os) const;
    /**
     * @brief Overloads the << opertator and exports in pipi format
     * @param  {std::ostream} os        : 
     * @param  {Objectobject} undefined : 
     * @return {std::ostream}           : 
     */
    friend std::ostream &operator<<(std::ostream & os, const Object&object) 
    { 
        object.print_implementation(os); 
        return os;  
    }
    /**
     * @brief  Returns a floatrect of the boundary of the object
     * @return {sf::FloatRect}        : 
     */
    sf::FloatRect get_boundaries(){return sf::FloatRect( position.x, position.y, size.x, size.y);}
    /**
     * @brief changes the position of the object to the mouse 
     * position when selected with left mouse button
     * @param  {sf::Event} event : 
     */
    void select(sf::Event event);

protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f speed = {0, 0};
    bool selected = false;


    /**
     * @brief virtual drawing class that should be implemented by every object called by the draw method
     * @param window The render window that the object should be drawn on.
    **/
    virtual void draw_implementation( sf::RenderWindow & window ) = 0;

};

