#include <SFML/Graphics.hpp>
#include <iostream>
#include "object.hpp"
#include "Sprite.hpp"

#define WINDOW_SIZE_X 480
#define WINDOW_SIZE_Y 480

struct Move {

    char player;
    sf::Vector2i position;
    


    Move(char player = ' ', sf::Vector2i position = {4,4}):
        player(player),
        position(position)
    {}


};


class ObjectContainer {

    object * container[9];
    int objectPointer = 0;
    sf::RenderWindow & window;


public:

    ObjectContainer(sf::RenderWindow & window):
        window(window)
    {}

    void addObject(sf::Vector2f position, bool turn){
        int offset = 500 / 3;
        position.x *= offset;
        position.y *= offset;

        if (turn){
            container[objectPointer] = new Sprite(position, "img/cross.png", {0.1,0.1}, "Cross", sf::Color::White );
            objectPointer++;
        } else {
            container[objectPointer] = new Sprite(position, "img/circle.png", {0.1,0.1}, "Circle", sf::Color::White );
            objectPointer++;
        }


    }

    void draw(){
        
        int counter = 0;
        
        for (auto item : container){
            if (counter == objectPointer)
                break;
            item->draw(window);
            counter++;
        }

    }

};

class Game {


private:
    sf::RenderWindow & window;
    sf::RectangleShape background;
    Sprite field = {sf::Vector2f(0,0), std::string("img/bord.png"), {0.65,0.60}, "Bord", {255,255,255,255}};
    Move moves[9];
    int movesPointer = 0;
    ObjectContainer container;
    bool turn = 0;


public:

    Game(sf::RenderWindow & window):
        window(window),
        background({480, 470}),
        container(window)

    {
        background.setFillColor(sf::Color::White);

    }

    void main(){

        draw();
        makeTurn();
        std::cout << "hey" << std::endl;
        checkwin();
        update();

    };

    void draw(){
        window.draw(background);
        field.draw(window);
        container.draw();
        window.display();



    };

    void update(){};

    void checkwin(){}

    void makeTurn(){
        /// X = 0, O = 1
        if (!turn) {
            while (!turn){
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        std::cout << "start" << std::endl;
   
                    addMove();
                }
            }
        }
        else if (turn) {
            while (turn){
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    addMove();
                }
            }
            
        } else {
            std::cout << "GameOver" << std::endl;
        }


    }

    void addMove(){
        sf::Vector2i position = sf::Mouse::getPosition() / 3;

        if (position.x < 3 or position.y < 3){

            moves[movesPointer] = Move{turn, position};
            sf::Vector2f newPosition = {float(position.x), float(position.y)};
            container.addObject(newPosition, turn);
            if(turn)turn = 0;
            else turn = 1;
            std::cout << "huheuehue" << std::endl;

        }
        
    }


};