

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include "object.hpp"
#include "actions.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Sprite.hpp"
#include "Line.hpp"
#include "ObjectContainer.hpp"
#include "GameOperators.hpp"

#define WINDOWX 640
#define WINDOWY 420




class Game {

    std::ifstream file;
    sf::RenderWindow & window;
    ObjectContainer container;
    bool mouseSelection = false;
    std::string fileLocation = "sav.dat";

        
    action actions[2] = {
		action( sf::Mouse::Left, [&](){ container.mouseMove(sf::Mouse::getPosition( window )); }),
		action( sf::Mouse::Right, [&](){ container.select(sf::Mouse::getPosition( window )); })
	};


public:
    Game(sf::RenderWindow & window):
        window(window)
    {
        load();
    }

    void load();

    void save();

    void main();

    void update(){ container.update(); }

    void draw();

};



#endif
