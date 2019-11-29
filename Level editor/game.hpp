#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "object.hpp"

#ifndef GAME
#define GAME

#define MAXOBJECTS 100
#define WINDOWX 640
#define WINDOWY 420


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

void add(){

}




class ObjectContainer {

    object * container[MAXOBJECTS];
    unsigned int containerPointer = 0;


public:
    ObjectContainer(){}

    void addObject( 
        std::string type,
        sf::Vector2f size,
        sf::Vector2f position,
        std::string name,
        sf::Color color
    )
    {
        if (type == "Rectangle"){
            container[containerPointer] = new Rectangle(size, position, name, color);
            containerPointer++;
        } 
        else if (type == "Circle"){
            container[containerPointer] = new Circle(size.x, position, name, color);
            containerPointer++;
        }
    }
    
    void update(){
        for(auto item : container){
            item->update();
        }
    }

    void draw(sf::RenderWindow & window){
        for(auto item : container){
            item->draw(window);
        }
    }

};



class Game {

    std::ifstream file;
    sf::RenderWindow window = sf::RenderWindow{sf::VideoMode{WINDOWX, WINDOWY}, "window"};
    ObjectContainer container;

public:
    Game(){
        load();
    }


    void load() {
        file.open("jerkel.jrkl");

        if(!(file.is_open())){
            std::cout << "file not found\n";
            std::ofstream newFile;
            newFile.open("jerkel.jrkl");
            newFile.close();
            file.open("jerkel.jrkl");
        }

        std::string type;
        sf::Vector2f size;
        std::string name;
        sf::Vector2f position;
        sf::Color color = sf::Color::Blue;

        while (name != ""){
            file >> position >> size >> type >> name;
            container.addObject(type, size, position, name, color);
        }

    }


    void update(){
        container.update();
    }

    void draw(){
        container.draw(window);
    }





};



#endif
