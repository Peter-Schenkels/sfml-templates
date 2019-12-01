#ifndef object_hpp
#define object_hpp

#include <SFML/Graphics.hpp>


class object {

protected:
	
	sf::Vector2f position = sf::Vector2f{0,0};
	std::string name;
	
public:
	
	object(sf::Vector2f & position, std::string name):
		position(position),
		name(name)
	{
		
	}

	sf::Vector2f getPosition() { return position; }

	virtual void setColor(const sf::Color color) = 0;

	virtual void update() = 0;

	virtual void draw(sf::RenderWindow & window) = 0;

	virtual	void mouseMove( sf::Vector2f mousePosition ) = 0;

	virtual std::string exportString() = 0;

	void move(sf::Vector2f pPosition){ position = pPosition; }


	virtual sf::CircleShape getBody() = 0;

	std::string getName() { return name; }
};


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

	void mouseMove( sf::Vector2f mousePosition) override{
		if (body.getGlobalBounds().contains(mousePosition)){
			move(sf::Vector2f(
				mousePosition.x - radius,
				mousePosition.y - radius
				)
				);
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


	sf::CircleShape getBody() override {
		return body;
	}

};


#endif