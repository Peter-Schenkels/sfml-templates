#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "object.hpp"



class Rectangle : public object {


private:

	sf::Vector2f size;
    sf::RectangleShape body;
	sf::Color color;
	

public:

    Rectangle
	(
		sf::Vector2f size, 
		sf::Vector2f position, 
		std::string name, 
		sf::Color color
	);

	void setColor(const sf::Color color) override { body.setFillColor(color); }

	void update() override{ body.setPosition(position); }

	void draw(sf::RenderWindow & window) override{ window.draw(body); }

	std::string exportString() override;

    void mouseMove( sf::Vector2f mousePosition ) override;

	void select(sf::Vector2f mousePosition) override;

};









#endif