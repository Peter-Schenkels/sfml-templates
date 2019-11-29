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
	{}

	sf::Vector2f getPosition() { return position; }

	virtual void setColor(const sf::Color color);

	virtual void update();

	virtual void draw(sf::RenderWindow & window);

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

	void draw(sf::RenderWindow & window){
		window.draw(body);
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
        body(radius),
		color(color)
    {
		update();
		setColor(color);
	}

	void setColor(const sf::Color color) override {
		body.setFillColor(color);
	}

	void update() override{
		body.setPosition(position);
	}

	void draw(sf::RenderWindow & window){
		window.draw(body);
	}

};


#endif