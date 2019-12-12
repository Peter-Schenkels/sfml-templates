#include <SFML/Graphics.hpp>
#include <iostream>
#include "object.hpp"
#include "Sprite.hpp"

#define WINDOW_SIZE_X 480
#define WINDOW_SIZE_Y 480

struct Move {

    bool player;
    sf::Vector2i position;
    
    Move(bool player = 0, sf::Vector2i position = {4,4}):
        player(player),
        position(position)
    {}


};

class ObjectContainer {

    int objectPointer = -1;
    Sprite container[10]= {};
    sf::RenderWindow & window;


public:

    ObjectContainer(sf::RenderWindow & window):
        window(window)
    {}

    void setPointer(int newPoint){


        if (newPoint > 8 or newPoint < 0){
            std::cout << "invalid pointer set" << std::endl;
        }

        objectPointer = newPoint;

    }

    int getObjectPointer() { return objectPointer; }

    void draw(std::vector<Move> & moves, int movesPointer){

        int counter = 0;
        
        for (auto item : moves){


            if (counter == movesPointer) break;
                ///
            if(item.player){
                container[counter].loadTexture("img/circle.png");
                container[counter].setScale({0.45,0.45});
                container[counter].move
                ({
                    float(item.position.x * (500 / 3) - 70),
                    float(item.position.y * (500 / 3) - 70)
                });
            } else {
                container[counter].loadTexture("img/cross.png");
                container[counter].setScale({0.15,0.15});
                container[counter].move
                ({
                    float(item.position.x * (500 / 3)),
                    float(item.position.y * (500 / 3))
                });
            }

            
            
            container[counter].update();
            ///
            container[counter].draw(window);
            counter++;
        }

    }

};


bool checkAvailable(std::vector<Move> list, Move value){

    if(list.empty()) return 1;

    int counter = 0;
    int size = list.size() - 1;
    for(Move item : list){
        if (counter == size) return 1;
        if (item.position == value.position) return 0;
    }

    return 1;

}



class Game {


private:
    sf::RenderWindow & window;
    sf::RectangleShape background;
    Sprite field = {sf::Vector2f(0,0), std::string("img/bord.png"), {0.65,0.60}, "Bord", {255,255,255,255}};
    std::vector<Move> moves;
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

        makeTurn();
        checkwin();
        draw();
        update();

    };

    bool checkWin2(int turn, int field[3][3]){
        //check horizontal
        for(int y = 0; y != 3; y++){
            if(
                field[0][y] == turn &&
                field[1][y] == turn &&
                field[2][y] == turn
            ){
                std::cout << "horizontal " << y + 1<< std::endl;
                return 1; 
            }
        }

        //check vertical
        for(int x = 0; x != 3; x++){
            if(
                field[x][0] == turn &&
                field[x][1] == turn &&
                field[x][2] == turn
            )
            {
                std::cout << "vertical " << x + 1<< std::endl;
                return 1; 
            }
        }

        //check diagnol 
        if(  field[0][0] == turn &&
             field[1][1] == turn &&
             field[2][2] == turn
        )   {
                std::cout << "diagnol 1" << std::endl;
                return 1; 
            }

        if(  field[0][2] == turn &&
             field[1][1] == turn &&
             field[2][0] == turn
        ) {
                std::cout << "diagnol 2" << std::endl;
                return 1; 
            }

        return 0;

    }

    void checkwin(){
        int field[3][3];
        for (int x = 0; x < 3; x++){
            for (int y = 0; y < 3; y++){
                field[x][y] = 2;
            }      
        }
        //to array
        for(auto item : moves){
            field[item.position.x][item.position.y] = item.player;
        }
        
        //check horizontal
        if(checkWin2(turn, field)){
            std::cout << turn << " has won" << std::endl;
            while(1);          
        }
        else if(checkDraw(field)) {
            std::cout << "Draw!" << std::endl;
            while(1);                     

        }
    }

    bool checkDraw(int field[3][3]){
        for (int x = 0; x < 3; x++){
            for (int y = 0; y < 3; y++){
                if (field[x][y] == 2)
                    return 0;
            }      
        }

        return 1;

    }

    void draw(){
        window.clear();
        window.draw(background);
        field.draw(window);
        container.draw(moves, movesPointer);
        window.display();

    };

    void update(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if(movesPointer != 0){
                movesPointer--;
                moves.pop_back();

                if (moves.back().player){
                    turn = 0;
                } else {
                    turn = 1;
                }
                while(sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
            }
        }
    };

    void makeTurn(){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            addMove();
            while(sf::Mouse::isButtonPressed(sf::Mouse::Left));
        }
    
        
    }

 void addMove(){

        sf::Vector2i position = (sf::Mouse::getPosition() - sf::Vector2i(88,88))/ 162 ;


        if (position.x < 3 && position.y < 3){

            Move newMove = {turn, position};

            if (checkAvailable(moves, newMove)){

                movesPointer++;
                moves.push_back(newMove);

            }

            if(turn){
                turn = 0;
            } else {
                turn = 1;
            }



        }


    }


};