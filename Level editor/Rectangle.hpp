#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "object.hpp"



class Rectangle : public object {

private:
	sf::Vector2f size;
    sf::RectangleShape body;
	sf::Color color;
	bool selected = false;
	


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

    void mouseMove( sf::Vector2f mousePosition, bool & mouseSelection  ) override{

		if (mouseSelection == false){
			selected = true;
		}

		if (body.getGlobalBounds().contains(mousePosition) && selected){
			if (mouseSelection == false){
				selected = false;
				std::cout << name << " los bal\n";
			} else {
					move(sf::Vector2f(
				mousePosition.x - 25,
				mousePosition.y - 25
				)
				);
				std::cout << "vast\n";
			}
		}
	}

	sf::CircleShape getBody() override {
		return sf::CircleShape{10};
	}

};









#endif