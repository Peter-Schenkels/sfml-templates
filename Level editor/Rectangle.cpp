#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "object.hpp"



class Rectangle : public object {

private:
	sf::Vector2f size;
    sf::RectangleShape body;
	sf::Color color;
	


public:
    Rectangle(sf::Vector2f size, sf::Vector2f position, std::string name, sf::Color color):
        object(position, name),
        body(size),
		color(color)
    {
		update();
	}

	void setColor(const sf::Color color) override {
		body.setFillColor(color);
		setColor(color);
	}

	void update() override{
		body.setPosition(position);
	}

	void draw(sf::RenderWindow & window) override{
		window.draw(body);
	}

	std::string exportString() override{
		std::string exportStr = "1 (" +
		std::to_string(position.x) + "," +
		std::to_string(position.y) + ") (" +
		std::to_string(size.x) + "," +
		std::to_string(size.y) + ") Rectangle " +
		name + " white";

		return exportStr;
	}

    void mouseMove( sf::Vector2f mousePosition ) override{
		if (body.getGlobalBounds().contains(mousePosition)){
				move(sf::Vector2f(
			mousePosition.x - 25,
			mousePosition.y - 25
			)
			);
		}
	}

	sf::CircleShape getBody() override {
		return sf::CircleShape{10};
	}

};









#endif