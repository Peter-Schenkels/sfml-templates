#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "object.hpp"
#include "actions.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Sprite.hpp"

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
        std::string color
    )
    {
        try {   
            
            if (type == "Rectangle"){
                container[containerPointer] = new Rectangle(size, position, name, sf::Color::White);
                containerPointer++;
            } 
            else if (type == "Circle"){
                container[containerPointer] = new Circle(size.x, position, name, sf::Color::White);
                containerPointer++;
            }
            else if (type == "Sprite"){
                container[containerPointer] = new Sprite(position, color, size, name);
                containerPointer++;
            }
            else {
                throw(type);
            }

        }
        catch(std::string type){
            std::cout << "error unable to recognise type: \"" << type << "\"" << std::endl;
        }

    }
    
    void update(){
        unsigned int itemNr = 0;

        for(auto item : container){
            if(itemNr == containerPointer){
                break;
            }
            item->update();
            itemNr++;
        }
    }

    void deselect(){
        unsigned int itemNr = 0;

        for(auto item : container){
            if(itemNr == containerPointer){
                break;
            }
            item->deselect();
            itemNr++;
        }
    }

    void draw(sf::RenderWindow & window){
        unsigned int itemNr = 0;
        for(auto item : container){
            
            

            if(itemNr == containerPointer){
                break;
            }
            item->draw(window);
            itemNr++;
        }
    }

    void mouseMove(sf::Vector2i mousePosition, bool & mouseSelection){

        sf::Vector2f newMousePosition = static_cast<sf::Vector2f>(mousePosition);
        unsigned int itemNr = 0;
     
        for(auto object : container){
            
            if(itemNr == containerPointer){
                break;
            }
            object->mouseMove(newMousePosition, mouseSelection);
            itemNr++;
        }
       
    }

    std::string exportString(){

        unsigned int itemNr = 0;
        std::string exportString;
        for(auto object : container){
            
            if(itemNr == containerPointer){
                break;
            }
            exportString += object->exportString();
            exportString += "\n";
            itemNr++;
        }
        return exportString += "0";
        
    }

};



class Game {

    std::ifstream file;
    sf::RenderWindow & window;
    ObjectContainer container;
    bool mouseSelection = false;
    std::string fileLocation = "sav.dat";

        
    action actions[1] = {
		action( sf::Mouse::Left, [&](){ container.mouseMove(sf::Mouse::getPosition( window ), mouseSelection); })

	};

public:
    Game(sf::RenderWindow & window):
        window(window)
    {
        load();
    }


    void load() {
        try {
            
            file.open(fileLocation);

            if(!(file.is_open())){
                throw(fileLocation);
            }

            std::string type;
            std::string end;
            sf::Vector2f size;
            std::string name = "";
            sf::Vector2f position;
            sf::Color color = sf::Color::White;
            std::string appearance;
            file >> end; 
            while (end == "1"){
                
                file >> position >> size >> type >> name >> appearance;
                file >> end; 
                container.addObject(type, size, position, name, appearance);

            }
        }
        catch(std::string fileLocation){
            std::cerr << "unable to open file: \"" << fileLocation << "\"\nObject loading failed";
        }
    

    }

    void save(){

        try { 
            std::ofstream file;

            file.open(fileLocation);

            if(!file.is_open()){
                throw(fileLocation);
            } 
            
            file << container.exportString();
            
            file.close();
        }
        catch (std::string fileLocation){
            std::cerr << "unable to save to file: \"" << fileLocation << "\"\nObject saving failed";

        }
        
    }

    void main(){
        
        for (auto action : actions){
            action();
        }
        if (!(sf::Mouse::Left)){
            mouseSelection = false;
            container.deselect();

        } 
        update();
        draw();
    }


    void update(){
        container.update();
    }

    void draw(){
        window.clear();
        container.draw(window);
        window.display();
    }






};



#endif
