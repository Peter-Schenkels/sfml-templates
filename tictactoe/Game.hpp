#include <SFML/Graphics.hpp>
#include <iostream>
#include "object.hpp"
#include "Sprite.hpp"


struct Move {

    char player;
    sf::Vector2i position;

    Move(char & player, sf::Vector2i & position):
        player(player),
        position(position)
    {}


};

class ObjectContainer {

    object * container[9];



public:

    ObjectContainer();

    void addObject(bool cross, sf::Vector2i){



    }

    void draw(){


    }

};

class Game {


private:
    sf::RenderWindow & window;
    Move moves[9];
    char turn;


public:

    Game();


    void main(){

        while (window.isOpen()){
            draw();
            makeTurn();
            checkwin();
            update();
        }

    };

    void draw(){



    };

    void update(){};

    void checkwin(){}

    void makeTurn(){}


};