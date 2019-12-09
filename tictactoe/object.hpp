#ifndef object_hpp
#define object_hpp

#include <SFML/Graphics.hpp>


class object {

protected:
	
	sf::Vector2f position = sf::Vector2f{0,0};
	std::string name;
	bool selected = false;
	
public:

	object(){
		name = "empty";
	}
	
	object(
		sf::Vector2f & position, 
		std::string name
	):
		position(position),
		name(name)
	{}

	sf::Vector2f getPosition() { return position; }

	virtual void setColor(const sf::Color color) = 0;

	virtual void update() = 0;

	void deselect(){ selected = false; }

	virtual void draw(sf::RenderWindow & window) = 0;

	virtual	void mouseMove( sf::Vector2f mousePosition, bool & mouseSelection ) = 0;

	virtual std::string exportString() = 0;

	void move(sf::Vector2f pPosition){ position = pPosition; }

	std::string getName() { return name; }
};









#endif