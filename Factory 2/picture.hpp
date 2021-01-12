#include "object.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class Picture : public Object
{

private:
    sf::Sprite sprite;
    sf::Texture texture;
    std::string file_path;
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
     * Picture 
     * 
     * @brief Picture Constructor
     * @param  {sf::Vector2f} position : position of the picture
     * @param  {sf::Vector2f} size     : size of the picture
     * @param  {std::string} file_path : file path of the sprite
     */
    Picture(sf::Vector2f position, sf::Vector2f size, std::string file_path);

};