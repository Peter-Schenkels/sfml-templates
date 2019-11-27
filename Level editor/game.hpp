#include <SFML/Graphics.hpp>
#include <iostream>
#include "object.hpp"

#ifndef GAME
#define GAME

#define MAXOBJECTS 100

class Game {



private:

    sf::RenderWindow window( sf::VideoMode( 1200, 700 ), "SFML window" );
    std::ofstream outfile("save.jrkl");
    object objects[MAXOBJECTS];
    unsigned int numberOfActiveObjects = 0;

public:
    Game(){
        
    }

    void init();

    void main();

    void update();

    void draw();


    void save();





};


#endif