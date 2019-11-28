#include <SFML/Graphics.hpp>
#include <iostream>
#include "object.hpp"

#ifndef GAME
#define GAME

#define MAXOBJECTS 100


class unknown_color : public std::exception {
public:
   unknown_color( const std::string & name  ):
       s{ std::string{ "unknown colcor [" } + name + "]" }
   {}
private:
   std::string s;
};


std::ifstream & operator>>( std::ifstream & input, sf::Color & rhs ){
   std::string s;
   input >> s;
   const struct { const char * name; sf::Color color; } colors[]{
       { "yellow", sf::Color::Yellow },
       { "red",    sf::Color::Red },
       { "green", sf::Color::Green },
       { "blue",    sf::Color::Blue }
   };
   for( auto const & color : colors ){
       if( color.name == s ){ 
          rhs = color.color;
          return input;
       }
   }
   throw unknown_color( s );
}

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs){
    std::string position;
    std::string xPos;
    std::string yPos;
    bool comma = false;
    input >> position;
    unsigned int index;
    for (auto chr : position){
        if (chr == ','){
            comma = true;
            continue;
        }
        if (chr == '('){
            continue;
        }
        if (chr == ')'){
            break;
        }
        if (comma) {
            yPos += chr;
            
        } else {
            xPos += chr;
        }
    }
    rhs.x = strtof((xPos).c_str(),0);
    rhs.y = strtof((yPos).c_str(),0);
    return input;
}


class objectStorage {

private:
    unsigned int storagePointer = 0;
    std::unique_ptr<object*> storage[MAXOBJECTS];

public:
    objectStorage(){}

void addObject(object* newObject){
    storage[storagePointer] = new object{
    storagePointer++;

}







}



class Game {



private:

    sf::RenderWindow window( sf::VideoMode( 1200, 700 ), "SFML window" );
    std::ofstream outfile("save.jrkl");
    object objects *[MAXOBJECTS];
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