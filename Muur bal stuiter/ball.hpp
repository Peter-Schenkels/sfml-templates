#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>


class hitbox {

public:
	sf::Vector2f position, size;
	sf::RectangleShape left, right, top, bottom;
	sf::RectangleShape box;

	hitbox(sf::Vector2f position, sf::Vector2f size):
		position(position),
		size(size),
		left(sf::Vector2f{0, size.y}),
		right{sf::Vector2f{0, size.y}},
		top({size.x, 0}),
		bottom({size.x, 0}),
		box(size)
	{
		left.setPosition(position);
		right.setPosition({position.x+ size.x, position.y});
		top.setPosition(position);
		bottom.setPosition({position.x, position.y + size.y});
		box.setPosition(position);

		left.setOutlineThickness(1.f);
		right.setOutlineThickness(1.f);
		top.setOutlineThickness(1.f);
		bottom.setOutlineThickness(1.f);
	}

	void update(sf::Vector2f pposition){
		position = pposition;
		left.setPosition(position);
		right.setPosition({position.x+ size.x, position.y});
		top.setPosition(position);
		bottom.setPosition({position.x, position.y + size.y});
		box.setPosition(position);
	}

	void draw(sf::RenderWindow & window){
		window.draw(left);
		window.draw(right);
		window.draw(top);
		window.draw(bottom);
	}

	bool leftSideIntersect(sf::FloatRect collider){
		return left.getGlobalBounds().intersects(collider);
	}
	
	bool rightSideIntersect(sf::FloatRect collider){
		return right.getGlobalBounds().intersects(collider);
	}

	bool topSideIntersect(sf::FloatRect collider){
		return top.getGlobalBounds().intersects(collider);
	}

	bool bottomSideIntersect(sf::FloatRect collider){
		return bottom.getGlobalBounds().intersects(collider);
	}

	sf::FloatRect getOuterbounds(){
		return box.getGlobalBounds();
	}
};

class object {

protected:
	float height, width;
	hitbox collision;
	sf::Vector2f position;

public:
	object(float height, float width, sf::Vector2f & position):
		height(height),
		width(width),
		collision(position, {height, width}),
		position(position)
		
	{}
	hitbox getHitbox(){ return collision; }
	virtual void intersect(sf::FloatRect collider) = 0;


};

class wall : public object{

public:

	wall(sf::Vector2f position, float height, float width);
	
	void draw( sf::RenderWindow & window ) const;
	void move( sf::Vector2f delta );
	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );
	void intersect(sf::FloatRect collider) override;


};


class ball : public object{

private:
	float size;
	
public:
	sf::Vector2f speed{10, 4};
	ball( sf::Vector2f position, float size = 30.0 );
	void intersect(sf::FloatRect collider) override;
	void draw( sf::RenderWindow & window ) const;
	void move( sf::Vector2f delta );
	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );
	sf::Vector2f getSize() {return {size, size};}
	sf::Vector2f getPosition() {return position;}


};

class box {

private:
	wall &left;
	wall &right;
	wall &top;
	wall &bottom;

public:
	box(wall &left, wall &right, wall &top, wall &bottom):
		left(left),
		right(right),
		top(top),
		bottom(bottom)
	{}

	void move( sf::Vector2f delta ){
		left.move(delta);
		right.move(delta);
		top.move(delta);
		bottom.move(delta);
	}

	void draw(sf::RenderWindow & window){
		left.draw(window);
		right.draw(window);
		top.draw(window);
		bottom.draw(window);
	}

	
};

#endif
