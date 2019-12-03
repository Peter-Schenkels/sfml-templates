#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "object.hpp"


class Circle : public object {

private:
	float radius;
    sf::CircleShape body;
	sf::Color color;


public:
    Circle(float radius, sf::Vector2f position, std::string name, sf::Color color):
        object(position, name),
		radius(radius),
        body(radius),
		color(color)
    {
		update();
	}

	void setColor(const sf::Color color) override {
		body.setFillColor(color);
	}

	void update() override{
		body.setPosition(position);
	}

	void draw(sf::RenderWindow & window) override{
		window.draw(body);
	}

	void mouseMove( sf::Vector2f mousePosition, bool & mouseSelection) override{



		if (body.getGlobalBounds().contains(mousePosition)){
			
			if(mouseSelection == false){
				selected = true;
				mouseSelection = true;
			}


			if (selected){
				move(sf::Vector2f(
					mousePosition.x - radius,
					mousePosition.y - radius
					)
					);
			}

		}
	}

	std::string exportString() override{
		std::string exportStr = "1 (" +
		std::to_string(position.x) + "," +
		std::to_string(position.y) + ") (" +
		std::to_string(radius) + "," +
		std::to_string(radius) + ") Circle " +
		name + " white";

		return exportStr;
	}


};



#endif