#include "object.hpp"


class Line : public Object
{

private:
    sf::VertexArray line;
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
     * Line 
     * 
     * @brief  constructor of the line object
     * @param  {sf::Vector2f} position : position of the line
     * @param  {sf::Vector2f} size     : size of the line
     * @param  {sf::Color} color       : color of the line
     */
    Line(sf::Vector2f position, sf::Vector2f size, sf::Color color);

};