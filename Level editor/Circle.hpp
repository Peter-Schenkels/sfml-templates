#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "object.hpp"


class Circle : public object {


private:

	float radius;
    sf::CircleShape body;
	sf::Color color;


public:

    Circle(
			float radius, 
			sf::Vector2f position, 
			std::string name, 
			sf::Color color
		):
			object(position, name),
			radius(radius),
			body(radius),
			color(color)
	{
		setColor(color);
		update();
	}

	void setColor(const sf::Color color) override { body.setFillColor(color); }

	void update() override{ body.setPosition(position); }

	void draw(sf::RenderWindow & window) override{ window.draw(body); }

	void mouseMove( sf::Vector2f mousePosition, bool & mouseSelection) override;

	std::string exportString() override;


};



#endif