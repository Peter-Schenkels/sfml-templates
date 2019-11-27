#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "box.hpp"


class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(std::function< void() > work):
		condition(
			[]()-> bool { return true; }
		),
		work(work)
		{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};



int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 1200, 700 }, "SFML window" };
	ball myBall{ { 320.0, 240.0 }};
	wall leftWall {{ 30.0, 30.0 }, 30.0, 600};
	wall rightWall {{ 1000.0 , 30.0 }, 30.0, 600};
	wall topWall {{ 30.0, 30.0 }, 1000.0, 30.0};
	wall bottomWall {{ 30.0, 600 }, 1000, 30.0};
	wall doos{{30, 30}, 100, 100};
	box room{leftWall, rightWall, topWall, bottomWall};
	window.setFramerateLimit(240);

	action actions[] = {
		action( sf::Keyboard::Left,  [&](){ doos.move( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ doos.move( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ doos.move( sf::Vector2f(  0.0, -1.0 )); }),
		action( sf::Keyboard::Down,  [&](){ doos.move( sf::Vector2f(  0.0, +1.0 )); }),
		action(						 [&](){ myBall.move(myBall.speed); }),
		action( sf::Mouse::Left,     [&](){ myBall.jump( sf::Mouse::getPosition( window )); })
	};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		myBall.draw(window);
		myBall.intersect(leftWall.getHitbox().getOuterbounds());
		myBall.intersect(rightWall.getHitbox().getOuterbounds());
		myBall.intersect(topWall.getHitbox().getOuterbounds());
		myBall.intersect(bottomWall.getHitbox().getOuterbounds());
		myBall.intersect(doos.getHitbox().getOuterbounds());
		room.draw(window);
		doos.draw(window);
		window.display();



        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

	std::cout << "Terminating application\n";
	return 0;
}

